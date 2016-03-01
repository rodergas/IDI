# version 330 core

in vec3 vertex;
in vec3 normal;
uniform vec3 posFocus;
uniform vec3 colFocus;
uniform vec3 llumAmbient;
in vec3 matamb;
in vec3 matdiff;
in vec3 matspec;
in float matshin;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 TG;

out vec4 vertex2;
out vec3 normal2;
out vec3 matambF;
out vec3 matdiffF;
out vec3 matspecF;
out float matshinF;
out vec3 llumAmbientF;
out vec3 posFocusF;
out vec3 colFocusF;
out vec3 llumF;


// Valors per als components que necessitem dels focus de llum



out vec3 fcolor;


void main()
{	
    //fcolor = matdiff;
	matambF = matamb;
	matdiffF = matdiff;
	matspecF = matspec;
	matshinF = matshin;
	posFocusF = posFocus;
	colFocusF =colFocus;
	llumAmbientF =llumAmbient;
	
	
	
	mat3 tsco = mat3(view*TG);
	mat3 NormalMatrix = inverse(transpose(tsco));
	vec3 normal2 = normalize(NormalMatrix*normal);
	vec4 vertex2 = normalize(vec4(tsco*vertex, 1.0));
	vec3 llum = normalize(posFocus.xyz-vertex2.xyz);
	//fcolor = Lambert(normal2, llum);
	llumF = llum;
	//fcolor = Phong(normal2, posFocus, vertex2);
    gl_Position = proj * view * TG * vec4 (vertex, 1.0);
}

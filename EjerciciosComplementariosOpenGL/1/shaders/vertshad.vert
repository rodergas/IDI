# version 330 core

in vec3 vertex;
in vec3 normal;

in vec3 matamb;
in vec3 matdiff;
in vec3 matspec;
in float matshin;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 TG;

// Valors per als components que necessitem dels focus de llum
vec3 colFocus = vec3(0, 1, 1);
vec3 llumAmbient = vec3(0.2, 0.2, 0.2);
vec3 posFocus = vec3(1, 1, 1);  // en SCA pero suponemos en SCO

out vec3 fcolor;

///////////////////COLORS////////////////////
// R G B //                // C M A //
// 1 0 0 // Vermell        // 0 1 1 // Cyan
// 0 1 0 // Verd           // 1 0 1 // Magenta
// 0 0 1 // Blau           // 1 1 0 // Groc
///////////////////FOCUS/////////////////////
// Escena --> View*Posicio (SCA)//
// Camera --> res (SCO)//
// Model  --> View*TG*Posicio (SCM)//
/////////////////////////////////////////////

vec3 Lambert (vec3 NormSCO, vec3 L) 
{
    // S'assumeix que els vectors que es reben com a paràmetres estan normalitzats

    // Inicialitzem color a component ambient
    vec3 colRes = llumAmbient * matamb;

    // Afegim component difusa, si n'hi ha
    if (dot (L, NormSCO) > 0)
      colRes = colRes + colFocus * matdiff * dot (L, NormSCO);
    return (colRes);
}

vec3 Phong (vec3 NormSCO, vec3 L, vec4 vertSCO) 
{
    // Els vectors estan normalitzats

    // Inicialitzem color a Lambert
    vec3 colRes = Lambert (NormSCO, L);

    // Calculem R i V
    if (dot(NormSCO,L) < 0)
      return colRes;  // no hi ha component especular

    vec3 R = reflect(-L, NormSCO); // equival a: normalize (2.0*dot(NormSCO,L)*NormSCO - L);
    vec3 V = normalize(-vertSCO.xyz);

    if ((dot(R, V) < 0) || (matshin == 0))
      return colRes;  // no hi ha component especular
    
    // Afegim la component especular
    float shine = pow(max(0.0, dot(R, V)), matshin);
    return (colRes + matspec * colFocus * shine); 
}

void main()
{	
    //fcolor = matdiff;
    mat3 tsco = mat3(view*TG);
    mat3 NormalMatrix = inverse(transpose(tsco));
    vec3 normal2 = normalize(NormalMatrix*normal);
    
    vec4 vertex2 = normalize(vec4(tsco*vertex, 1.0));
    //vec4 posFocusOBS = normalize(vec4(view*posFocus, 1.0));
    
    vec3 llum = normalize(posFocus.xyz-vertex2.xyz);
    
    fcolor = Phong(normal2, llum, vertex2);
    gl_Position = proj * view * TG * vec4 (vertex, 1.0);
}

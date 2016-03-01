#version 330 core

in vec3 fcolor;
uniform int franja;
out vec4 FragColor;

void main(){

	int r = int(gl_FragCoord.y * 0.1);
	if(franja == 1){
	  if(r % 2 == 0){
	    FragColor = vec4(1.,1.,1.,1.);
	  }
	  else{
	  FragColor = vec4(0.,0.,0.,1.);
	  }
  }else{
  FragColor = vec4(fcolor,1);
  }
}

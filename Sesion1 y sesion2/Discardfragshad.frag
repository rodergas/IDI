#version 330 core
out vec4 FragColor;

void main(){
  FragColor = vec4(1.);
  int r = int(gl_FragCoord.y * 0.1 / 2); 
  if((r %2) == 0) discard;
  else{
    if(gl_FragCoord.x < 400 && gl_FragCoord.y >= 400)
      FragColor = vec4(1.,0.,0.,1.);
    else if(gl_FragCoord.x >= 400 && gl_FragCoord.y >= 400)
      FragColor = vec4(0.,0.,1.,1.);
    else if(gl_FragCoord.x >= 400 && gl_FragCoord.y < 400)
      FragColor = vec4(0.,1.,0.,1.);
    else if(gl_FragCoord.x < 400 && gl_FragCoord.y < 400)
      FragColor = vec4(1.,1.,0.,1.);
  }
}



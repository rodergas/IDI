#include <GL/glew.h>
#include "MyGLWidget.h"

#include <iostream>

MyGLWidget::MyGLWidget (QGLFormat &f, QWidget* parent) : QGLWidget(f, parent)
{
  setFocusPolicy(Qt::ClickFocus);  // per rebre events de teclat
  xClick = yClick = 0;
  angleY = 0.0;
  DoingInteractive = NONE;
  radiEsc = sqrt(3);
  vrp = glm::vec3(0,0,0);
  FOV = M_PI/3;
  FOVIni = M_PI/6;
}

void MyGLWidget::initializeGL ()
{
  // glew és necessari per cridar funcions de les darreres versions d'OpenGL
  glewExperimental = GL_TRUE;
  glewInit(); 
  glGetError();  // Reinicia la variable d'error d'OpenGL

  glClearColor (0.5, 0.7, 1.0, 1.0);  // defineix color de fons (d'esborrat)
  glEnable(GL_DEPTH_TEST);
  carregaShaders ();
  createBuffers ();
  projectTransform ();
  viewTransform ();
  rotar = 0.0f;
    posF = glm::vec3(1,0,0);
  mourePat = glm::vec3(0,0,0);
}

void MyGLWidget::paintGL ()
{
  // Esborrem el frame-buffer i el depth-buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Activem el VAO per a pintar el terra 
  glBindVertexArray (VAO_Terra);

  modelTransformTerra ();

  // pintem
  glDrawArrays(GL_TRIANGLES, 0, 12);

  // Activem el VAO per a pintar el Patricio
  glBindVertexArray (VAO_Patr);

 modelTransformPatricio ();

  // Pintem l'escena
  glDrawArrays(GL_TRIANGLES, 0, patr.faces().size()*3);

  //modelTransformPatricio2();
  // Pintem l'escena
  //glDrawArrays(GL_TRIANGLES, 0, patr.faces().size()*3);

  
  glBindVertexArray(0);
  glBindVertexArray (VAO_cow);
  glUniform1i(cowLoc, 1);
  modelTransformCow();
  // Pintem l'escena
  glDrawArrays(GL_TRIANGLES, 0, cow.faces().size()*3);
  glUniform1i(cowLoc, 0);
  glBindVertexArray(0);
}

void MyGLWidget::resizeGL (int w, int h)
{
  glViewport (0, 0, w, h);
    projectTransform();
}

void MyGLWidget::createBuffers ()
{
  // Carreguem el model de l'OBJ - Atenció! Abans de crear els buffers!
  //patr.load("/assig/idi/models/Patricio.obj");
  patr.load("./models/Patricio.obj");

  // Calculem la capsa contenidora del model
  calculaCapsaModel ();
  
  // Creació del Vertex Array Object del Patricio
  glGenVertexArrays(1, &VAO_Patr);
  glBindVertexArray(VAO_Patr);

  // Creació dels buffers del model patr
  // Buffer de posicions
  glGenBuffers(1, &VBO_PatrPos);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_PatrPos);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*patr.faces().size()*3*3, patr.VBO_vertices(), GL_STATIC_DRAW);

  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  // Buffer de normals
  glGenBuffers(1, &VBO_PatrNorm);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_PatrNorm);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*patr.faces().size()*3*3, patr.VBO_normals(), GL_STATIC_DRAW);

  glVertexAttribPointer(normalLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(normalLoc);

  // En lloc del color, ara passem tots els paràmetres dels materials
  // Buffer de component ambient
  glGenBuffers(1, &VBO_PatrMatamb);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_PatrMatamb);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*patr.faces().size()*3*3, patr.VBO_matamb(), GL_STATIC_DRAW);

  glVertexAttribPointer(matambLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matambLoc);

  // Buffer de component difusa
  glGenBuffers(1, &VBO_PatrMatdiff);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_PatrMatdiff);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*patr.faces().size()*3*3, patr.VBO_matdiff(), GL_STATIC_DRAW);

  glVertexAttribPointer(matdiffLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matdiffLoc);

  // Buffer de component especular
  glGenBuffers(1, &VBO_PatrMatspec);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_PatrMatspec);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*patr.faces().size()*3*3, patr.VBO_matspec(), GL_STATIC_DRAW);

  glVertexAttribPointer(matspecLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matspecLoc);

  // Buffer de component shininness
  glGenBuffers(1, &VBO_PatrMatshin);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_PatrMatshin);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*patr.faces().size()*3, patr.VBO_matshin(), GL_STATIC_DRAW);

  glVertexAttribPointer(matshinLoc, 1, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matshinLoc);

  //Dades cow

  cow.load("./models/cow.obj");

  // Calculem la capsa contenidora del model
  calculaCapsaModelCow();

  // Creació del Vertex Array Object del Patricio
  glGenVertexArrays(1, &VAO_cow);
  glBindVertexArray(VAO_cow);

  // Creació dels buffers del model patr
  // Buffer de posicions
  glGenBuffers(1, &VBO_cowPos);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_cowPos);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*cow.faces().size()*3*3, cow.VBO_vertices(), GL_STATIC_DRAW);

  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  // Buffer de normals
  glGenBuffers(1, &VBO_cowNorm);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_cowNorm);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*cow.faces().size()*3*3, cow.VBO_normals(), GL_STATIC_DRAW);

  glVertexAttribPointer(normalLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(normalLoc);

  // En lloc del color, ara passem tots els paràmetres dels materials
  // Buffer de component ambient
  glGenBuffers(1, &VBO_cowMatamb);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_cowMatamb);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*cow.faces().size()*3*3, cow.VBO_matamb(), GL_STATIC_DRAW);

  glVertexAttribPointer(matambLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matambLoc);

  // Buffer de component difusa
  glGenBuffers(1, &VBO_cowMatdiff);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_cowMatdiff);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*cow.faces().size()*3*3, cow.VBO_matdiff(), GL_STATIC_DRAW);

  glVertexAttribPointer(matdiffLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matdiffLoc);

  // Buffer de component especular
  glGenBuffers(1, &VBO_cowMatspec);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_cowMatspec);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*cow.faces().size()*3*3, cow.VBO_matspec(), GL_STATIC_DRAW);

  glVertexAttribPointer(matspecLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matspecLoc);

  // Buffer de component shininness
  glGenBuffers(1, &VBO_cowMatshin);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_cowMatshin);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*cow.faces().size()*3, cow.VBO_matshin(), GL_STATIC_DRAW);

  glVertexAttribPointer(matshinLoc, 1, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matshinLoc);

  // Dades del terra
  // VBO amb la posició dels vèrtexs
  glm::vec3 posterra[12] = {
	glm::vec3(-1.0, -1.0, 1.0),
	glm::vec3(1.0, -1.0, 1.0),
	glm::vec3(-1.0, -1.0, -1.0),
	glm::vec3(-1.0, -1.0, -1.0),
	glm::vec3(1.0, -1.0, 1.0),
	glm::vec3(1.0, -1.0, -1.0),
	glm::vec3(-1.0, -1.0, -1.0),
	glm::vec3(1.0, -1.0, -1.0),
	glm::vec3(-1.0, 1.0, -1.0),
	glm::vec3(-1.0, 1.0, -1.0),
	glm::vec3(1.0, -1.0, -1.0),
	glm::vec3(1.0, 1.0, -1.0)
  }; 

  // VBO amb la normal de cada vèrtex
  glm::vec3 norm1 (0,1,0);
  glm::vec3 norm2 (0,0,1);
  glm::vec3 normterra[12] = {
	norm1, norm1, norm1, norm1, norm1, norm1, // la normal (0,1,0) per als primers dos triangles
	norm2, norm2, norm2, norm2, norm2, norm2  // la normal (0,0,1) per als dos últims triangles
  };

  // Definim el material del terra
  glm::vec3 amb(0.2,0,0.2);
  glm::vec3 diff(0.8,0,0.8);
  glm::vec3 spec(0,0,0);
  float shin = 100;

  // Fem que aquest material afecti a tots els vèrtexs per igual
  glm::vec3 matambterra[12] = {
	amb, amb, amb, amb, amb, amb, amb, amb, amb, amb, amb, amb
  };
  glm::vec3 matdiffterra[12] = {
	diff, diff, diff, diff, diff, diff, diff, diff, diff, diff, diff, diff
  };
  glm::vec3 matspecterra[12] = {
	spec, spec, spec, spec, spec, spec, spec, spec, spec, spec, spec, spec
  };
  float matshinterra[12] = {
	shin, shin, shin, shin, shin, shin, shin, shin, shin, shin, shin, shin
  };

// Creació del Vertex Array Object del terra
  glGenVertexArrays(1, &VAO_Terra);
  glBindVertexArray(VAO_Terra);

  glGenBuffers(1, &VBO_TerraPos);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraPos);
  glBufferData(GL_ARRAY_BUFFER, sizeof(posterra), posterra, GL_STATIC_DRAW);

  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  glGenBuffers(1, &VBO_TerraNorm);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraNorm);
  glBufferData(GL_ARRAY_BUFFER, sizeof(normterra), normterra, GL_STATIC_DRAW);

  // Activem l'atribut normalLoc
  glVertexAttribPointer(normalLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(normalLoc);

  // En lloc del color, ara passem tots els paràmetres dels materials
  // Buffer de component ambient
  glGenBuffers(1, &VBO_TerraMatamb);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraMatamb);
  glBufferData(GL_ARRAY_BUFFER, sizeof(matambterra), matambterra, GL_STATIC_DRAW);

  glVertexAttribPointer(matambLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matambLoc);

  // Buffer de component difusa
  glGenBuffers(1, &VBO_TerraMatdiff);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraMatdiff);
  glBufferData(GL_ARRAY_BUFFER, sizeof(matdiffterra), matdiffterra, GL_STATIC_DRAW);

  glVertexAttribPointer(matdiffLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matdiffLoc);

  // Buffer de component especular
  glGenBuffers(1, &VBO_TerraMatspec);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraMatspec);
  glBufferData(GL_ARRAY_BUFFER, sizeof(matspecterra), matspecterra, GL_STATIC_DRAW);

  glVertexAttribPointer(matspecLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matspecLoc);

  // Buffer de component shininness
  glGenBuffers(1, &VBO_TerraMatshin);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraMatshin);
  glBufferData(GL_ARRAY_BUFFER, sizeof(matshinterra), matshinterra, GL_STATIC_DRAW);

  glVertexAttribPointer(matshinLoc, 1, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matshinLoc);

  glBindVertexArray(0);
  anglePat = M_PI;
}

void MyGLWidget::carregaShaders ()
{
  // Creem els shaders per al fragment i vertex shader
  QGLShader fs(QGLShader::Fragment, this);
  QGLShader vs(QGLShader::Vertex, this);
  // Carreguem el codi dels fitxers i els compilem 
  fs.compileSourceFile("./shaders/fragshad.frag");
  vs.compileSourceFile("./shaders/vertshad.vert");

  // Creem el program
  program = new QGLShaderProgram(this);
  // Li afegim els shaders corresponents
  program->addShader(&fs);
  program->addShader(&vs);

  // Linkem el program
  program->link();

  // Indiquem que aquest és el program que volem usar
  program->bind();

  // Obtenim identificador per a l'atribut “vertex” del vertex shader
  vertexLoc = glGetAttribLocation (program->programId(), "vertex");
  // Obtenim identificador per a l'atribut “normal” del vertex shader
  normalLoc = glGetAttribLocation (program->programId(), "normal");
  // Obtenim identificador per a l'atribut “matamb” del vertex shader
  matambLoc = glGetAttribLocation (program->programId(), "matamb");
  // Obtenim identificador per a l'atribut “matdiff” del vertex shader
  matdiffLoc = glGetAttribLocation (program->programId(), "matdiff");
  // Obtenim identificador per a l'atribut “matspec” del vertex shader
  matspecLoc = glGetAttribLocation (program->programId(), "matspec");
  // Obtenim identificador per a l'atribut “matshin” del vertex shader
  matshinLoc = glGetAttribLocation (program->programId(), "matshin");

  // Demanem identificadors per als uniforms del vertex shader
  transLoc = glGetUniformLocation (program->programId(), "TG");
  projLoc = glGetUniformLocation (program->programId(), "proj");
  viewLoc = glGetUniformLocation (program->programId(), "view");
  
  
  posFocusLoc = glGetUniformLocation (program->programId(), "posFocus");
  
  cowLoc = glGetUniformLocation (program->programId(), "cow");

}

void MyGLWidget::modelTransformPatricio ()
{
  glm::mat4 TG;  // Matriu de transformació
  TG = glm::translate(glm::mat4(1.f), glm::vec3(1 + vrp[0]+ mourePat[0],-0.5,0+ mourePat[2]));
  TG = glm::rotate(TG, rotar, glm::vec3(0,1,0));
  TG = glm::scale(TG, glm::vec3(escala, escala, escala));
  TG = glm::translate(TG, -centreBasePatr);

  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::modelTransformPatricio2()
{
  glm::mat4 TG;  // Matriu de transformació
  TG = glm::translate(glm::mat4(1.f), glm::vec3(0,2,0)); //factor escala 2/respecto la altura, la altura valdra 2
  TG = glm::rotate(TG, -anglePat, glm::vec3(0,0,1));
  TG = glm::scale(TG, glm::vec3(escala, escala, escala));
  TG = glm::translate(TG, -centrePatr);

  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::modelTransformCow()
{
  glm::mat4 TG;  // Matriu de transformació
  //TG = glm::scale(TG, glm::vec3(escala, escala, escala));
  TG = glm::translate(glm::mat4(1.f), glm::vec3(1,-1,0));
  //TG = glm::rotate(TG, (float)-M_PI/2.0f, glm::vec3(1.0,0.0,0.0));
  //TG = glm::rotate(TG, (float)-M_PI/2.0f, glm::vec3(0.0,0.0,1.0));
  TG = glm::rotate(TG, rotar, glm::vec3(0,1,0));
  TG = glm::rotate(TG, (float)-M_PI/2.0f, glm::vec3(0.0,1.0,0.0));
  TG = glm::rotate(TG, (float)-M_PI/2.0f, glm::vec3(1.0,0.0,0.0));
  TG = glm::scale(TG, glm::vec3(escalaCow, escalaCow, escalaCow));
  TG = glm::translate(TG, -centreBaseCow);

  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::modelTransformTerra ()
{
  glm::mat4 TG;  // Matriu de transformació
  TG = glm::mat4(1.f);
  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::projectTransform ()
{
  //sempre mantenim la aspect ratio de la pantalla per evitar deformacions
    //double ax = (2*radiEsc - 2)/2;
    //double FOV = atan((2+ax)/2*radiEsc)*2;
  glm::mat4 Proj;  // Matriu de projecció
  //Proj = glm::perspective(M_PI/3, 1.0, radiEsc/2, 3.*radiEsc);
  //Proj = glm::perspective(FOV, 1.0, radiEsc, 3.*radiEsc);
  //glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]);
  ra = double (width()) / double (height());
  if(ra > 1){
  glm::mat4 Proj = glm::perspective(FOV, ra, radiEsc/2, 3.*radiEsc);
  glUniformMatrix4fv(projLoc, 1,GL_FALSE, &Proj[0][0]);
  }else{
      FOV = 2*atan(tan(FOVIni)/ra);
      glm::mat4 Proj = glm::perspective(FOV, ra, radiEsc/2, 3.*radiEsc);
      glUniformMatrix4fv(projLoc, 1,GL_FALSE, &Proj[0][0]);
  }
}

void MyGLWidget::viewTransform ()
{
  glm::mat4 View;  // Matriu de posició i orientació
  //View = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, -2*radiEsc));


  View = glm::lookAt(glm::vec3(-1,1,-1),glm::vec3(1 + vrp[0],-(0.5-0.125),0),glm::vec3(0,1,0));
  View = glm::rotate(View, -angleY, glm::vec3(0, 1, 0));
  //View = glm::translate(View, glm::vec3(0, -1, 0));

  glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::calculaCapsaModel ()
{
  // Càlcul capsa contenidora i valors transformacions inicials
  float minx, miny, minz, maxx, maxy, maxz;
  minx = maxx = patr.vertices()[0];
  miny = maxy = patr.vertices()[1];
  minz = maxz = patr.vertices()[2];
  for (unsigned int i = 3; i < patr.vertices().size(); i+=3)
  {
    if (patr.vertices()[i+0] < minx)
      minx = patr.vertices()[i+0];
    if (patr.vertices()[i+0] > maxx)
      maxx = patr.vertices()[i+0];
    if (patr.vertices()[i+1] < miny)
      miny = patr.vertices()[i+1];
    if (patr.vertices()[i+1] > maxy)
      maxy = patr.vertices()[i+1];
    if (patr.vertices()[i+2] < minz)
      minz = patr.vertices()[i+2];
    if (patr.vertices()[i+2] > maxz)
      maxz = patr.vertices()[i+2];
  }
  escala = 0.25/(maxy-miny);
  centrePatr[0] = (minx+maxx)/2.0; centrePatr[1] = (miny+maxy)/2.0; centrePatr[2] = (minz+maxz)/2.0;
  centreBasePatr[0] = (minx+maxx)/2.0; centreBasePatr[1] = miny; centreBasePatr[2] = (minz+maxz)/2.0;
}

void MyGLWidget::calculaCapsaModelCow()
{
  // Càlcul capsa contenidora i valors transformacions inicials
  float minx, miny, minz, maxx, maxy, maxz;
  minx = maxx = cow.vertices()[0];
  miny = maxy = cow.vertices()[1];
  minz = maxz = cow.vertices()[2];
  for (unsigned int i = 3; i < cow.vertices().size(); i+=3)
  {
    if (cow.vertices()[i+0] < minx)
      minx = cow.vertices()[i+0];
    if (cow.vertices()[i+0] > maxx)
      maxx = cow.vertices()[i+0];
    if (cow.vertices()[i+1] < miny)
      miny = cow.vertices()[i+1];
    if (cow.vertices()[i+1] > maxy)
      maxy = cow.vertices()[i+1];
    if (cow.vertices()[i+2] < minz)
      minz = cow.vertices()[i+2];
    if (cow.vertices()[i+2] > maxz)
      maxz = cow.vertices()[i+2];
  }
  escalaCow = 0.5/(maxy-miny);
  centreCow[0] = (minx+maxx)/2.0; centreCow[1] = (miny+maxy)/2.0; centreCow[2] = (minz+maxz)/2.0;
  centreBaseCow[0] = (minx+maxx)/2.0; centreBaseCow[1] = miny; centreBaseCow[2] = (minz+maxz)/2.0;
}

void MyGLWidget::keyPressEvent (QKeyEvent *e)
{
  switch (e->key())
  {
    case Qt::Key_R : {
        rotar += M_PI/6.0;
        modelTransformPatricio();
        modelTransformCow();
        updateGL();
        break;
    }
      case Qt::Key_K : {
          vrp[0] -= 0.2;
          modelTransformPatricio();
          viewTransform();
          updateGL();
          break;
      }
      case Qt::Key_L : {
          vrp[0] += 0.2;
          modelTransformPatricio();
          viewTransform();
          updateGL();
          break;
      }
            case Qt::Key_Up: {
          posF[2] -= 0.1;
          mourePat[2] -= 0.1;
          modelTransformPatricio();
          llum();
          break;
      }
      case Qt::Key_Down: {
          posF[2] += 0.1;
          mourePat[2] += 0.1;
          modelTransformPatricio();
          llum();
          break;
      }
      case Qt::Key_Left: {
          posF[0] -= 0.1;
          mourePat[0] -= 0.1;
          modelTransformPatricio();
          llum();
          break;
      }
      case Qt::Key_Right: {
          posF[0] += 0.1;
          mourePat[0] += 0.1;
          modelTransformPatricio();
          llum();
          break;
      }
    case Qt::Key_Escape:
        exit(0);

    default: e->ignore(); break;
  }
  updateGL();
}

void MyGLWidget::mousePressEvent (QMouseEvent *e)
{
  xClick = e->x();
  yClick = e->y();

  if (e->button() & Qt::LeftButton &&
      ! (e->modifiers() & (Qt::ShiftModifier|Qt::AltModifier|Qt::ControlModifier)))
  {
    DoingInteractive = ROTATE;
  }
}

void MyGLWidget::mouseReleaseEvent( QMouseEvent *)
{
  DoingInteractive = NONE;
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *e)
{
  // Aqui cal que es calculi i s'apliqui la rotacio o el zoom com s'escaigui...
  if (DoingInteractive == ROTATE)
  {
    // Fem la rotació
    angleY += (e->x() - xClick) * M_PI / 180.0;
    viewTransform ();
  }

  xClick = e->x();
  yClick = e->y();

  updateGL ();
}
void MyGLWidget::llum()
{
glUniform3f(posFocusLoc, posF[0], posF[1], posF[2]);
}

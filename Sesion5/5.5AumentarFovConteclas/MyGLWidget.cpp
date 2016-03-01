#include <GL/glew.h>
#include "MyGLWidget.h"

#include <iostream>

MyGLWidget::MyGLWidget (QGLFormat &f, QWidget* parent) : QGLWidget(f, parent)
{
  setFocusPolicy(Qt::ClickFocus); // per rebre events de teclat
  scale = 1.0f;
}

void MyGLWidget::initializeGL ()
{

  FOV = M_PI/2; // NEW 5.1
  FOVIni = M_PI/4; // NEW 5.1

  // glew és necessari per cridar funcions de les darreres versions d'OpenGL
  glewExperimental = GL_TRUE;
  glewInit();
  glGetError();  // Reinicia la variable d'error d'OpenGL

  glEnable(GL_DEPTH_TEST);

  glClearColor(0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
  carregaShaders();
  m.load("../models/Patricio.obj");
  calculaCapsaModel();
  createBuffers();
  //modelTransform ();
  projectTransform();
  viewTransform();
}

/*void MyGLWidget::paintGL ()
{
  // Esborrem el frame-buffer
  glClear (GL_COLOR_BUFFER_BIT);

  // Activem el VAO per a pintar el terra
  glBindVertexArray (VAO_Terra);

  // pintem
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  // Activem el VAO per a pintar la caseta
  glBindVertexArray (VAO_Casa);

  // pintem
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 5);

  glBindVertexArray (0);
}*/

void MyGLWidget::paintGL ()
{

  glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


  //glBindVertexArray (VAO_Casa);
  //glDrawArrays(GL_TRIANGLE_STRIP, 0, 5);

  modelTransform();

  glBindVertexArray(VAO_Homer);
  glDrawArrays(GL_TRIANGLES, 0, m.faces().size()*3);
/*
  modelTransformTierra(); // Antes de pintar el suelo
                          // Sin esta llamada, te rota tmb el suelo

  glBindVertexArray (VAO_Terra);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
*/
  glBindVertexArray (0);

}

void MyGLWidget::modelTransform ()
{
  glm::mat4 TG;  // Matriu de transformació
  TG = glm::translate(TG, -centrePatr);
  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::modelTransformTierra ()
{
  // Matriu de transformació de model
  glm::mat4 transform = glm::scale(glm::mat4(1.0f), glm::vec3(scale));
  transform = glm::rotate(transform, 0.0f, glm::vec3(0.,1.,0.));
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::resizeGL (int w, int h)
{
  glViewport(0, 0, w, h);
  projectTransform();
}

void MyGLWidget::keyPressEvent(QKeyEvent* event)
{
  switch (event->key()) {
    case Qt::Key_Escape:
      exit(0);
    case Qt::Key_S: { // escalar a més gran
      scale += 0.05;
      modelTransform ();
      updateGL();
      break;
    }
    case Qt::Key_D: { // escalar a més petit
      scale -= 0.05;
      modelTransform ();
      updateGL();
      break;
    }
    case Qt::Key_R: {
      rotHom += M_PI/4.0;
      modelTransform ();
      updateGL();
      break;
    }
    case Qt::Key_Z: {
        FOV -= 0.02;
        projectTransform ();
        updateGL();
        break;
    }
    case Qt::Key_X: {
        FOV += 0.02;
        projectTransform ();
        updateGL();
        break;
    }
    default: event->ignore(); break;
  }
}

void MyGLWidget::createBuffers ()
{
  // Dades de la caseta
  // Dos VBOs, un amb posició i l'altre amb color

  /* COMENTADO PARA EL 4

  glm::vec3 posicio[5] = {
    glm::vec3(-0.5, -1.0, 0.0),
    glm::vec3( 0.5, -1.0, 0.0),
    glm::vec3(-0.5,  0.0, 0.0),
    glm::vec3( 0.5,  0.0, 0.0),
    glm::vec3( 0.0,  0.6, 0.0)
  };
  glm::vec3 color[5] = {
    glm::http://www.fib.upc.edu/fib.htmlvec3(1,0,0),
    glm::vec3(0,1,0),
    glm::vec3(0,0,1),
    glm::vec3(1,0,0),
    glm::vec3(0,1,0)
  };

  // Creació del Vertex Array Object per pintar
  glGenVertexArrays(1, &VAO_Casa);
  glBindVertexArray(VAO_Casa);

  glGenBuffers(1, &VBO_CasaPos);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_CasaPos);
  glBufferData(GL_ARRAY_BUFFER, sizeof(posicio), posicio, GL_STATIC_DRAW);

  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  glGenBuffers(1, &VBO_CasaCol);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_CasaCol);
  glBufferData(GL_ARRAY_BUFFER, sizeof(color), color, GL_STATIC_DRAW);

  // Activem l'atribut colorLoc
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);

  */ //COMENTADO PARA EL 4

  glGenVertexArrays(1, &VAO_Homer);
  glBindVertexArray(VAO_Homer);

  glGenBuffers(1, &VBO_posicio);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_posicio);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*m.faces().size()*3*3, m.VBO_vertices(), GL_STATIC_DRAW);

   // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  glGenBuffers(1, &VBO_colors);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_colors);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*m.faces().size()*3*3, m.VBO_matdiff(), GL_STATIC_DRAW);

   // Activem l'atribut colorLoc
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);

  // Dades del terra
  // Dos VBOs, un amb posició i l'altre amb color
  glm::vec3 posterra[4] = {
    glm::vec3(-1.0, -1.0, -1.0),
    glm::vec3(-1.0, -1.0, 1.0),
    glm::vec3(1.0, -1.0, -1.0),
    glm::vec3(1.0, -1.0, 1.0)
  };
  glm::vec3 colterra[4] = {
    glm::vec3(1,0,1),
    glm::vec3(1,0,1),
    glm::vec3(1,0,1),
    glm::vec3(1,0,1)
  };

  // Creació del Vertex Array Object per pintar
  glGenVertexArrays(1, &VAO_Terra);
  glBindVertexArray(VAO_Terra);

  glGenBuffers(1, &VBO_TerraPos);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraPos);
  glBufferData(GL_ARRAY_BUFFER, sizeof(posterra), posterra, GL_STATIC_DRAW);

  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  glGenBuffers(1, &VBO_TerraCol);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraCol);
  glBufferData(GL_ARRAY_BUFFER, sizeof(colterra), colterra, GL_STATIC_DRAW);

  // Activem l'atribut colorLoc
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);

  rotHom = 0.0;
  first = true;
  ax = 0;
  ay = 0;
  glBindVertexArray (0);
}

void MyGLWidget::carregaShaders()
{
  // Creem els shaders per al fragment shader i el vertex shader
  QGLShader fs (QGLShader::Fragment, this);
  QGLShader vs (QGLShader::Vertex, this);
  // Carreguem el codi dels fitxers i els compilem
  fs.compileSourceFile("shaders/fragshad.frag");
  vs.compileSourceFile("shaders/vertshad.vert");
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
  // Obtenim identificador per a l'atribut “color” del vertex shader
  colorLoc = glGetAttribLocation (program->programId(), "color");
  // Uniform locations
  transLoc = glGetUniformLocation(program->programId(), "TG");

  projLoc = glGetUniformLocation(program->programId(), "proj");

  viewLoc = glGetUniformLocation(program->programId(), "view");
}

void MyGLWidget::projectTransform()
{

  ra = double (width())/double (height());
  if (ra > 1) {
    glm::mat4 Proj = glm::perspective(FOV, ra, double(d - r), double(d + r));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, &Proj[0][0]);
  }
  else {
    //FOV = 2*atan(tan(FOVIni)/ra); // per evitar retallament
    glm::mat4 Proj = glm::perspective(FOV, ra, double(d - r), double(d + r));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, &Proj[0][0]);

  }
  // glm::perspective (FOV en radians, ra window, znear, zfar)


}

void MyGLWidget::viewTransform()
{
 //glm::mat4 View = glm::lookAt(glm::vec3(0,0, d),glm::vec3(0,0,0),glm::vec3(0,1,0));
    glm::vec3 VRP = glm::vec3(0,0,0);
    glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0,0,-d));
    View = glm::rotate(View, -0.0f, glm::vec3(0.,0.,1.));// φ
    View = glm::rotate(View, ay, glm::vec3(1.,0.,0.));// θ
    View = glm::rotate(View, -ax, glm::vec3(0.,1.,0.));// ψ
    View = glm::translate(View, glm::vec3(-VRP.x,-VRP.y,-VRP.z));//VRP
  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &View[0][0]);


  // glm::lookAt(OBS, VRP, UP)


}
void MyGLWidget::calculaCapsaModel()
{
  // Càlcul capsa contenidora i valors transformacions inicials
  //float minx, miny, minz, maxx, maxy, maxz;
  minx = maxx = m.vertices()[0];
  miny = maxy = m.vertices()[1];
  minz = maxz = m.vertices()[2];
  for (unsigned int i = 3; i < m.vertices().size(); i+=3)
  {
    if (m.vertices()[i+0] < minx)
      minx = m.vertices()[i+0];
    if (m.vertices()[i+0] > maxx)
      maxx = m.vertices()[i+0];
    if (m.vertices()[i+1] < miny)
      miny = m.vertices()[i+1];
    if (m.vertices()[i+1] > maxy)
      maxy = m.vertices()[i+1];
    if (m.vertices()[i+2] < minz)
      minz = m.vertices()[i+2];
    if (m.vertices()[i+2] > maxz)
      maxz = m.vertices()[i+2];
  }
  centrePatr[0] = (minx+maxx)/2.0; centrePatr[1] = (miny+maxy)/2.0; centrePatr[2] = (minz+maxz)/2.0;

  glm::vec3 ds = glm::vec3(maxx - minx, maxy -miny, maxz - minz);

  r = (sqrt(ds.x*ds.x +  ds.y*ds.y + ds.z*ds.z))/2.0;

  d = r/(sin(FOV/2.0));
}


//NUEVO

void MyGLWidget::mouseMoveEvent(QMouseEvent *e){
    if(first){
        oldPos = e->pos();
        first = false;
    }else{
        dx = e->pos().x() - oldPos.x();
        dy = e->pos().y() - oldPos.y();
        oldPos = e->pos();
        switch(e->buttons()){
            case Qt::LeftButton :
                if(dx > 0)ax += 0.02;
                else ax -= 0.02;
                if(dy < 0)ay += 0.02; //me muevo para arriba
                else ay -= 0.02;
                viewTransform();
                updateGL();
                break;
            default: e->ignore();
        }
    }
}


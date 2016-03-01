#include <GL/glew.h>
#include "MyGLWidget.h"

#include <iostream>

MyGLWidget::MyGLWidget (QGLFormat &f, QWidget* parent) : QGLWidget(f, parent)
{
  setFocusPolicy(Qt::ClickFocus);  // per rebre events de teclat
}

void MyGLWidget::initializeGL ()
{
  // glew és necessari per cridar funcions de les darreres versions d'OpenGL
  glewExperimental = GL_TRUE;
  glewInit(); 
  glGetError();  // Reinicia la variable d'error d'OpenGL

  glClearColor (0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)

  carregarShaders();
  createBuffers();
}

void MyGLWidget::paintGL ()
{
  glClear (GL_COLOR_BUFFER_BIT);  // Esborrem el frame-buffer

  // Activem l'Array a pintar 
  glBindVertexArray(VAO);
 
  // Pintem l'escena
  glDrawArrays(GL_TRIANGLES, 0, 3);
  
  // Desactivem el VAO
  glBindVertexArray(0);
}

void MyGLWidget::resizeGL (int w, int h)
{
  glViewport (0, 0, w, h);
}

void MyGLWidget::createBuffers ()
{
  glm::vec3 Vertices[3];  // Tres vèrtexs amb X, Y i Z
  Vertices[0] = glm::vec3(-1.0, -1.0, 0.0); // IZQ
  Vertices[1] = glm::vec3(1.0, -1.0, 0.0); // DER
  Vertices[2] = glm::vec3(0.0, 1.0, 0.0); // ARRIBA
  
  // Creació del Vertex Array Object (VAO) que usarem per pintar
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  // Creació del buffer amb les dades dels vèrtexs
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
  // Activem l'atribut que farem servir per vèrtex (només el 0 en aquest cas)	
  glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(pos);


  glm::vec3 Colores[3];  // Tres vèrtexs amb X, Y i Z
  Colores[0] = glm::vec3(1.0, 0.0, 0.0); // IZQ - ROJO
  Colores[1] = glm::vec3(0.0, 1.0, 0.0); // DER - VERDE
  Colores[2] = glm::vec3(0.0, 0.0, 1.0); // ARRIBA - AZUL

  // Creació del buffer amb les dades dels vèrtexs
  glGenBuffers(1, &VBO2);
  glBindBuffer(GL_ARRAY_BUFFER, VBO2);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Colores), Colores, GL_STATIC_DRAW);
  // Activem l'atribut que farem servir per vèrtex (només el 0 en aquest cas)	
  glVertexAttribPointer(pos2, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(pos2);

  //scl = 0.5;
  //glUniform1f (varloc, scl);

  vectorDeTrans = glm::vec3(0.0, 0.0, 0.0);
  vectorDeRota = glm::vec3(0.0, 0.0, 1.0);
  angulo = 0.0;
  vectorDeEscalado = glm::vec3(0.5, 0.5, 0.5);
  modelTransform();

  // Desactivem el VAO
  glBindVertexArray(0);
}

void MyGLWidget::carregarShaders()
{
  QGLShader fs (QGLShader::Fragment, this);
  QGLShader vs (QGLShader::Vertex, this);
  fs.compileSourceFile("./fragshad.frag");
  vs.compileSourceFile("./vertshad.vert");
  program = new QGLShaderProgram(this);
  program->addShader(&fs);
  program->addShader(&vs);
  program->link();
  program->bind();
  pos = glGetAttribLocation(program->programId(), "vertex");
  pos2 = glGetAttribLocation(program->programId(), "color");
  //varloc = glGetUniformLocation(program->programId(),"val");
  transloc = glGetUniformLocation(program->programId(), "TG");
}

void MyGLWidget::keyPressEvent (QKeyEvent *e) {

  if (e->key() == Qt::Key_Escape) exit(0);
  else if (e->key() == Qt::Key_S) {
    //scl += 0.1;
    //glUniform1f(varloc,scl);
    vectorDeEscalado[0] += 0.1;
    vectorDeEscalado[1] += 0.1;
    vectorDeEscalado[2] += 0.1;
    modelTransform();
    updateGL();
  }
  else if (e->key() == Qt::Key_D) {
    //scl -= 0.1;
    //glUniform1f(varloc,scl);
    vectorDeEscalado[0] -= 0.1;
    vectorDeEscalado[1] -= 0.1;
    vectorDeEscalado[2] -= 0.1;
    modelTransform();
    updateGL();
  }
  else if (e->key() == Qt::Key_Left) {
    vectorDeTrans[0] -= 0.1; // --tx
    angulo += 45.0;
    modelTransform();
    updateGL();
  }
  else if (e->key() == Qt::Key_Right) {
    vectorDeTrans[0] += 0.1; // ++tx
    angulo += 45.0;
    modelTransform();
    updateGL();
  }
  else if (e->key() == Qt::Key_Up) {
    vectorDeTrans[1] += 0.1; // ++ty
    angulo += 45.0;
    modelTransform();
    updateGL();
  }
  else if (e->key() == Qt::Key_Down) {
    vectorDeTrans[1] -= 0.1; // --ty
    angulo += 45.0;
    modelTransform();
    updateGL();   
  }
  else e->ignore();

}

void MyGLWidget::modelTransform() {

  glm::mat4 TG; // Matriu de transformacio

  TG = glm::translate (glm::mat4(1.0), vectorDeTrans);

  TG = glm::rotate (TG, angulo, vectorDeRota);

  TG = glm::scale (TG, vectorDeEscalado);

  glUniformMatrix4fv (transloc, 1, GL_FALSE, &TG[0][0]);

}

/* Afegeix a la transformacio geometrica dels vertexs un escalat uniforme amb 
  un factor d’escala variable mitjancant teclat (com abans amb ’s’ i ’d’) */

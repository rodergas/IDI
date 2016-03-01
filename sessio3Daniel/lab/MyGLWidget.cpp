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
  Vertices[0] = glm::vec3(-1.0, -1.0, 0.0);
  Vertices[1] = glm::vec3(1.0, -1.0, 0.0);
  Vertices[2] = glm::vec3(0.0, 1.0, 0.0);
  
  // Creació del Vertex Array Object (VAO) que usarem per pintar
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  // Creació del buffer amb les dades dels vèrtexs
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
  // Activem l'atribut que farem servir per vèrtex (només el 0 en aquest cas)	
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);

  scl = 0.5;
  glUniform1f (varloc, scl);

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
  varloc = glGetUniformLocation(program->programId(),"val");
}

void MyGLWidget::keyPressEvent (QKeyEvent *e) {

  if (e->key() == Qt::Key_Escape) exit(0);
  else if (e->key() == Qt::Key_S) {
    scl += 0.1;
    glUniform1f(varloc,scl);
    updateGL();
  }
  else if (e->key() == Qt::Key_D) {
    scl -= 0.1;
    glUniform1f(varloc,scl);
    updateGL();
  }
  else e->ignore();

}

/* Afegeix un uniform de tipus float al Vertex Shader que el faras servir per 
a multiplicar les coordenades del vertex i que inicialment tindra valor 0.5. 
Afegeix al teu programa la possibilitat de modificar aquest valor del uniform 
mitjancant les tecles ’s’ i ’d’ */

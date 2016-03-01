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

  carregaShaders();
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
  int posV = glGetAttribLocation(program->programId(), "vertex");
  glVertexAttribPointer(posV, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(posV);

  // Desactivem el VAO
  glBindVertexArray(0);

  glm::vec3 Colores[3]; // Colores para cada vertice
  Colores[0] = glm::vec3(1.0, 0.0, 0.0);
  Colores[1] = glm::vec3(0.0, 1.0, 0.0);
  Colores[2] = glm::vec3(0.0, 0.0, 1.0);
  glBindVertexArray(VAO);
  //Creació del buffer amb dades dels vèrtexs
  glGenBuffers(1, &VBO2);
  glBindBuffer(GL_ARRAY_BUFFER, VBO2);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Colores), Colores, GL_STATIC_DRAW);

  int posC = glGetAttribLocation(program->programId(), "color");
  glVertexAttribPointer(posC, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(posC);
  glBindVertexArray(0);

  //scl = 0.5;
  rot = 0.0;
  //glUniform1f(varLoc,scl);

  vTrans = glm::vec3(0.0,0.0,0.0);
  vRot = glm::vec3(0.0,0.0,1.0);
  vScale = glm::vec3(0.5,0.5,0.5);
  first = true;
  modelTransform();
}

void MyGLWidget::carregaShaders()
{
  QGLShader fs(QGLShader::Fragment, this);
  fs.compileSourceFile("./fragshad.frag");
  QGLShader vs(QGLShader::Vertex, this);
  vs.compileSourceFile("./vertshad.vert");
  program = new QGLShaderProgram(this);
  program->addShader(&fs);
  program->addShader(&vs);
  program->link();
  program->bind();
  varLoc = glGetUniformLocation(program->programId(),"val");
  transLoc = glGetUniformLocation(program->programId(),"TG");
}

void MyGLWidget::keyPressEvent(QKeyEvent * e){
    switch(e->key()){
        case Qt::Key_Escape :
            exit(0);
        case Qt::Key_S :
            //scl += 0.1;
            //glUniform1f(varLoc,scl);
            vScale[0] += 0.1;
            vScale[1] += 0.1;
            vScale[2] += 0.1;
            modelTransform();
            updateGL();
            break;
        case Qt::Key_D :
            //scl -= 0.1;
            //glUniform1f(varLoc,scl);
            vScale[0] -= 0.1;
            vScale[1] -= 0.1;
            vScale[2] -= 0.1;
            modelTransform();
            updateGL();
            break;
        case Qt::Key_Left :
            vTrans[0] = vTrans[0] - 0.1; //--x
            rot += M_PI/4;
            modelTransform();
            updateGL();
            break;
        case Qt::Key_Right :
            vTrans[0] = vTrans[0] + 0.1; //++x
            rot += M_PI/4;
            modelTransform();
            updateGL();
            break;
        case Qt::Key_Down :
            vTrans[1] = vTrans[1] - 0.1; //--y
            rot += M_PI/4;
            modelTransform();
            updateGL();
            break;
        case Qt::Key_Up :
            vTrans[1] = vTrans[1] + 0.1; //++y
            rot += M_PI/4;
            modelTransform();
            updateGL();
            break;
        default: e->ignore();
    }
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *e){
    if(first){
        oldPos = e->pos();
        first = false;
    }else{
        dx = e->x() - oldPos.x();
        dy = e->y() - oldPos.y();
        oldPos = e->pos();
        switch(e->buttons()){
            case Qt::LeftButton :
                if(dx < 0)vScale[0] -= 0.001;
                else vScale[0] += 0.001;
                if(dy < 0)vScale[1] += 0.001;
                else vScale[1] -= 0.001;
                modelTransform();
                updateGL();
                break;
            default: e->ignore();
        }
    }
}

void MyGLWidget::modelTransform(){
    glm::mat4 TG; //Mat transformacio

    TG = glm::translate(glm::mat4(1.0), vTrans);
    TG = glm::rotate(TG, rot, vRot);
    TG = glm::scale(TG, vScale);


    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);

}




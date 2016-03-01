#define GLM_FORCE_RADIANS
#include <QGLWidget>
#include <QGLShader>
#include <QGLShaderProgram>
#include <QKeyEvent>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "../Model/Model.h"

class MyGLWidget : public QGLWidget {
  Q_OBJECT

  public:
    MyGLWidget (QGLFormat &f, QWidget *parent=0);

  protected:
    // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    virtual void initializeGL ( );
    // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
    // Tot el que es dibuixa es dibuixa aqui.
    virtual void paintGL ( );
    // resizeGL - És cridat quan canvia la mida del widget
    virtual void resizeGL (int width, int height);
    // keyPressEvent - Es cridat quan es prem una tecla
    virtual void keyPressEvent (QKeyEvent *event);

  private:
    void createBuffers ();
    void carregaShaders ();
    void modelTransform ();
    void projectTransform(); // nuevo
    void viewTransform();
    void modelTransformTierra(); //nuevo

    // attribute locations
    GLuint vertexLoc, colorLoc;
    // uniform locations
    GLuint transLoc;
    GLuint projLoc;//nuevo
    GLuint viewLoc; // nuevo
    // VAO i VBO names
    GLuint VAO_Casa, VBO_CasaPos, VBO_CasaCol;
    GLuint VAO_Terra, VBO_TerraPos, VBO_TerraCol;
    GLuint VAO_Homer, VBO_posicio, VBO_colors; // nuevo
    // Program
    QGLShaderProgram *program;
    // Internal vars
    float scale;
    glm::vec3 pos;
    
    float rotHom;
    
    Model m; //new
};


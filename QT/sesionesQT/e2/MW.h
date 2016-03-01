//Incluir la clase que heredamos
#include <QWidget>

//Nombre de la clase nuestra: clase que heredamos
class MW: public QWidget
{
  Q_OBJECT
  public:
        int R,G,B;
        MW(QWidget *parent);
  public slots:
        void RC(int);
        void GC(int);
        void BC(int);
        void SET();
};

	

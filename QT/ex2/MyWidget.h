//Incluir la clase que heredamos
#include <QWidget>

//Nombre de la clase nuestra: clase que heredamos
class MyWidget: public QWidget
{
  Q_OBJECT
  public:
        MyWidget(QWidget *parent);
  public slots:

	void Color(int, int, int);
};

	

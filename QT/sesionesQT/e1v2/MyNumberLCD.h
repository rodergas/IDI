//Incluir la clase que heredamos
#include <QLCDNumber>

//Nombre de la clase nuestra: clase que heredamos
class MyNumberLCD: public QLCDNumber
{
  Q_OBJECT
  public:
       MyNumberLCD(QWidget *parent);
  public slots:

	void Zero();

       // void ColorOnChange(int);

	void display(int);
};

	

#include <QLCDNumber>
class MyNumberLCD: public QLCDNumber
{
  Q_OBJECT
  public:
        MyNumberLCD(QWidget *parent);
  public slots:

	void Zero();

        void ColorOnChange(int);
};

	

#include <QLCDNumber>
class MyLCD: public QLCDNumber
{
  Q_OBJECT
  public:
  	MyLCD(QWidget *parent);
	int numLCD;
  public slots:
  void fallos(QString s);
  void resetLCD();
};

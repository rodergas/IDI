#include <QLCDNumber>
class MyLCD: public QLCDNumber
{
  Q_OBJECT
  public:
  	MyLCD(QWidget *parent);
  public slots:

  void Base3(int n);
  void Zero();

};

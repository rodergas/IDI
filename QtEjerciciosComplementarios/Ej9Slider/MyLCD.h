#include <QLCDNumber>
class MyLCD: public QLCDNumber
{
  Q_OBJECT
  public:
  	MyLCD(QWidget *parent);
	int numAgafat;
	int numLCD;
	int numUndo;
  public slots:

  void agafarNum(int);
  void Suma();
  void Restar();
  void Undo();
  void Reset();
};

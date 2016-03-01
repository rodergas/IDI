#include <QLineEdit>
class MyLineEdit: public QLineEdit
{
  Q_OBJECT
  public:
  	MyLineEdit(QWidget *parent);
	bool verde;
	int numLCD;
  public slots:
  void acertar(QString);
  void reset();
};

#include <QLineEdit>
class MyLineEdit: public QLineEdit
{
  Q_OBJECT
  public:
  	MyLineEdit(QWidget *parent);
	bool shift;
	QString line;
  public slots:
    void clicaShift();
    void clicaA();
    void clicaE();
    void clicaI();
    void clicaO();
    void clicaU();

};

#include <QLabel>
class MyLabel: public QLabel
{
  Q_OBJECT
  public:
  	MyLabel(QWidget *parent);
	int resultat;
  public slots:

  void sumaUn();
  void sumaDos();
  void restart();
};

#include <QLabel>
class MyLabel: public QLabel
{
  Q_OBJECT
  public:
  	MyLabel(QWidget *parent);
	int yellow;
	int red;
	int tempGraus;
	int tempLabel;
  public slots:

  void Groc(int g);
  void Vermell(int v);
  void TemperaturaLabel(int t);
  void Color(int g, int v, int temp);
  void Suma();
  void Resta();
};

#include <QLabel>
class MyLabel: public QLabel
{
  Q_OBJECT
  public:
  	MyLabel(QWidget *parent);
	//int camio;
	//int cotxe;
// 	int moto;
// //  	int reca;
  public slots:
    void ClicaCotxe();
    void ClicaCamio();
    void ClicaMoto();
    void rec();
    void Obrir();
    void Tancar();
};

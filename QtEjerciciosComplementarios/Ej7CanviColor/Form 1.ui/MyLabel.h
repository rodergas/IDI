#include <QLabel>
class MyLabel: public QLabel
{
  Q_OBJECT
  public:
  	MyLabel(QWidget *parent);
	bool rojo;
	bool verde;
	bool amarillo;
  public slots:

  void CanviColor();
};

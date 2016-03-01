// .h

#include <QLabel>
class nameOfClass: public QLabel
{
  Q_OBJECT
  private:
	QString text2;
        int n;
  public:
    
  nameOfClass (QWidget *parent);
  
  public slots:

  void posarCero();
  void posarNumero(int);
  void getText(QString str);
  
};

// .cpp

#include "MyQLabel.h"

MyQLabel::MyQLabel(QWidget *parent):QLabel(parent)
{
}

void MyQLabel::posarCero() {
	posarNumero(0);
}

void MyQLabel::posarNumero(int n) {
	if (intValue() == 0) {
		setSegmentStyle(Flat);
		setStyleSheet("color:green");
		display(n);
	}

}



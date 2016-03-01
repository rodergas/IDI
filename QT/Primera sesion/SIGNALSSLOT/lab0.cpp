#include <QApplication>
#include <QFrame>
#include <QLayout>

#include <QLineEdit>
#include <QPushButton>

int main( int argc, char ** argv)
{
  // Creem tots els components
  QApplication a(argc, argv);
  QString fontFamily = "Arial";
  a.setFont(fontFamily);
//Crea frame
  QFrame F(0,NULL);
  //Crea contenidor horitzontal
  QHBoxLayout* cH = new QHBoxLayout(&F);


//Afegeix una caixa de text
  QLineEdit* le = new QLineEdit(&F);
  cH->addWidget(le);
//Afegeix un espai(hortizonal, vertical)
  QSpacerItem* sp = new QSpacerItem(100,20);
  cH->addItem(sp);
  //Crea contenidor vertical
  QVBoxLayout* cV = new QVBoxLayout(&F);
  cH->addItem(cV);
  //Afegeix boto
  QPushButton* ok = new QPushButton("D'acord", &F);
  cV->addWidget(ok);
  //Afegeix un altre boto
  QPushButton* surt = new QPushButton("Surt", &F);
  cV->addWidget(surt);

  F.show();
  return a.exec();
}

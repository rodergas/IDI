#include <QApplication>
#include <QFrame>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLCDNumber>
#include <QDial>


int main( int argc, char ** argv)
{
  // Creem tots els components
  QApplication app(argc, argv);
  QFrame *w=new QFrame();
  QVBoxLayout *mainLayout=new QVBoxLayout(w);

  QLabel *label_mostra   = new QLabel ( "Hours", w); //lbl1
  QLabel *label_mostra2   = new QLabel ( "Minutes", w); //lbl1

  QLCDNumber *h = new QLCDNumber(2, w);
  QLCDNumber *m = new QLCDNumber(2, w);

  QDial *dh = new QDial(w);
  QDial *dm = new QDial(w);

  QVBoxLayout *HorasL=new QVBoxLayout(w);
  QVBoxLayout *MinutosL=new QVBoxLayout(w);

  QHBoxLayout *layHoriz  = new QHBoxLayout();          // lo1  Layout Horizontal

  QHBoxLayout *qButtonLayout = new QHBoxLayout();
  QPushButton *quitButton = new QPushButton("&Exit", w);

  // // // // // // //
  HorasL->addWidget(label_mostra);
  HorasL->addWidget(h);
  HorasL->addWidget(dh);

  MinutosL->addWidget(label_mostra2);
  MinutosL->addWidget(m);
  MinutosL->addWidget(dm);

  layHoriz->addLayout(HorasL);
  layHoriz->addLayout(MinutosL);

  // Insertem l'espai i el buttó de quit al layout horizontal del botó
  qButtonLayout->addItem(new QSpacerItem(30,10,QSizePolicy::Expanding,QSizePolicy::Minimum));
  qButtonLayout->addWidget(quitButton);

  // Afegim tots els elements dins del layout principal
  mainLayout->addLayout(layHoriz);
  //mainLayout->addLayout(layHoriz);
  //mainLayout->addItem(new QSpacerItem(20,40,QSizePolicy::Minimum,QSizePolicy::Expanding));
  mainLayout->addLayout(qButtonLayout);

  app.connect(quitButton, SIGNAL(clicked()), w, SLOT(close()));
  //app.connect(txtLine, SIGNAL(textChanged(const QString&)), label_mostra, SLOT(setText(const QString &)));
  //app.connect(dh, SIGNAL);

  w->show();
  return app.exec();}

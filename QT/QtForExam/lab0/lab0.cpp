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
  /*
  QVBoxLayout *mainLayout=new QVBoxLayout(w);
  QLabel *label_mostra   = new QLabel ( "Etiqueta de mostra", w); //lbl1
  QHBoxLayout *layHoriz  = new QHBoxLayout();          // lo1  Layout Horizontal
  QLabel *label_nouText  = new QLabel( "Entra el nou text:", w);  //lbl2
  QLineEdit *txtLine=new QLineEdit( "Line Edit", w);
  QHBoxLayout *qButtonLayout = new QHBoxLayout();
  QPushButton *quitButton = new QPushButton("&Quit", w); //La & Hace que se cierre la ventana

  // Insertem el label i el editor de text al primer layout horizontal
  layHoriz->addWidget(label_nouText);
  layHoriz->addWidget(txtLine);

  // Insertem l'espai i el buttó de quit al layout horizontal del botó
  qButtonLayout->addItem(new QSpacerItem(30,10,QSizePolicy::Expanding,QSizePolicy::Minimum));
  qButtonLayout->addWidget(quitButton);
  
  // Afegim tots els elements dins del layout principal
  mainLayout->addWidget(label_mostra);
  mainLayout->addLayout(layHoriz);
  mainLayout->addItem(new QSpacerItem(20,40,QSizePolicy::Minimum,QSizePolicy::Expanding));
  mainLayout->addLayout(qButtonLayout);

  app.connect(quitButton, SIGNAL(clicked()), w, SLOT(close()));
  app.connect(txtLine, SIGNAL(textChanged(const QString&)), label_mostra, SLOT(setText(const QString &)));

  */
  QDial* hoursDial = new QDial(w);
  QDial* minutesDial = new QDial(w);
  QLabel* hourst = new QLabel("Hours", w);
  QLabel* minutest = new QLabel("Minutes", w);
  QLCDNumber* hours = new QLCDNumber(w);
  QLCDNumber* minutes = new QLCDNumber(w);
  QGridLayout* gridLayout = new QGridLayout(w);

  hourst->setAlignment(Qt::AlignBottom);
  minutest->setAlignment(Qt::AlignBottom);
  hoursDial->setMaximum(23);
  hoursDial->setMinimum(0);
  minutesDial->setMaximum(59);
  minutesDial->setMinimum(0);

  gridLayout->addWidget(hourst,0,0,1,1);
  gridLayout->addWidget(minutest,0,1,1,1);
  gridLayout->addWidget(hours,1,0,1,1);
  gridLayout->addWidget(minutes,1,1,1,1);
  gridLayout->addWidget(hoursDial,2,0,1,1);
  gridLayout->addWidget(minutesDial,2,1,1,1);

  app.connect(hoursDial,SIGNAL(sliderMoved(int)), hours,SLOT(display(int)));
  app.connect(minutesDial,SIGNAL(sliderMoved(int)),minutes,SLOT(display(int)));
  w->show();
  return app.exec();
}

#include <QApplication>
#include <QPushbutton>
#include <QFrame>
#include <QLayout>
#include <QLineEdit>

int main(int argc, char ** argv){
	QApplication a(argc,argv);

	QString fontFamily = "Arial";
	a.setFont(fontFamily);

	QFrame F(0, NULL);

	QGridLayout* cH = new QGridLayout(&F);

	QLineEdit* le = new QLineEdit(&F);
	cH->addWidget(le,0,0,-1,1);

	QSpacerItem *sp = new QSpacerItem(100,20);
	cH->addItem(sp,0,1,1,1);

	QPushButton* ok = new QPushButton("D'acord", &F);
	cH->addWidget(ok,0,2,1,1);


	QPushButton* surt = new QPushButton("Surt", &F);
	cH->addWidget(surt,1,2,1,1);

	F.show();
	return a.exec();
}
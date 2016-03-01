#include <QApplication>
#include <QPushbutton>
#include <QFrame>
#include <QLayout>
#include <QLineEdit>
#include <QLabel>
#include <mylabel.h>
#include <MyForm.h>

int main(int argc, char ** argv){
	QApplication a(argc,argv);

    /*QString fontFamily = "Arial";
	a.setFont(fontFamily);

	QFrame F(0, NULL);

    QVBoxLayout* cH = new QVBoxLayout(&F);

	QLineEdit* le = new QLineEdit(&F);
    cH->addWidget(le);

    MyLabel* text = new MyLabel(&F);
    text->setText("olakase");
    text->setVisible(false);
    cH->addWidget(text);

    a.connect(le,SIGNAL(textChanged(QString)), text,SLOT(setModifiedText(QString)));

    a.connect(le,SIGNAL(returnPressed()), text,SLOT(setTextInherited()));

	F.show();
    return a.exec();*/

    MyForm form;
    form.show();
    return a.exec();
}

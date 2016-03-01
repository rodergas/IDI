#include <QApplication>
#include <QPushbutton>

int main(int argc, char ** argv){
	QApplication a(argc,argv);

	QPushButton hello("Hola mundo", 0);

	hello.resize(150,30);

	hello.show();

	return a.exec();
}
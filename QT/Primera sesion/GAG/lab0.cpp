#include <QApplication>
#include <QFrame>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>


int main( int argc, char ** argv)
{
  // Creem tots els components
  QApplication a(argc, argv);
  QPushButton hello("Hello Qt", 0);
  hello.resize(150,30);
  hello.show();
  return a.exec();
}

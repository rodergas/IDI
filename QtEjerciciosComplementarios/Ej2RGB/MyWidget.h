#include <QLabel>
class MyWidget: public QLabel
{
  Q_OBJECT
  public:
  	MyWidget(QWidget *parent);
	QString f;
	QString s;
	QString t;

  public slots:

  void posarColor();
  void agafarFirst(int first);
  void agafarSecond(int second);
  void agafarThird(int third);
};

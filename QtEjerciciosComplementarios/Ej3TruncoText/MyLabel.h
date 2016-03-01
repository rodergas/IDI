#include <QLabel>
class MyLabel: public QLabel
{
  Q_OBJECT
  public:
  	MyLabel(QWidget *parent);
	QString text;
	QString textGlobal;
  public slots:

  void agafarText(QString s);
  void truncar(int n);
};

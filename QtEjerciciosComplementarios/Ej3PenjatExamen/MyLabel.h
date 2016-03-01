#include <QLabel>
class MyLabel: public QLabel
{
  Q_OBJECT
  public:
  	MyLabel(QWidget *parent);
	QString line;
  public slots:
  void agafarText(QString s);
  void reset();
};

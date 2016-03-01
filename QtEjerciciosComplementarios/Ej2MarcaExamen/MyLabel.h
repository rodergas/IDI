#include <QLabel>
#include<QKeyEvent>
class MyLabel: public QLabel
{
  Q_OBJECT
  public:
  	MyLabel(QWidget *parent);

  public slots:
  void agafarText(QString s);
  void returnPressed2();
};

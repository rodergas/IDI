#include <QCheckBox>

class MyCheckBox: public QCheckBox
{
  Q_OBJECT
  public:
  	MyCheckBox(QWidget *parent);

  public slots:
  void agafarTextCheck(QString s);
  void returnPressed2Check();
};

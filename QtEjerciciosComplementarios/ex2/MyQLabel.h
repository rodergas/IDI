#include <QLabel>
class MyQLabel: public QLabel
{
  Q_OBJECT
  private:
    

  public:
    MyQLabel (QWidget *parent);

  public slots:
    void pint (QString str);
};

#include <QLineEdit>
class MyQLineEdit: public QLineEdit
{
  Q_OBJECT
  private:

  int acum;
  QString dic;
  QString sol;

  public:
    MyQLineEdit (QWidget *parent);

  public slots:
    void incr();

  signals:
    void suma1(int);
    void solucio(QString);
};

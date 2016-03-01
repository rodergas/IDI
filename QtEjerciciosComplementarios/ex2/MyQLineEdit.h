#include <QLineEdit>
class MyQLineEdit: public QLineEdit
{
  Q_OBJECT
  private:
    

  public:
    MyQLineEdit (QWidget *parent);

  public slots:
    void actualitzar();

  signals:
    void pintar (QString str);
    void changeCheck(bool b);
};

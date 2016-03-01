#include <QLabel>
class MyQLabel: public QLabel
{
  Q_OBJECT
  private:
    int groc;
    int vermell;
    int increment;
    int graus;

  public:
    MyQLabel (QWidget *parent);

  public slots:
    void numgroc(int);
    void numvermell(int);
    void numincrement(int);
    void suma();
    void resta();

    void changecolor(int);

  signals:
    void envianumero(int);
};

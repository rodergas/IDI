#include <QTextEdit>
class MyTextEdit: public QTextEdit
{
  Q_OBJECT
  public:
  	MyTextEdit(QWidget *parent);
	int numGlob;
	QString sGlob;

  public slots:
    void AgafarString(QString s);
    void AgafarNum(int n);
    void Afegir();
};

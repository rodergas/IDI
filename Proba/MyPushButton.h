#include <QPushButton>
class MyPushButton: public QPushButton
{
  Q_OBJECT
  public:
  	MyPushButton(QWidget *parent);
	
	int placesLl;
	int placesOc;
private: 
  bool verd;
  public slots:
    void actualitza();
    void cogerNumLl(int ll);
    void cogerNumOc(int oc);
    
signals:

  void placesLliures(int n);
  void placesOcupades(int n);
  void placesLliuresIni(int n);
  void placesOcupadesIni(int n);
  


};

#ifndef MYDOUBLESLIDER_H
#define MYDOUBLESLIDER_H
#include <QSlider>
#include <QObject>
#include <QWidget>


class MyDoubleSlider : public QSlider
{
    Q_OBJECT
public:
    MyDoubleSlider(QWidget* parent=0);
    ~MyDoubleSlider();
signals:
    void sliderDoubleMoved(double);
public slots:
    void fromIntToDouble(int);
};

#endif // MYDOUBLESLIDER_H

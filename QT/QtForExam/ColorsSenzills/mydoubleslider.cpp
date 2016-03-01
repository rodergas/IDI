#include "mydoubleslider.h"

MyDoubleSlider::MyDoubleSlider(QWidget* parent):QSlider(parent)
{

}

MyDoubleSlider::~MyDoubleSlider()
{

}

void MyDoubleSlider::fromIntToDouble(int value){
    double doubleValue = value/100.0;
    emit sliderDoubleMoved(doubleValue);
}

#include "MyLCD.h"


MyLCD::MyLCD(QWidget *parent):QLCDNumber(parent)
{
}

void MyLCD::Base3(int n) {
    display(QString::number(n,3));
}

void MyLCD::Zero() {
    display(0);
}



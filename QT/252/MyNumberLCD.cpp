#include "MyNumberLCD.h"

MyNumberLCD::MyNumberLCD(QWidget *parent):QLCDNumber(parent) {}

void MyNumberLCD::Zero() {
    setSegmentStyle(Flat);
    setStyleSheet("color:green");
    display(0);
}

void MyNumberLCD::ColorOnChange(int n) {
    setSegmentStyle(Flat);
    if (intValue() == 0) {
        setStyleSheet("color:green");
        display(n);
    }
    else if (intValue() % 2 == 0) {
            setStyleSheet("color:blue");
            display(n);
    }
    else if (intValue() % 2 != 0) {
            setStyleSheet("color:red");
            display(n);
    }
}

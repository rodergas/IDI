#include "MyLCD.h"

MyLCD::MyLCD(QWidget *parent):QLCDNumber(parent)
{
}

void MyLCD::posarCero() {
    setSegmentStyle(Flat);
    setStyleSheet("color:white;"
                "background-color: black;");
	display(0);
}

void MyLCD::posarNumero(int n){
    if (n == 0) {
        setSegmentStyle(Flat);
        setStyleSheet("color:green");
        display(n);
    }
    else if (n % 2 == 0) {
        setSegmentStyle(Flat);
        setStyleSheet("color:blue");
        display(n);
    }
    else if (n % 2 != 0) {
        setSegmentStyle(Flat);
        setStyleSheet("color:red");
        display(n);
    }
}

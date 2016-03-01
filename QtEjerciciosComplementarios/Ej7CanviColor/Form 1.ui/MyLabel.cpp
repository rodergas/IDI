#include "MyLabel.h"


MyLabel::MyLabel(QWidget *parent):QLabel(parent)
{
    setStyleSheet("QLabel { background-color: rgb(255,0,0);}");
    rojo = true;
    verde = false;
    amarillo = false;
}

void MyLabel::CanviColor() {
    if(rojo){
        setStyleSheet("QLabel { background-color: rgb(255,255,0);}");
        rojo = false;
        amarillo = true;
        verde = false;
    } else if(amarillo){
        setStyleSheet("QLabel { background-color: rgb(0,255,0);}");
        rojo = false;
        amarillo = false;
        verde = true;
    } else{
        setStyleSheet("QLabel { background-color: rgb(255,0,0);}");
        rojo = true;
        amarillo = false;
        verde = false;
    }
}




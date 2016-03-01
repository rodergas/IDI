#include "MyLabel.h"


int reca = 0;
int camio = 0;
int cotxe = 0;
int moto= 0;
bool obert = false;
MyLabel::MyLabel(QWidget *parent):QLabel(parent)
{

    camio = 0;
    cotxe = 0;
    moto = 0;
}

void MyLabel::ClicaCotxe() {
    if(obert){
        ++cotxe;
        setText(QString::number(cotxe));
    }
}

void MyLabel::ClicaCamio() {
     if(obert){
        ++camio;
        setText(QString::number(camio));
     }
}

void MyLabel::ClicaMoto() {
     if(obert){
        ++moto;
        setText(QString::number(moto));
     }
}


void MyLabel::rec() {
    reca = cotxe + camio*4 + moto;
    setText(QString::number(reca));
}


void MyLabel::Obrir() {
setStyleSheet("QLabel { background-color: rgb(0,255,0);}");
obert = true;
}

void MyLabel::Tancar() {
setStyleSheet("QLabel { background-color: rgb(255,0,0);}");
obert = false;
}








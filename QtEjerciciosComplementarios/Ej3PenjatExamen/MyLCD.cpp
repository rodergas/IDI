#include "MyLCD.h"


MyLCD::MyLCD(QWidget *parent):QLCDNumber(parent)
{
    numLCD = 5;
}


void MyLCD::fallos(QString s) {
    QString aux = s;
    aux.remove(QString("D"), Qt::CaseInsensitive);
    aux.remove(QString("I"), Qt::CaseInsensitive);
    aux.remove(QString("C"), Qt::CaseInsensitive);
    aux.remove(QString("O"), Qt::CaseInsensitive);
    aux.remove(QString("N"), Qt::CaseInsensitive);
    aux.remove(QString("A"), Qt::CaseInsensitive);
    aux.remove(QString("R"), Qt::CaseInsensitive);
    for(int i = 0; i < aux.length(); ++i){
        if(aux[i] != ' ') --numLCD;
        if(numLCD <= 0) display(0);
        else display(numLCD);
    }
    numLCD = 5;
}

void MyLCD::resetLCD() {
    numLCD = 5;
    display(numLCD);
}



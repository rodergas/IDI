#include "MyPushButton.h"

MyPushButton::MyPushButton(QWidget *parent):QPushButton(parent)
{
    setStyleSheet("QPushButton { background-color: rgb(0,255,0);}");
    placesLl = 4;
    placesOc = 0;
    emit placesLliures(placesLl);
    emit placesOcupades(placesOc);
    verd = true;
}


void MyPushButton::actualitza() {

    if (verd){
        setStyleSheet("QPushButton { background-color: rgb(255,0,0);}");
        --placesLl;
        ++placesOc;
        emit placesLliures(placesLl);
        emit placesOcupades(placesOc);
        verd = false;
    } else if (!verd) {
        setStyleSheet("QPushButton { background-color: rgb(0,255,0);}");
        ++placesLl;
        --placesOc;
        emit placesLliures(placesLl);
        emit placesOcupades(placesOc);
        verd = true;
    }
}


void MyPushButton::cogerNumLl(int ll) {
    placesLl = ll;
}

void MyPushButton::cogerNumOc(int oc) {
    placesOc = oc;
}

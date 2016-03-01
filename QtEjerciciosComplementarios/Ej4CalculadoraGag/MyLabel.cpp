#include "MyLabel.h"


MyLabel::MyLabel(QWidget *parent):QLabel(parent)
{
    resultat = 0;
}

void MyLabel::sumaUn() {
    resultat += 1;
    setText(QString::number(resultat));
}

void MyLabel::sumaDos() {
    resultat += 2;
    setText(QString::number(resultat));
}

void MyLabel::restart() {
    resultat = 0;
    setText(QString::number(resultat));
}

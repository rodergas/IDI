#include "MyLabel.h"
#include <QTextStream>
int tempLabelAux = 0;
int yellow = 0;
int red = 41;

MyLabel::MyLabel(QWidget *parent):QLabel(parent)
{
    tempLabel = 1;

}

void MyLabel::Groc(int g) {
    yellow = g;
    Color(yellow, red,tempLabelAux);
}

void MyLabel::Vermell(int v) {
    red = v;
    Color(yellow, red,tempLabelAux);

}

void MyLabel::Suma() {
    tempLabelAux += tempLabel;
    setText(QString::number(tempLabelAux));
}
void MyLabel::Resta() {
    tempLabelAux -= tempLabel;
    setText(QString::number(tempLabelAux));
}

void MyLabel::TemperaturaLabel(int t){
    tempLabel = t;
}
void MyLabel::Color(int g,int red, int temp) {
    QTextStream(stdout) << "Entro" << endl;
    if(temp < g) setStyleSheet("QLabel { background-color: rgb(0,255,0);}");
    else if(temp >= g and temp <= red) setStyleSheet("QLabel { background-color: rgb(255,255,0);}");
    else if(temp < g) setStyleSheet("QLabel{ background-color: rgb(255,0,0);}");
}



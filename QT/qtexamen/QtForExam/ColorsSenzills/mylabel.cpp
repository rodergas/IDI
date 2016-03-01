#include "mylabel.h"


MyLabel::MyLabel(QWidget* parent):QLabel(parent)
{

}

MyLabel::~MyLabel()
{

}

void MyLabel::setDouble(double d){
    QLabel::setText(QString::number(d,'f',2));
}

void MyLabel::setRed(){
    //QLabel:palette().setColor(QPalette::Background, QColor::fromRgb(255,0,0,255));
    QLabel::setStyleSheet("background-color: red");
}

void MyLabel::setBlue(){
    QLabel::setStyleSheet("background-color: blue");
}


void MyLabel::setTextInherited(){
    QLabel::setText(QLabel::text());
    if (QLabel::isVisible()){
        QLabel::setVisible(true);
    }
    else {
        QLabel::setVisible(true);
    }

}


void MyLabel::setModifiedText(QString s){
    QString aux;
    for (int i = 0; i < s.size(); ++i){
        if (s[i].isLower()){
            aux.append(s[i].toUpper());
        }
        else {
            aux.append(s[i].toLower());
        }
    }
    QLabel::setText(aux);
}

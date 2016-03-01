#include "MyLabel.h"


MyLabel::MyLabel(QWidget *parent):QLabel(parent)
{
    line ="**********";
}


void MyLabel::agafarText(QString s) {
    QString aux = s;
    if(aux.contains("D", Qt::CaseInsensitive)){
        line.replace(0,1,"D");
    }
    if(aux.contains("I", Qt::CaseInsensitive)){
        line.replace(1,1,"I");
        line.replace(4,1,"I");
        line.replace(9,1,"I");
    }
    if(aux.contains("C", Qt::CaseInsensitive)){
        line.replace(2,1,"C");
        line.replace(3,1,"C");
    }
    if(aux.contains("O", Qt::CaseInsensitive)){
        line.replace(5,1,"O");
    }
    if(aux.contains("A", Qt::CaseInsensitive)){
        line.replace(7,1,"A");
    }
    if(aux.contains("R", Qt::CaseInsensitive)){
        line.replace(8,1,"R");
    }
    if(aux.contains("N", Qt::CaseInsensitive)){
        line.replace(6,1,"N");
    }
    setText(line);
}

void MyLabel::reset(){
    line ="**********";
    setText(line);
}




#include "MyWidget.h"


MyWidget::MyWidget(QWidget *parent):QLabel(parent)
{
}


void MyWidget::posarColor(){
    //setStyleSheet("background-color: rgb (" + f + "," + s + "," + t +")");
    setStyleSheet("QLabel { background-color: rgb("+ f + "," + s + "," + t +");}");
}

void MyWidget::agafarFirst(int first){
    f = QString::number(first);
}

void MyWidget::agafarSecond(int second){
    s = QString::number(second);
}
void MyWidget::agafarThird(int third){
    t = QString::number(third);
}

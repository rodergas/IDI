#include "MyLabel.h"
#include <QTextStream>
QString text2 = "";
MyLabel::MyLabel(QWidget *parent):QLabel(parent)
{


}

void MyLabel::agafarText(QString s){
    text2 = s;
}

void MyLabel::returnPressed2(){
        if(text2 == "Marca") {
            setStyleSheet("QLabel { background-color: rgb(0,255,0);}");
        }else if(text2 == "Desmarca"){
            setStyleSheet("QLabel { background-color: rgb(255,255,255);}");
        }
}








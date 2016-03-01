#include "MyLineEdit.h"


MyLineEdit::MyLineEdit(QWidget *parent):QLineEdit(parent)
{
    numLCD = 5;
}


void MyLineEdit::acertar(QString s) {
    QString aux = s;
    if(s.contains(QString("D"), Qt::CaseInsensitive) and
       s.contains(QString("I"), Qt::CaseInsensitive) and
       s.contains(QString("C"), Qt::CaseInsensitive) and
       s.contains(QString("O"), Qt::CaseInsensitive) and
       s.contains(QString("N"), Qt::CaseInsensitive) and
       s.contains(QString("A"), Qt::CaseInsensitive) and
       s.contains(QString("R"), Qt::CaseInsensitive)){
        clear();
        setStyleSheet("QLineEdit { background-color: rgb(0,255,0);}");
        setReadOnly(true);

    }else{

        aux.remove(QString("D"), Qt::CaseInsensitive);
        aux.remove(QString("I"), Qt::CaseInsensitive);
        aux.remove(QString("C"), Qt::CaseInsensitive);
        aux.remove(QString("O"), Qt::CaseInsensitive);
        aux.remove(QString("N"), Qt::CaseInsensitive);
        aux.remove(QString("A"), Qt::CaseInsensitive);
        aux.remove(QString("R"), Qt::CaseInsensitive);
        for(int i = 0; i < aux.length(); ++i){
            if(aux[i] != ' ') --numLCD;
        }

        if(numLCD <= 0){
            clear();
            setStyleSheet("QLineEdit { background-color: rgb(255,0,0);}");
            setReadOnly(true);
        }
        numLCD = 5;
    }
}


void MyLineEdit::reset(){
    numLCD = 5;
    clear();
    setReadOnly(false);
    setStyleSheet("QLineEdit { background-color: rgb(255,255,255);}");
}

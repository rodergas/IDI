#include "MyQLineEdit.h"

MyQLineEdit::MyQLineEdit(QWidget *parent):QLineEdit(parent) {
    acum = 0;
    dic = "diccionari";
    sol = "**********";
}

void MyQLineEdit:: incr(){

    emit suma1(acum);


    QString aux= text().right(1);
    if (dic.contains(aux, Qt::CaseInsensitive)){

        int value = dic.indexOf(aux);
        sol.replace(value, 1, aux);
        value = dic.indexOf(aux,value+1);
        while(value != -1){

            sol.replace(value, 1, aux);
            value = dic.indexOf(aux,value+1);
        }

        emit solucio(sol);
        if (sol == dic){
            setStyleSheet("background-color:green");
            setText("");
        }
    }
    else {
        ++acum;
        emit suma1(acum);
        if (acum >= 5){
            setStyleSheet("background-color:red");
            setText("");
        }
    }

}





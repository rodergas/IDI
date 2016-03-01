#include "MyCheckBox.h"

QString text3 = "";
MyCheckBox::MyCheckBox(QWidget *parent):QCheckBox(parent)
{


}

void MyCheckBox::agafarTextCheck(QString s){
    text3 = s;
}

void MyCheckBox::returnPressed2Check(){
        if(text3 == "Marca") {
            setChecked(true);
        }else if(text3 == "Desmarca"){
            setChecked(false);
        }
}








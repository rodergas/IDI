#include "MyQLineEdit.h"

MyQLineEdit::MyQLineEdit(QWidget *parent):QLineEdit(parent) {
}

void MyQLineEdit:: actualitzar(){
  if (text() == "Marca") {
    emit pintar("green");
    emit changeCheck(true);
  }
  else if (text() == "Desmarca") {
    emit pintar("red");
    emit changeCheck(false);   
  }
}

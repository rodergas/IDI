#include "MyQLabel.h"

MyQLabel::MyQLabel(QWidget *parent):QLabel(parent) {
    graus = 0;
    increment = 1;
    groc = 0;
    vermell = 41;
}

void MyQLabel::numgroc(int ngroc) {
  groc = ngroc;
  changecolor(graus);
}

void MyQLabel::numvermell(int nvermell) {
  vermell = nvermell;
  changecolor(graus);
}

void MyQLabel::numincrement(int nincrement) {
  increment = nincrement;
}

void MyQLabel::suma() {
  graus = graus + increment;
  setText(QString::number(graus));
  emit envianumero(graus);
}

void MyQLabel::resta() {
  graus = graus - increment;
  setText(QString::number(graus));
  emit envianumero(graus);
}

void MyQLabel::changecolor(int n) {
  if (n < groc) setStyleSheet("background-color:green");
  else if (n >= groc and n <= vermell) setStyleSheet("background-color:yellow");
  else if (n >vermell) setStyleSheet("background-color:red");
}


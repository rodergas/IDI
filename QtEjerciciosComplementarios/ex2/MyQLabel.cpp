#include "MyQLabel.h"

MyQLabel::MyQLabel(QWidget *parent):QLabel(parent) {
}

void MyQLabel::pint(QString color) {
  setStyleSheet("background-color:"+color);
}

#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent):QLabel(parent)
{
}

void MyLabel::agafarText(QString s) {
    textGlobal = s;
}

void MyLabel::truncar(int n) {
    text = textGlobal;
    text.truncate(n);
    setText(text);
}

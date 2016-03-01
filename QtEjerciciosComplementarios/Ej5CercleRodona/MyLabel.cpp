#include "MyLabel.h"


MyLabel::MyLabel(QWidget *parent):QLabel(parent)
{
}

void MyLabel::Creu() {
    setText("X");
}

void MyLabel::Cercle() {
    setText("O");
}


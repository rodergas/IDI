#include "MyLineEdit.h"


MyLineEdit::MyLineEdit(QWidget *parent):QLineEdit(parent)
{
    shift = false;
    line ="";
}


void MyLineEdit::clicaShift() {
    shift = not shift;
}

void MyLineEdit::clicaA() {
    if(shift)line += 'A';
    else line += 'a';
    setText(line);
}

void MyLineEdit::clicaE() {
    if(shift)line += 'E';
    else line += 'e';
    setText(line);
}

void MyLineEdit::clicaI() {
    if(shift)line += 'I';
    else line += 'i';
    setText(line);
}

void MyLineEdit::clicaO() {
    if(shift)line += 'O';
    else line += 'o';
    setText(line);
}

void MyLineEdit::clicaU() {
    if(shift)line += 'U';
    else line += 'u';
    setText(line);
}




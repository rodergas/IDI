#include "MyTextEdit.h"


MyTextEdit::MyTextEdit(QWidget *parent):QTextEdit(parent)
{
}

void MyTextEdit::AgafarNum(int n) {
numGlob = n;
}

void MyTextEdit::AgafarString(QString s) {
sGlob = s;
}

void MyTextEdit::Afegir() {
    QString num = QString::number(numGlob);
    QString final= num +" "+ sGlob;
    append(final);
}




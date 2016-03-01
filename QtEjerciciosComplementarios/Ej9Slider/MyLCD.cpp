#include "MyLCD.h"


MyLCD::MyLCD(QWidget *parent):QLCDNumber(parent)
{
    numLCD = 0;
    numAgafat = 1;
    numUndo = 0;
}

void MyLCD::agafarNum(int n) {
    numAgafat = n;
}

void MyLCD::Suma() {
    numUndo = numLCD;
    numLCD += numAgafat;
    display(numLCD);
}

void MyLCD::Restar() {
    numUndo = numLCD;
    numLCD -= numAgafat;
    display(numLCD);
}

void MyLCD::Undo(){
       display(numUndo);
       numLCD = numUndo;
}

void MyLCD::Reset(){
       numUndo = numLCD;
       numLCD = 0;
       display(numLCD);
}



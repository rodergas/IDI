#include "MyLCD.h"

MyLCD::MyLCD(QWidget *parent):QLCDNumber(parent)
{
}

void MyLCD::posarCero() {
	display(0);
}

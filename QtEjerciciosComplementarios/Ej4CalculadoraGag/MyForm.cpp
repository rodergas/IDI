// MyForm.cpp
#include "MyForm.h"

MyForm::MyForm(QWidget* parent): QWidget(parent) {
        ui.setupUi(this);
        // altres inicialitzacions i connexions
        //connect(ui.okButton, SIGNAL(clicked()), this, SLOT(close()));
}

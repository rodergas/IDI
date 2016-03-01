/********************************************************************************
** Form generated from reading UI file 'Form.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <MyLineEdit.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    MyLineEdit *lineEdit;
    QPushButton *pushButton_7;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(868, 515);
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 40, 91, 22));
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 40, 91, 22));
        pushButton_3 = new QPushButton(Form);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(350, 40, 91, 22));
        pushButton_4 = new QPushButton(Form);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(490, 40, 91, 22));
        pushButton_5 = new QPushButton(Form);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(650, 40, 91, 22));
        pushButton_6 = new QPushButton(Form);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(90, 80, 651, 22));
        lineEdit = new MyLineEdit(Form);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(92, 120, 651, 21));
        pushButton_7 = new QPushButton(Form);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(100, 200, 631, 22));

        retranslateUi(Form);
        QObject::connect(pushButton_6, SIGNAL(clicked()), lineEdit, SLOT(clicaShift()));
        QObject::connect(pushButton, SIGNAL(clicked()), lineEdit, SLOT(clicaA()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), lineEdit, SLOT(clicaE()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), lineEdit, SLOT(clicaI()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), lineEdit, SLOT(clicaO()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), lineEdit, SLOT(clicaU()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), Form, SLOT(close()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Form", "A", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Form", "E", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Form", "I", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Form", "O", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Form", "U", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("Form", "Shift", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("Form", "Quit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H

/********************************************************************************
** Form generated from reading UI file 'MyForm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFORM_H
#define UI_MYFORM_H

#include <MyQLineEdit.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyForm
{
public:
    MyQLineEdit *lineEdit;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *MyForm)
    {
        if (MyForm->objectName().isEmpty())
            MyForm->setObjectName(QString::fromUtf8("MyForm"));
        MyForm->resize(400, 300);
        lineEdit = new MyQLineEdit(MyForm);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 20, 281, 41));
        lcdNumber = new QLCDNumber(MyForm);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(70, 110, 51, 51));
        label = new QLabel(MyForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 120, 52, 13));
        label_2 = new QLabel(MyForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 120, 81, 16));
        pushButton = new QPushButton(MyForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 240, 91, 22));

        retranslateUi(MyForm);
        QObject::connect(lineEdit, SIGNAL(textEdited(QString)), lineEdit, SLOT(incr()));
        QObject::connect(lineEdit, SIGNAL(suma1(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(lineEdit, SIGNAL(solucio(QString)), label_2, SLOT(setText(QString)));

        QMetaObject::connectSlotsByName(MyForm);
    } // setupUi

    void retranslateUi(QWidget *MyForm)
    {
        MyForm->setWindowTitle(QApplication::translate("MyForm", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MyForm", "Paraula:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MyForm", "**********", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MyForm", "New Game", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyForm: public Ui_MyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFORM_H

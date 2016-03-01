/********************************************************************************
** Form generated from reading UI file 'MyForm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFORM_H
#define UI_MYFORM_H

#include <MyQLabel.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyForm
{
public:
    MyQLabel *label;
    QLabel *label_2;
    MyQLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QPushButton *pushButton_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *MyForm)
    {
        if (MyForm->objectName().isEmpty())
            MyForm->setObjectName(QString::fromUtf8("MyForm"));
        MyForm->resize(436, 349);
        label = new MyQLabel(MyForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 20, 251, 101));
        label_2 = new QLabel(MyForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 150, 52, 13));
        label_3 = new MyQLabel(MyForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 150, 52, 13));
        pushButton = new QPushButton(MyForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 190, 91, 81));
        pushButton_2 = new QPushButton(MyForm);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 190, 101, 81));
        spinBox = new QSpinBox(MyForm);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(350, 160, 52, 22));
        spinBox->setMinimum(41);
        spinBox->setMaximum(100);
        spinBox_2 = new QSpinBox(MyForm);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(60, 160, 52, 22));
        spinBox_2->setMaximum(20);
        spinBox_3 = new QSpinBox(MyForm);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(90, 280, 52, 22));
        spinBox_3->setMinimum(1);
        spinBox_3->setMaximum(10);
        pushButton_3 = new QPushButton(MyForm);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(330, 290, 91, 22));
        label_4 = new QLabel(MyForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 160, 52, 13));
        label_5 = new QLabel(MyForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(290, 160, 52, 13));
        label_6 = new QLabel(MyForm);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 280, 61, 16));

        retranslateUi(MyForm);
        QObject::connect(pushButton_3, SIGNAL(clicked()), MyForm, SLOT(close()));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), label, SLOT(numgroc(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), label, SLOT(numvermell(int)));
        QObject::connect(spinBox_3, SIGNAL(valueChanged(int)), label_3, SLOT(numincrement(int)));
        QObject::connect(pushButton, SIGNAL(clicked()), label_3, SLOT(suma()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_3, SLOT(resta()));
        QObject::connect(label_3, SIGNAL(envianumero(int)), label, SLOT(changecolor(int)));

        QMetaObject::connectSlotsByName(MyForm);
    } // setupUi

    void retranslateUi(QWidget *MyForm)
    {
        MyForm->setWindowTitle(QApplication::translate("MyForm", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QApplication::translate("MyForm", "Graus:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MyForm", "0", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MyForm", "+", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MyForm", "-", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MyForm", "Sortir", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MyForm", "Groc", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MyForm", "Vermell", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MyForm", "Increment:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyForm: public Ui_MyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFORM_H

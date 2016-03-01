/********************************************************************************
** Form generated from reading UI file 'Form.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <MyLabel.h>
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
    MyLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(374, 80);
        label = new MyLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 21, 16));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 20, 41, 22));
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 20, 41, 22));
        pushButton_3 = new QPushButton(Form);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(150, 20, 31, 22));
        pushButton_4 = new QPushButton(Form);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(230, 20, 91, 22));

        retranslateUi(Form);
        QObject::connect(pushButton_4, SIGNAL(clicked()), Form, SLOT(close()));
        QObject::connect(pushButton, SIGNAL(clicked()), label, SLOT(sumaUn()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label, SLOT(sumaDos()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), label, SLOT(restart()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form", "0", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Form", "1", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Form", "2", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Form", "C", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Form", "Surt", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H

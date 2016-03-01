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
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    MyLabel *label;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(400, 300);
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 30, 51, 22));
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 30, 51, 22));
        label = new MyLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 61, 31));
        pushButton_3 = new QPushButton(Form);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(160, 60, 51, 22));

        retranslateUi(Form);
        QObject::connect(pushButton_3, SIGNAL(clicked()), Form, SLOT(close()));
        QObject::connect(pushButton, SIGNAL(clicked()), label, SLOT(Creu()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label, SLOT(Cercle()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Form", "Creu", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Form", "Cercle", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        pushButton_3->setText(QApplication::translate("Form", "&Sortir", 0, QApplication::UnicodeUTF8));
        pushButton_3->setShortcut(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H

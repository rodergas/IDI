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
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    MyLabel *label;
    QLabel *label_2;
    MyLabel *label_3;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpinBox *spinBox_3;
    QLabel *label_6;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(626, 448);
        label = new MyLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 511, 131));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 180, 41, 16));
        label_3 = new MyLabel(Form);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 180, 52, 13));
        spinBox = new QSpinBox(Form);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(130, 210, 52, 22));
        spinBox->setMaximum(20);
        spinBox_2 = new QSpinBox(Form);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(410, 210, 52, 22));
        spinBox_2->setMinimum(41);
        spinBox_2->setMaximum(100);
        label_4 = new QLabel(Form);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 210, 31, 16));
        label_5 = new QLabel(Form);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(360, 210, 41, 20));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 240, 141, 61));
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 240, 151, 61));
        spinBox_3 = new QSpinBox(Form);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(190, 310, 52, 22));
        spinBox_3->setMinimum(1);
        spinBox_3->setMaximum(10);
        label_6 = new QLabel(Form);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(120, 310, 61, 20));
        pushButton_3 = new QPushButton(Form);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(410, 360, 91, 22));

        retranslateUi(Form);
        QObject::connect(spinBox_3, SIGNAL(valueChanged(int)), label, SLOT(TemperaturaLabel(int)));
        QObject::connect(spinBox_3, SIGNAL(valueChanged(int)), label_3, SLOT(TemperaturaLabel(int)));
        QObject::connect(pushButton, SIGNAL(clicked()), label_3, SLOT(Suma()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_3, SLOT(Resta()));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), label, SLOT(Groc(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), label, SLOT(Vermell(int)));
        QObject::connect(pushButton_3, SIGNAL(clicked()), Form, SLOT(close()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QApplication::translate("Form", "Graus:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form", "0", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Form", "Groc:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Form", "Vermell:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Form", "+", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Form", "-", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Form", "Increment", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Form", "Sortir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H

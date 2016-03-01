/********************************************************************************
** Form generated from reading UI file 'Form.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <MyLCD.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    MyLCD *lcdNumber;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(400, 300);
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 81, 20));
        horizontalSlider = new QSlider(Form);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(100, 50, 160, 23));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(9);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 20, 52, 13));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 90, 91, 91));
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 90, 91, 91));
        pushButton_2->setIconSize(QSize(32, 32));
        lcdNumber = new MyLCD(Form);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(220, 90, 141, 91));
        pushButton_3 = new QPushButton(Form);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 190, 91, 22));
        pushButton_4 = new QPushButton(Form);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(270, 190, 91, 22));
        pushButton_5 = new QPushButton(Form);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(280, 260, 91, 22));

        retranslateUi(Form);
        QObject::connect(pushButton_5, SIGNAL(clicked()), Form, SLOT(close()));
        QObject::connect(horizontalSlider, SIGNAL(sliderMoved(int)), lcdNumber, SLOT(agafarNum(int)));
        QObject::connect(pushButton, SIGNAL(clicked()), lcdNumber, SLOT(Suma()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), lcdNumber, SLOT(Restar()));
        QObject::connect(horizontalSlider, SIGNAL(sliderMoved(int)), label_2, SLOT(setNum(int)));
        QObject::connect(pushButton_3, SIGNAL(clicked()), lcdNumber, SLOT(Undo()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), lcdNumber, SLOT(Reset()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form", "Diferencial", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form", "1", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Form", "+", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Form", "-", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Form", "Undo", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Form", "Reset", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Form", "&Sortir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H

/********************************************************************************
** Form generated from reading UI file 'Form.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <MyWidget.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    MyWidget *label_4;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(517, 300);
        horizontalSlider = new QSlider(Form);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(60, 150, 160, 23));
        horizontalSlider->setMaximum(255);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(Form);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(60, 190, 160, 23));
        horizontalSlider_2->setMaximum(255);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_3 = new QSlider(Form);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(60, 230, 160, 23));
        horizontalSlider_3->setMaximum(255);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        lcdNumber = new QLCDNumber(Form);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(230, 150, 64, 23));
        lcdNumber_2 = new QLCDNumber(Form);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(230, 190, 64, 23));
        lcdNumber_3 = new QLCDNumber(Form);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(230, 230, 64, 23));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 230, 91, 22));
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 230, 91, 22));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 150, 16, 16));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 200, 16, 16));
        label_3 = new QLabel(Form);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 230, 16, 16));
        label_4 = new MyWidget(Form);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 20, 281, 111));

        retranslateUi(Form);
        QObject::connect(horizontalSlider, SIGNAL(sliderMoved(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(sliderMoved(int)), lcdNumber_2, SLOT(display(int)));
        QObject::connect(horizontalSlider_3, SIGNAL(sliderMoved(int)), lcdNumber_3, SLOT(display(int)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), Form, SLOT(close()));
        QObject::connect(horizontalSlider, SIGNAL(sliderMoved(int)), label_4, SLOT(agafarFirst(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(sliderMoved(int)), label_4, SLOT(agafarSecond(int)));
        QObject::connect(horizontalSlider_3, SIGNAL(sliderMoved(int)), label_4, SLOT(agafarThird(int)));
        QObject::connect(pushButton, SIGNAL(clicked()), label_4, SLOT(posarColor()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Form", "Ok", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Form", "Quit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form", "R", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form", "G", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form", "B", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H

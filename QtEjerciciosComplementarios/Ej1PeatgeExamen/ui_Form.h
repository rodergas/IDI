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
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    MyLabel *label_6;
    MyLabel *label_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_2;
    MyLabel *label;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QPushButton *pushButton;
    MyLabel *label_4;
    MyLabel *label_2;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(693, 743);
        widget = new QWidget(Form);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(130, 80, 421, 241));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new MyLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 1, 1, 1);

        label_3 = new MyLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        radioButton = new QRadioButton(widget);
        buttonGroup = new QButtonGroup(Form);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(radioButton);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout->addWidget(radioButton, 1, 3, 1, 2);

        radioButton_2 = new QRadioButton(widget);
        buttonGroup->addButton(radioButton_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 2, 3, 1, 2);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 0, 2, 1);

        label = new MyLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 3, 1, 1);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 4, 4, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 3, 0, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        label_4 = new MyLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        label_2 = new MyLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);


        retranslateUi(Form);
        QObject::connect(pushButton, SIGNAL(clicked()), label_2, SLOT(ClicaCamio()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_3, SLOT(ClicaCotxe()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), label_4, SLOT(ClicaMoto()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), label_6, SLOT(rec()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_6, SLOT(rec()));
        QObject::connect(pushButton, SIGNAL(clicked()), label_6, SLOT(rec()));
        QObject::connect(radioButton, SIGNAL(clicked()), label, SLOT(Obrir()));
        QObject::connect(radioButton_2, SIGNAL(clicked()), label, SLOT(Tancar()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), Form, SLOT(close()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Form", "0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form", "0", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("Form", "Obrir", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("Form", "Tancar", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Form", "Cotxe", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        pushButton_4->setText(QApplication::translate("Form", "Sortir", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Form", "Moto", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Form", "Recaptacio (\342\202\254):", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Form", "Camio", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Form", "0", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H

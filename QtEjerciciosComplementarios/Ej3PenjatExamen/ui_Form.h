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
#include <MyLabel.h>
#include <MyLineEdit.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *widget;
    QFormLayout *formLayout;
    MyLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    MyLabel *label_2;
    MyLCD *lcdNumber;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(686, 410);
        widget = new QWidget(Form);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(6, 6, 536, 123));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new MyLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        label_2 = new MyLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        lcdNumber = new MyLCD(widget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setProperty("intValue", QVariant(5));

        formLayout->setWidget(1, QFormLayout::LabelRole, lcdNumber);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::LabelRole, verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(418, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        formLayout->setLayout(3, QFormLayout::SpanningRole, horizontalLayout_2);


        retranslateUi(Form);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Form, SLOT(close()));
        QObject::connect(lineEdit, SIGNAL(textEdited(QString)), lcdNumber, SLOT(fallos(QString)));
        QObject::connect(pushButton, SIGNAL(clicked()), lcdNumber, SLOT(resetLCD()));
        QObject::connect(lineEdit, SIGNAL(textEdited(QString)), label_2, SLOT(agafarText(QString)));
        QObject::connect(pushButton, SIGNAL(clicked()), label_2, SLOT(reset()));
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), lineEdit, SLOT(acertar(QString)));
        QObject::connect(pushButton, SIGNAL(clicked()), lineEdit, SLOT(reset()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form", "Paraula:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form", "**********", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Form", "&Sortir", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Form", "Nou", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H

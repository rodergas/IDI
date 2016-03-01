/********************************************************************************
** Form generated from reading UI file 'Form.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <MyPushButton.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    MyPushButton *pushButton;
    MyPushButton *pushButton_3;
    QVBoxLayout *verticalLayout_3;
    MyPushButton *pushButton_2;
    MyPushButton *pushButton_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_5;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(712, 510);
        verticalLayout_5 = new QVBoxLayout(Form);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton = new MyPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 60));
        pushButton->setSizeIncrement(QSize(11, 14));

        verticalLayout_2->addWidget(pushButton);

        pushButton_3 = new MyPushButton(Form);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 60));

        verticalLayout_2->addWidget(pushButton_3);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton_2 = new MyPushButton(Form);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 60));

        verticalLayout_3->addWidget(pushButton_2);

        pushButton_4 = new MyPushButton(Form);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 60));

        verticalLayout_3->addWidget(pushButton_4);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        spinBox = new QSpinBox(Form);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setEnabled(false);
        spinBox->setValue(4);

        verticalLayout->addWidget(spinBox);

        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        spinBox_2 = new QSpinBox(Form);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setEnabled(false);

        verticalLayout->addWidget(spinBox_2);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_5->addLayout(horizontalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 118, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(498, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_5 = new QPushButton(Form);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(Form);
        QObject::connect(pushButton, SIGNAL(clicked()), pushButton, SLOT(actualitza()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), pushButton_2, SLOT(actualitza()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), pushButton_3, SLOT(actualitza()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), pushButton_4, SLOT(actualitza()));
        QObject::connect(pushButton, SIGNAL(placesLliures(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(pushButton_2, SIGNAL(placesLliures(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(pushButton_3, SIGNAL(placesLliures(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(pushButton_4, SIGNAL(placesLliures(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(pushButton, SIGNAL(placesOcupades(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(pushButton_2, SIGNAL(placesOcupades(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(pushButton_3, SIGNAL(placesOcupades(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(pushButton_4, SIGNAL(placesOcupades(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), pushButton_2, SLOT(cogerNumLl(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), pushButton_2, SLOT(cogerNumOc(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), pushButton, SLOT(cogerNumLl(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), pushButton, SLOT(cogerNumOc(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), pushButton_3, SLOT(cogerNumLl(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), pushButton_3, SLOT(cogerNumOc(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), pushButton_4, SLOT(cogerNumLl(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), pushButton_4, SLOT(cogerNumOc(int)));
        QObject::connect(pushButton_5, SIGNAL(clicked()), Form, SLOT(close()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        pushButton_3->setText(QString());
        pushButton_2->setText(QString());
        pushButton_4->setText(QString());
        label->setText(QApplication::translate("Form", "Places Lliures", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form", "Places Ocupades", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Form", "&Sortir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H

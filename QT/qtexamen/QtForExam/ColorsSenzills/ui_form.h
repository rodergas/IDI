/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mydoubleslider.h"
#include "mylabel.h"

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    MyDoubleSlider *horizontalSlider;
    MyDoubleSlider *horizontalSlider_2;
    MyDoubleSlider *horizontalSlider_3;
    QHBoxLayout *horizontalLayout_2;
    MyLabel *label_2;
    MyLabel *label_3;
    MyLabel *label_4;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(400, 216);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
        Form->setSizePolicy(sizePolicy);
        widget = new QWidget(Form);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 30, 361, 166));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSlider = new MyDoubleSlider(widget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        horizontalSlider_2 = new MyDoubleSlider(widget);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_2);

        horizontalSlider_3 = new MyDoubleSlider(widget);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new MyLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        label_3 = new MyLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        label_4 = new MyLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Form);
        QObject::connect(horizontalSlider, SIGNAL(sliderDoubleMoved(double)), label_2, SLOT(setDouble(double)));
        QObject::connect(horizontalSlider, SIGNAL(sliderMoved(int)), horizontalSlider, SLOT(fromIntToDouble(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(sliderDoubleMoved(double)), label_3, SLOT(setDouble(double)));
        QObject::connect(horizontalSlider_2, SIGNAL(sliderMoved(int)), horizontalSlider_2, SLOT(fromIntToDouble(int)));
        QObject::connect(horizontalSlider_3, SIGNAL(sliderMoved(int)), horizontalSlider_3, SLOT(fromIntToDouble(int)));
        QObject::connect(horizontalSlider_3, SIGNAL(sliderDoubleMoved(double)), label_4, SLOT(setDouble(double)));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Exemple d'\303\272s de Qt Designer", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("Form", "0", 0));
        label_3->setText(QApplication::translate("Form", "0", 0));
        label_4->setText(QApplication::translate("Form", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H

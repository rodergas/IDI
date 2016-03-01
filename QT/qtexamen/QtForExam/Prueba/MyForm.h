#ifndef MYFORM_H
#define MYFORM_H

#include <QWidget>
#include "ui_form.h"

class MyForm : public QWidget
{
    Q_OBJECT
public:
    explicit MyForm(QWidget *parent = 0);
    ~MyForm();

signals:

public slots:

private:
    Ui::Form ui;
};

#endif // MYFORM_H

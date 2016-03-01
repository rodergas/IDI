#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class MyLabel: public QLabel
{
    Q_OBJECT
public:
    MyLabel(QWidget* parent=0);
    ~MyLabel();

signals:

public slots:
    void setBlue();
    void setRed();
    void setModifiedText(QString);
    void setTextInherited();
};

#endif // MYLABEL_H

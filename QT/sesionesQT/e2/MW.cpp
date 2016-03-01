#include "MW.h"

MW::MW(QWidget *parent) {
    QPalette P(palette());
    P.setColor(QPalette::Background, Qt::black);
    setAutoFillBackground(true);
    setPalette(P);
    R = 0;
    G = 0;
    B = 0;
}

void MW::RC(int r) {
    R = r;
}

void MW::GC(int g) {
    G = g;
}

void MW::BC(int b) {
    B = b;
}

void MW::SET() {
    QPalette P(palette());
    P.setColor(QPalette::Background, QColor(R,G,B));
    setAutoFillBackground(true);
    setPalette(P);
    show();
}

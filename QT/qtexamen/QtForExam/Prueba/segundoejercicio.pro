TEMPLATE=app
QT+=widgets
CONFIG += qt
DEPENDPATH+=.
INCLUDEPATH+=.
#Input
SOURCES+=main.cpp \
    mylabel.cpp \
    MyForm.cpp

HEADERS += \
    mylabel.h \
    MyForm.h

FORMS += \
    form.ui

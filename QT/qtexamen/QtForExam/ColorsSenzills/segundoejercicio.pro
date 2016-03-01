TEMPLATE=app
QT+=widgets
CONFIG += qt
DEPENDPATH+=.
INCLUDEPATH+=.
#Input
SOURCES+=main.cpp \
    mylabel.cpp \
    MyForm.cpp \
    mydoubleslider.cpp

HEADERS += \
    mylabel.h \
    MyForm.h \
    mydoubleslider.h

FORMS += \
    form.ui

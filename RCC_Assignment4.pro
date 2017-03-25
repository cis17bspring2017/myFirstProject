TEMPLATE = app
TARGET = RCC_Assignment4

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += account.h \
           history.h \
           transfer.h \
           summary.h \
    banksoftware.h
SOURCES += account.cpp \
           history.cpp \
           main.cpp \
           transfer.cpp \
           summary.cpp \
    banksoftware.cpp

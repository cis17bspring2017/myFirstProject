TEMPLATE = app
TARGET = RCC_Assignment4

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    bankwindow.cpp\
   checkingaccount.cpp\
    savingsaccount.cpp \
    loginwindow.cpp

HEADERS += \
    bankwindow.h\
   checkingaccount.h\
    savingsaccount.h \
    loginwindow.h

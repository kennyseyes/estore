#-------------------------------------------------
#
# Project created by QtCreator 2017-10-07T23:27:44
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = store
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    store.cpp \
    login.cpp \
    forgetpassword.cpp \
    signup.cpp \
    user.cpp \
    clothes.cpp \
    food.cpp \
    book.cpp \
    electronics.cpp \
    sports.cpp \
    product.cpp \
    productdetails.cpp \
    cart.cpp

HEADERS += \
        mainwindow.h \
    store.h \
    login.h \
    forgetpassword.h \
    signup.h \
    user.h \
    clothes.h \
    food.h \
    book.h \
    electronics.h \
    sports.h \
    product.h \
    productdetails.h \
    cart.h

FORMS += \
        mainwindow.ui \
    store.ui \
    login.ui \
    forgetpassword.ui \
    signup.ui \
    user.ui \
    productdetails.ui \
    cart.ui

RESOURCES += \
    img.qrc

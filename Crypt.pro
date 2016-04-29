#-------------------------------------------------
#
# Project created by QtCreator 2016-04-11T17:05:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Crypt
TEMPLATE = app


SOURCES += src/main.cpp \
    src/crypt.cpp \
    src/crypt_func.cpp \
    src/func_crpt_vigi.cpp \
    src/work_with_file.cpp \
    src/func_morze.cpp

HEADERS  += \
    crypt.h

FORMS    += \
    crypt.ui

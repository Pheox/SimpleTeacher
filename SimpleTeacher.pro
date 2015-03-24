#-------------------------------------------------
#
# Project created by QtCreator 2015-03-24T22:37:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleTeacher
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    src/Dictionary.cc \
    src/Lexicon.cc \
    src/Word.cc

HEADERS  += mainwindow.h \
    src/Dictionary.h \
    src/Lexicon.h \
    src/Word.h

FORMS    += mainwindow.ui \
    main.ui

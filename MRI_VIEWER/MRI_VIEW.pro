#-------------------------------------------------
#
# Project created by QtCreator 2023-05-10T10:19:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MRI_VIEW
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++17
CONFIG += no_keywords

INCLUDEPATH += C:/C++/libs/boost_1_82_0
INCLUDEPATH += C:\ProgramData\anaconda3\include
INCLUDEPATH += C:\ProgramData\anaconda3\

LIBS += -LC:/ProgramData/anaconda3/libs/ -lpython311 -lpython3
LIBS += -LC:/C++/libs/boost_1_82_0/stage/lib/ -lboost_thread-vc141-mt-gd-x64-1_82 -lboost_python311-vc141-mt-gd-x64-1_82

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    imagePack.cpp \
    interp.cpp \
    main.cpp \
    mainwindow.cpp \
    packContain.cpp \
    packParams.cpp \
    predresult.cpp \
    qlistmodel.cpp \
    dialogwhichwind.cpp \
    packscroll.cpp \
    dialpl.cpp \
    dialogclassify.cpp \
    dialogclwait.cpp \
    predsclasses.cpp

HEADERS += \
        mainwindow.h \
    imagePack.h \
    interp.h \
    mainwindow.h \
    packContain.h \
    packParams.h \
    predresult.h \
    qlistmodel.h \
    dialogwhichwind.h \
    packscroll.h \
    dialpl.h \
    dialogclassify.h \
    dialogclwait.h \
    predsclasses.h

FORMS += \
        mainwindow.ui \
    dialogwhichwind.ui \
    dialpl.ui \
    dialogclassify.ui \
    dialogclwait.ui

win32:RC_FILE = ico.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

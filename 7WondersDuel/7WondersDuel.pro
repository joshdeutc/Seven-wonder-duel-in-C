QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    a_propos.cpp \
    batimentwidget.cpp \
    jetonprogreswidget.cpp \
    main.cpp \
    mainwindow.cpp \
    merveillewidget.cpp

HEADERS += \
    a_propos.h \
    batimentwidget.h \
    carte_bat_merv.h \
    jetonprogreswidget.h \
    jeu.h \
    mainwindow.h \
    merveillewidget.h

FORMS += \
    a_propos.ui \
    batimentwidget.ui \
    jetonprogreswidget.ui \
    mainwindow.ui \
    merveillewidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES +=

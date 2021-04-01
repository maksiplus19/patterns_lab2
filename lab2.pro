QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    changecolorcommand.cpp \
    changepencolorcommand.cpp \
    changepensizecommand.cpp \
    changetypecommand.cpp \
    command.cpp \
    figdialog.cpp \
    figure.cpp \
    main.cpp \
    mainwindow.cpp \
    movecommand.cpp \
    qcustomgraphicview.cpp \
    resizecommand.cpp

HEADERS += \
    changecolorcommand.h \
    changepencolorcommand.h \
    changepensizecommand.h \
    changetypecommand.h \
    command.h \
    figdialog.h \
    figtype.h \
    figure.h \
    mainwindow.h \
    movecommand.h \
    qcustomgraphicview.h \
    resizecommand.h

FORMS += \
    figdialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

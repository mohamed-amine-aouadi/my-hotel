QT       += core gui multimedia multimediawidgets
QT        +=sql
QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    animation.cpp \
    chambre.cpp \
    connexion.cpp \
    demande.cpp \
    equipement.cpp \
    evenement.cpp \
    hebergement.cpp \
    historique.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindowvideo.cpp \
    materiaux.cpp \
    pdf.cpp \
    personnel.cpp \
    qcustomplot.cpp \
    statchambre.cpp \
    statevenement.cpp \
    statistiq.cpp \
    statistique.cpp

HEADERS += \
    animation.h \
    chambre.h \
    connexion.h \
    demande.h \
    evenement.h \
    hebergement.h \
    mainwindow.h \
    mainwindowvideo.h \
    materiaux.h \
    pdf.h \
    personnel.h \
    qcustomplot.h \
    statchambre.h \
    statevenement.h \
    statistiq.h \
    statistique.h

FORMS += \
    mainwindow.ui \
    mainwindowvideo.ui \
    pdf.ui \
    statchambre.ui \
    statevenement.ui \
    statistiq.ui \
    statistique.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

DISTFILES += \
    historique.txt

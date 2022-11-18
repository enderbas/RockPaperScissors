QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
RESOURCES = icons.qrc
win32:RC_FILE += appicon.rc

SOURCES += \
    agirtas.cpp \
    bilgisayar.cpp \
    kagit.cpp \
    kullanici.cpp \
    makas.cpp \
    nesne.cpp \
    main.cpp \
    oyuncu.cpp \
    oyun.cpp \
    ozelkagit.cpp \
    tas.cpp \
    ustamakas.cpp

HEADERS += \
    agirtas.h \
    bilgisayar.h \
    kagit.h \
    kullanici.h \
    makas.h \
    nesne.h \
    oyuncu.h \
    oyun.h \
    ozelkagit.h \
    tas.h \
    ustamakas.h

FORMS += \
    oyun.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc

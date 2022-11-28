QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
RESOURCES = icons.qrc
win32:RC_FILE += appicon.rc

SOURCES += \
    src/agirtas.cpp \
    src/bilgisayar.cpp \
    src/kagit.cpp \
    src/kullanici.cpp \
    src/makas.cpp \
    src/nesne.cpp \
    src/main.cpp \
    src/oyuncu.cpp \
    src/oyun.cpp \
    src/ozelkagit.cpp \
    src/tas.cpp \
    src/ustamakas.cpp

HEADERS += \
    headers/agirtas.h \
    headers/bilgisayar.h \
    headers/kagit.h \
    headers/kullanici.h \
    headers/makas.h \
    headers/nesne.h \
    headers/oyuncu.h \
    headers/oyun.h \
    headers/ozelkagit.h \
    headers/tas.h \
    headers/ustamakas.h

FORMS += \
    src/oyun.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc

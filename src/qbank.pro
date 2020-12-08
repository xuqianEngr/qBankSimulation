QT -= gui
QT       += sql

CONFIG += c++11 console
CONFIG -= app_bundle
CONFIG += console pro

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
        control/interfacestate.cpp \
        control/statemathine.cpp \
        control/terminalcontrol.cpp \
        control/workpath.cpp \
        data/configuration.cpp \
        database/accountmanerger.cpp \
        database/usermanerger.cpp \
        main.cpp \
        out/textout.cpp \
        state/adduserstate.cpp \
        state/changepasswdstate.cpp \
        state/loginstate.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    control/interfacestate.h \
    control/statemathine.h \
    control/terminalcontrol.h \
    control/workpath.h \
    data/configuration.h \
    database/accountmanerger.h \
    database/usermanerger.h \
    out/textout.h \
    state/adduserstate.h \
    state/changepasswdstate.h \
    state/loginstate.h

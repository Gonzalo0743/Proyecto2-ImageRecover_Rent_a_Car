QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    genAlgorithm.cpp \
    genome.cpp \
    graph.cpp \
    irwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    rcwindow.cpp
    genAlgorithm.cpp
    graph.cpp
    genome.cpp
    irwindow.cpp
    rcwindow.cpp

HEADERS += \
    genAlgorithm.h \
    genome.h \
    graph.h \
    irwindow.h \
    mainwindow.h \
    rcwindow.h
    genome.h
    genAlgorithm.h
    graph.h
    irwindow.h
    rcwindow.h

FORMS += \
    irwindow.ui \
    mainwindow.ui \
    rcwindow.ui
    rcwindow.ui
    irwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opencv/build/x64/vc15/lib/ -lopencv_world454
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opencv/build/x64/vc15/lib/ -lopencv_world454d
else:unix: LIBS += -L$$PWD/../../../../../opencv/build/x64/vc15/lib/ -lopencv_world454

INCLUDEPATH += $$PWD/../../../../../opencv/build/include
DEPENDPATH += $$PWD/../../../../../opencv/build/include

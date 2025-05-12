QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CardGame
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    Deck.cpp \
    Card.cpp \
    Hand.cpp \
    Player.cpp

HEADERS += \
    mainwindow.h \
    Deck.h \
    Card.h \
    Hand.h \
    Player.h

RESOURCES += resources.qrc

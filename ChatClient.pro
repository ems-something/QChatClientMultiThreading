#-------------------------------------------------
#
# Project created by QtCreator 2013-04-09T11:44:06
#
#-------------------------------------------------

QT       += qml quick quickcontrols2 core network

TARGET = ChatClient
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

RESOURCES += \
    qml.qrc

SOURCES += main.cpp \
    Message.cpp \
    Chat.cpp \
    Client.cpp

HEADERS += \
    Message.h \
    Chat.h \
    Client.h

DISTFILES += \
    main.qml \
    LoginForm.ui.qml \
    Login.qml \
    ChatView.qml \
    ChatViewForm.ui.qml \
    Presentation.qml \
    PresentationForm.ui.qml

TEMPLATE = app
TARGET = Server
DESTDIR = ../x64/Debug

INCLUDEPATH +=\
      inc \
      json

HEADERS += \
    inc/msg_buff.h \
    inc/tcp_server.h \
    json/json-forwards.h \
    json/json.h

SOURCES += \
    src/jsoncpp.cpp \
    src/server.cpp \
    src/tcp_server.cpp


# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = lib
TARGET = DDS
DESTDIR = ../x64/Debug
CONFIG += staticlib debug console
win32{ INCLUDEPATH += src \
               inc \
               json \
               ../DDS/inc \
               C:/PROGRA~1/rti_connext_dds-6.1.0/include \
               C:/PROGRA~1/rti_connext_dds-6.1.0/include/ndds \
               C:/PROGRA~1/rti_connext_dds-6.1.0/include/ndds/hpp
     }
linux{ INCLUDEPATH += src \
               inc \
               json \
               ../DDS/inc \
               /home/user/rti_connext_dds-6.1.0/include \
               /home/user/rti_connext_dds-6.1.0/include/ndds \
               /home/user/rti_connext_dds-6.1.0/include/ndds/hpp
     }
win32{ DEFINES += _CONSOLE RTI_WIN32 RTI_STATIC _SCL_SECURE_NO_WARNINGS }
linux{ DEFINES += _CONSOLE RTI_UNIX RTI_STATIC _SCL_SECURE_NO_WARNINGS }
win32{ LIBS += \
    -L$$PWD/../DDS/bin/x64/Debug -lDDS \
    -LC:/PROGRA~1/rti_connext_dds-6.1.0/lib/x64Win64VS2017 -lnddscpp2zd \
    -LC:/PROGRA~1/rti_connext_dds-6.1.0/lib/x64Win64VS2017 -lnddsczd \
    -LC:/PROGRA~1/rti_connext_dds-6.1.0/lib/x64Win64VS2017 -lnddscorezd \
    -LC:/PROGRA~1/rti_connext_dds-6.1.0/lib/x64Win64VS2017 -lnetapi32 \
    -ladvapi32 \
    -luser32 \
    -lWS2_32 \
    -lDDS
    }
linux{ LIBS += \
        -L$$PWD/../../build/x64/Debug/  -lDDS \
        -L/home/user/rti_connext_dds-6.1.0/lib/x64Linux4gcc7.3.0 -lnddscpp2zd \
        -L/home/user/rti_connext_dds-6.1.0/lib/x64Linux4gcc7.3.0 -lnddsczd \
        -L/home/user/rti_connext_dds-6.1.0/lib/x64Linux4gcc7.3.0 -lnddscorezd \
        -ldl
    }
DEPENDPATH += .
MOC_DIR += GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += debug
UI_DIR += GeneratedFiles
RCC_DIR += GeneratedFiless

#include(DDS.pri)
HEADERS += ./inc/dds_comm.h \
    ./inc/reader_listener.h
SOURCES += ./src/dds_comm.cxx

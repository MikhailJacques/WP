TEMPLATE = app
TARGET = 1MissionPlan_Subscriber
DESTDIR = ../x64/Debug

INCLUDEPATH +=  \
        /home/user/rti_connext_dds-6.1.0/include \
        /home/user/rti_connext_dds-6.1.0/include/ndds \
        /home/user/rti_connext_dds-6.1.0/include/ndds/hpp


DEFINES += _CONSOLE RTI_UNIX RTI_STATIC _SCL_SECURE_NO_WARNINGS

LIBS += \
        -L/home/user/rti_connext_dds-6.1.0/lib/x64Linux4gcc7.3.0 -lnddscpp2zd \
        -L/home/user/rti_connext_dds-6.1.0/lib/x64Linux4gcc7.3.0 -lnddsczd \
        -L/home/user/rti_connext_dds-6.1.0/lib/x64Linux4gcc7.3.0 -lnddscorezd \
        -ldl

HEADERS += \
    application.hpp \
    dds_msgs.hpp \
    dds_msgsPlugin.hpp

SOURCES += \
    dds_msgs.cxx \
    dds_msgsPlugin.cxx \
    dds_msgs_subscriber.cxx

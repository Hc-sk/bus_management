QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_busroad.cpp \
    add_road.cpp \
    addstop.cpp \
    bus_road_in.cpp \
    busroad_man.cpp \
    busstops.cpp \
    change_road.cpp \
    change_route.cpp \
    changestop.cpp \
    connect_sql.cpp \
    delete_road.cpp \
    deleteroute.cpp \
    deletestop.cpp \
    main.cpp \
    manager.cpp \
    raod_man.cpp \
    road_inf.cpp \
    road_select.cpp \
    stop_man.cpp \
    user.cpp \
    widget.cpp

HEADERS += \
    add_busroad.h \
    add_road.h \
    addstop.h \
    bus_road_in.h \
    busroad_man.h \
    busstops.h \
    change_road.h \
    change_route.h \
    changestop.h \
    connect_sql.h \
    delete_road.h \
    deleteroute.h \
    deletestop.h \
    manager.h \
    raod_man.h \
    road_inf.h \
    road_select.h \
    stop_man.h \
    user.h \
    widget.h

FORMS += \
    add_busroad.ui \
    add_road.ui \
    addstop.ui \
    bus_road_in.ui \
    busroad_man.ui \
    busstops.ui \
    change_road.ui \
    change_route.ui \
    changestop.ui \
    connect_sql.ui \
    delete_road.ui \
    deleteroute.ui \
    deletestop.ui \
    manager.ui \
    raod_man.ui \
    road_inf.ui \
    road_select.ui \
    stop_man.ui \
    user.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc

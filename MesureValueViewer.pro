QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += C++14 c++17
#QMAKE_CXXFLAGS += /std:c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Domain/mesurevalue.cpp \
    IRepository/imesurevaluerepository.cpp \
    IRepository/isensorrepository.cpp \
    IRepository/mesurevaluerepositoryfactory.cpp \
    IRepository/sensorrepositoryfactory.cpp \
    Repository/mesurevaluejsonrepository.cpp \
    Repository/sensorrepositoryfake.cpp \
    Utility/utility.cpp \
    View/sensorview.cpp \
    ViewModel/sensorviewmodel.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Domain/mesurevalue.h \
    IRepository/imesurevaluerepository.h \
    IRepository/isensorrepository.h \
    IRepository/mesurevaluerepositoryfactory.h \
    IRepository/sensorrepositoryfactory.h \
    Repository/mesurevaluejsonrepository.h \
    Repository/sensorrepositoryfake.h \
    Utility/utility.h \
    View/sensorview.h \
    ViewModel/sensorviewmodel.h \
    mainwindow.h

FORMS += \
    View/sensorview.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

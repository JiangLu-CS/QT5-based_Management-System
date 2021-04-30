#-------------------------------------------------
#
# Project created by QtCreator 2020-10-02T13:35:15
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = studentSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    setting.cpp \
    teachermain.cpp \
    teacherselectgrade.cpp \
    showallgrades.cpp \
    selectcourse.cpp \
    showstudent.cpp \
    studentmanage.cpp \
    modstu.cpp \
    dormmanage.cpp \
    dormall.cpp \
    dormmod.cpp \
    bookmanage.cpp \
    book.cpp \
    bookall.cpp \
    bookmod.cpp \
    allteacher.cpp \
    showteacher.cpp \
    teachermod.cpp \
    studentyear.cpp \
    showstudentyear.cpp \
    stuevaluate.cpp \
    stuinformation.cpp \
    stusearchgrade.cpp \
    stuselectcourse.cpp \
    teacheckcourse.cpp \
    teaevaluate.cpp \
    teamain.cpp \
    teasubmitgrade.cpp \
    studentmain.cpp

HEADERS += \
        mainwindow.h \
    setting.h \
    teachermain.h \
    teacherselectgrade.h \
    showallgrades.h \
    selectcourse.h \
    showstudent.h \
    studentmanage.h \
    modstu.h \
    dormmanage.h \
    dormall.h \
    dormmod.h \
    bookmanage.h \
    book.h \
    bookall.h \
    bookmod.h \
    allteacher.h \
    showteacher.h \
    teachermod.h \
    studentyear.h \
    showstudentyear.h \
    stuevaluate.h \
    stuinformation.h \
    stusearchgrade.h \
    stuselectcourse.h \
    teacheckcourse.h \
    teaevaluate.h \
    teamain.h \
    teasubmitgrade.h \
    studentmain.h

FORMS += \
        mainwindow.ui \
    teachermain.ui \
    teacherselectgrade.ui \
    showallgrades.ui \
    selectcourse.ui \
    showstudent.ui \
    studentmanage.ui \
    modstu.ui \
    dormmanage.ui \
    dormall.ui \
    dormmod.ui \
    bookmanage.ui \
    book.ui \
    bookall.ui \
    bookmod.ui \
    allteacher.ui \
    showteacher.ui \
    teachermod.ui \
    studentyear.ui \
    showstudentyear.ui \
    stuevaluate.ui \
    stuinformation.ui \
    stusearchgrade.ui \
    stuselectcourse.ui \
    teacheckcourse.ui \
    teaevaluate.ui \
    teamain.ui \
    teasubmitgrade.ui \
    studentmain.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    re.qrc

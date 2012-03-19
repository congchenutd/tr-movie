QT       -= gui
CONFIG   -= app_bundle

QT += testlib

TEMPLATE = app
CONFIG += console
INCLUDEPATH += include

SOURCES += \
	src/Statement.cpp \
	src/Rental.cpp \
	src/Price.cpp \
	src/Movie.cpp \
	src/Main.cpp \
	src/Customer.cpp \
	test/TestMovie.cpp

HEADERS += \
	include/Statement.h \
	include/Rental.h \
	include/Price.h \
	include/Movie.h \
	include/Customer.h

FORMS += \
	ui/MainWindow.ui

RESOURCES += \
	ui/Resource.qrc


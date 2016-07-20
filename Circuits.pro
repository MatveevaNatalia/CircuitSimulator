TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    circuit.cpp \
    elements.cpp \
    elementfactory.cpp \
    nodalmatrixsolver.cpp

HEADERS += \
    circuit.h \
    elements.h \
    elementfactory.h \
    nodalmatrixsolver.h

LIBS += -llapack -lblas -larmadillo


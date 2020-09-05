TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += bib
INCLUDEPATH += gui_glut

LIBS += -lGL -lGLU -lglut -l3ds -lSDL_image

SOURCES += main.cpp \
    bib/Camera.cpp \
    bib/CameraDistante.cpp \
    bib/CameraJogo.cpp \
    bib/Desenha.cpp \
    bib/model3ds.cpp \
    bib/Vetor3D.cpp \
    gui_glut/extra.cpp \
    gui_glut/gui.cpp \
    objeto.cpp \
    pc.cpp \
    mesa.cpp \
    leque.cpp \
    cadeira.cpp \
    mesac.cpp \
    ojeto3ds.cpp

HEADERS += \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/model3ds.h \
    bib/Vetor3D.h \
    gui_glut/extra.h \
    gui_glut/gui.h \
    objeto.h \
    pc.h \
    mesa.h \
    leque.h \
    cadeira.h \
    mesac.h \
    ojeto3ds.h

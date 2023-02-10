TEMPLATE     = vcapp
TARGET       = Graphicus-03
CONFIG      += warn_on qt debug windows console
HEADERS     += canevas.h carre.h cercle.h rectangle.h coordonnee.h forme.h vecteur.h couche.h graphicusGUI.h tests.h centralWidget.h moninterface.h
SOURCES     += graphicus-02.cpp canevas.cpp carre.cpp cercle.cpp rectangle.cpp forme.cpp vecteur.cpp couche.cpp tests.cpp moninterface.cpp 
INCLUDEPATH += ../Graphicus-03
LIBS        += graphicusGUI.lib
QT          += widgets
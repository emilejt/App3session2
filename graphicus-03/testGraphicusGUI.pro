TEMPLATE     = vcapp
TARGET       = graphicus-03
CONFIG      += warn_on qt debug windows console
HEADERS     += canevas.h carre.h cercle.h coordonnee.h couche.h forme.h tests.h vecteur.h graphicusGUI.h rectangle.h monInterface.h
SOURCES     += monInterface.cpp graphicus-02.cpp canevas.cpp carre.cpp cercle.cpp couche.cpp forme.cpp tests.cpp rectangle.cpp vecteur.cpp
INCLUDEPATH += 
LIBS        += graphicusGUI.lib
QT          += widgets

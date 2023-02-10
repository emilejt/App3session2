#
# Auteur: C.-A. Brunet
# Date: 08 janvier 2018
# Description: compilation de graphicus-01. Ce fichier fait partie de 
#	la distribution de Graphicus.
#

graphicus-02: graphicus-02.o tests.o canevas.o couche.o forme.o carre.o cercle.o rectangle.o vecteur.o
	g++ -o graphicus-02 graphicus-02.o tests.o canevas.o couche.o forme.o carre.o cercle.o rectangle.o vecteur.o

graphicus-02.o: graphicus-02.cpp canevas.h couche.h forme.h
	g++ -c graphicus-02.cpp

tests.o: tests.cpp tests.h canevas.h couche.h forme.h cercle.h rectangle.h carre.h vecteur.h
	g++ -c tests.cpp

canevas.o: canevas.cpp canevas.h couche.h forme.h
	g++ -c canevas.cpp

couche.o: couche.cpp couche.h forme.h
	g++ -c couche.cpp

forme.o: forme.cpp forme.h
	g++ -c forme.cpp

cercle.o: cercle.cpp cercle.h
	g++ -c cercle.cpp
	
carre.o: carre.cpp carre.h
	g++ -c carre.cpp

rectangle.o: rectangle.cpp rectangle.h
	g++ -c rectangle.cpp

vecteur.o: vecteur.cpp vecteur.h 
	g++ -c vecteur.cpp

clean:
	rm  -f *.o

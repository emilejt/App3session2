#ifndef VECTEUR_H
#define VECTEUR_H
#include <iostream>
#include "forme.h"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
#define CAPACITE_INITIALE 2
template <typename T>
class Vecteur
{
private:
	int taille;
	T* tableau;
	int capacite;
	int indexcourant;
	friend ostream& operator<<<T>(ostream& os, const Vecteur& v);
public: 
	Vecteur(int laCapacite = CAPACITE_INITIALE);
	~Vecteur();
	int getCapacite();
	int getTaille() const;
	bool ajoutFin(T donnee);
	void clearVecteur();
	void afficher(ostream & s);
	T retireritem(int index);
	T getitem(int index);
	bool isEmpty();
	void augmentetaille();
	int getindexcourant();
	T& operator[] (int index);
	void operator+=(T N);
	void operator ++();
	void operator --();
	void afficherForme(ostream& s);
	const T& operator[](int index) const;
};


#include "vecteur.cpp"

#endif
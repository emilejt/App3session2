#ifndef VECTEUR_H
#define VECTEUR_H
#include <iostream>
#include "forme.h"
using namespace std;
#define CAPACITE_INITIALE 2

class Vecteur
{
private:
	int taille;
	Forme** tableau;
	int capacite;
public: 
	Vecteur(int laCapacite = CAPACITE_INITIALE);
	~Vecteur();
	int getCapacite();
	int getTaille();
	bool ajoutFin(Forme* pForme);
	void clearVecteur();
	void afficherForme(ostream & s);
	Forme* retirerForme(int index);
	Forme*getForme(int index);
	bool isEmpty();

};
#endif

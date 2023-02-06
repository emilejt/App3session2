#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
#include "forme.h"
#define CAPACITE_INITIALE 2

using namespace std;

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
	bool isEmpty();
	Forme* retirerForme(int index); //retour pointeur forme ou 0 si echec
	Forme* getForme(int index); //retour pointeur forme ou 0 si echec
	void afficherForme(ostream & s);
};
#endif

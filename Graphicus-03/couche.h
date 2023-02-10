/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe Couche gere un vecteur de pointeur de formes
 *    geometriques en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef COUCHE_H
#define COUCHE_H
#include "vecteur.h"
#include "forme.h"
#include <string>
#include <iostream>


#define MAX_CARACTERES 30

class Couche
{
private:
	Vecteur <Forme*>vect;
	int etat;
public:
	Couche();
	~Couche();
	bool ajoutForme(Forme* pForme);
	Forme* retraitForme(int index);
	Forme* obtenirForme(int index);
	double aireTotale();
	bool translaterCouche(int x,int y);
	bool reinitialiser();
	bool changerEtat(string etatDemande);
	void afficherCouche(ostream & s);
	int getEtat();
	bool isEmpty();
	int getTailleCouche();
	bool effacerCouche();
	const Forme* operator[](int index) const;
	Forme* operator[](int index);
	
};

#endif

#ifndef CARRE_H
#define CARREE_H

#include <iostream>
#include "coordonnee.h"
#include "forme.h"

using namespace std;

class Carree: public Forme
{
public:
	Carree(int x=0, int y=0, int longueur=0);
	~Carree();
	double aire();
	void setLongueur(int longueur);
	int getLongueur();
	int getPositionx();
	void setPositionx(int positionx);
	int getPositiony();
	void setPositiony(int positiony);
	void afficher(ostream & s);
private:
	int longueurCote;
};
#endif

#ifndef CERCLE_H
#define CERCLE_H

#include <iostream>
#include "coordonnee.h"
#include "forme.h"

using namespace std;

class Cercle: public Forme
{
public:
	Cercle(int x=0, int y=0, int rayoncercle=0);
	~Cercle();
	double aire();
	void setRayon(int rayoncercle);
	int getRayon();
	int getPositionx();
	void setPositionx(int positionx);
	int getPositiony();
	void setPositiony(int positiony);
	void afficher(ostream & s);
private:
	int rayon;
};
#endif

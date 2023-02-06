#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "coordonnee.h"
#include "forme.h"

using namespace std;

class Rectangle: public Forme
{
public:
	Rectangle(int x=0, int y=0, int largeurRect=0, int longueurRect=0) ;
	~Rectangle();
	double aire();
	void setLargeur(int largeurRect);
	int getLargeur();
	void setLongueur(int longueurRect);
	int getLongueur();
	int getPositionx();
	void setPositionx(int positionx);
	int getPositiony();
	void setPositiony(int positiony);
	void afficher(ostream & s);
private:
	int largeur;
	int longueur;
};
#endif

#include "forme.h"
#include "rectangle.h"

Rectangle::Rectangle(int x1, int y1, int longueurRect, int largeurRect)
{
	ancrage.x=x1;
	ancrage.y=y1;
	largeur=largeurRect;
	longueur=longueurRect;
}

Rectangle::~Rectangle()
{
}

void Rectangle::setLargeur(int largeurRect)
{
	largeur=largeurRect;
}

int Rectangle::getLargeur()
{
	return largeur;
}

void Rectangle::setLongueur(int longueurRect)
{
	longueur=longueurRect;
}

int Rectangle::getLongueur()
{
	return longueur;
}

double Rectangle::aire()
{
	return longueur*largeur;
}

int Rectangle::getPositionx()
{
	return ancrage.x;
}

void Rectangle::setPositionx(int positionx)
{
	ancrage.x=positionx;
}

int Rectangle::getPositiony()
{
	return ancrage.y;
}

void Rectangle::setPositiony(int positiony)
{
	ancrage.y=positiony;
}

void Rectangle::afficher(ostream & s)
{
	cout<<"Rectangle(x="<<ancrage.x<<",y="<<ancrage.y<<",l="<<longueur<<",h= "<<largeur<<",aire="<<longueur*largeur<<")"<<endl;
}

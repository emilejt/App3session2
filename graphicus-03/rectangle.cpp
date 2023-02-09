#include "rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(int x1, int y1, int longueurRectangle, int hauteurRectangle)
{
	 ancrage.x = x1;
 	 ancrage.y = y1;
 	 longueur = longueurRectangle;
 	 hauteur = hauteurRectangle;
}

Rectangle::~Rectangle()
{}

double Rectangle::aire()
{
	return longueur * hauteur;
}
void Rectangle::afficher(ostream & s)
{
	cout <<"Rectangle(x="<< ancrage.x <<",y=" << ancrage.y;
	cout <<", l=" << longueur << ", h=" << hauteur;
	cout <<", aire=" << aire() <<")"<< endl;	
}

int Rectangle::getlongueur()
{
	return longueur;
}

void Rectangle::setlongueur(int longueurRectangle)
{
	longueur = longueurRectangle;
}

int Rectangle::gethauteur()
{
	return hauteur;
}

void Rectangle::sethauteur(int hauteurRectangle)
{
	hauteur = hauteurRectangle;
}

	
	
	



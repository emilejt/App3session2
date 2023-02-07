#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "forme.h"


class Rectangle: public Forme
{
private:
	int longueur;
	int hauteur;
public :
 	Rectangle(int x1 = 0, int y1 = 0, int longueur = 0, int largeur = 0);
 	double aire();
 	~Rectangle();
 	void afficher(ostream & s);
 	int getlongueur();
 	void setlongueur(int longueurRectangle);
 	int gethauteur();
 	void sethauteur(int hauteurRectangle);
 	
 
};
#endif
 	
 	
 		
 	
 	

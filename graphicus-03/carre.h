#ifndef CARRE_H
#define CARRE_H
#include "rectangle.h"
#include <iostream>
using namespace std;

class Carre: public Rectangle
{
	int cote;
public:
	Carre(int x1=0, int y1=0, int coteCarre = 0);
	double aire();
	~Carre();
	void afficher(ostream & s);
	int getcote();
	void setcote(int coteCarre);
};
#endif



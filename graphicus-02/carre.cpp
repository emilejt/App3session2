#include "carre.h"

Carre::Carre(int x1, int y1, int coteCarre)
{
	ancrage.x = x1;
	ancrage.y = y1;
	cote = coteCarre;
}

Carre::~Carre()
{}

double Carre::aire()
{
	return cote * cote;
}

void Carre::afficher(ostream & s)
{
	cout <<"Carre(x="<< ancrage.x <<",y=" << ancrage.y;
	cout <<", c=" << cote;
	cout <<", aire=" << aire() << ")"<<endl;
}

void Carre::setcote(int coteCarre)
{
	cote = coteCarre;
}

int Carre::getcote()
{
	return cote;
}


#include <iostream>
#include "cercle.h"
using namespace std;

Cercle::Cercle(int x1, int y1, int rayonCercle)
{
	ancrage.x = x1;
	ancrage.y = y1;
	rayon = rayonCercle;
}

Cercle::~Cercle()
{}

double Cercle::aire()
{
	return PI * (rayon *rayon);
}

void Cercle::afficher(ostream & s)
{
	cout <<"Cercle(x="<< ancrage.x <<",y=" << ancrage.y;
	cout <<", r=" << rayon;
	cout <<", aire=" << aire() <<")"<< endl;
}

void Cercle::setrayon(int rayonCercle)
{
	rayon = rayonCercle;
}

int Cercle::getrayon()
{
	return rayon;
}

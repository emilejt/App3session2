#include <iostream>
#include "cercle.h"
#include <string>
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

string Cercle::affichage() const
{
	string str;
	str = "C " + to_string(ancrage.x) + " " + to_string(ancrage.y) + " " + to_string(rayon);
	return str;
}

int Cercle::ancragex()
{
	return ancrage.x;
}

int Cercle::ancragey()
{
	return ancrage.y;
}

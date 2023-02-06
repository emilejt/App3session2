#include "forme.h"
#include "carree.h"

using namespace std;

Carree::Carree(int x1, int y1, int longueur)
{
	ancrage.x=x1;
	ancrage.y=y1;
	longueurCote=longueur;
}

Carree::~Carree()
{
}

double Carree::aire()
{
	return longueurCote*longueurCote;
}

void Carree::setLongueur(int longueur)
{
	longueurCote=longueur;
}

int Carree::getLongueur()
{
	return longueurCote;
}

int Carree::getPositionx()
{
	return ancrage.x;
}

void Carree::setPositionx(int positionx)
{
	ancrage.x=positionx;
}

int Carree::getPositiony()
{
	return ancrage.y;
}

void Carree::setPositiony(int positiony)
{
	ancrage.y=positiony;
}

void Carree::afficher(ostream & s)
{
	cout<<"Carree(x="<<ancrage.x<<",y="<<ancrage.y<<",l="<<longueurCote<<",aire="<<longueurCote*longueurCote<<")"<<endl;
}

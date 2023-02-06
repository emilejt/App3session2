#include "forme.h"
#include "cercle.h"
#define PI 3.14
using namespace std;

Cercle::Cercle(int x1, int y1, int rayoncercle)
{
	ancrage.x=x1;
	ancrage.y=y1;
	rayon=rayoncercle;
}

Cercle::~Cercle()
{
}

double Cercle::aire()
{
	return PI*rayon*rayon;
}

void Cercle::setRayon(int rayoncercle)
{
	rayon=rayoncercle;
}

int Cercle::getRayon()
{
	return rayon;
}

int Cercle::getPositionx()
{
	return ancrage.x;
}

void Cercle::setPositionx(int positionx)
{
	ancrage.x=positionx;
}

int Cercle::getPositiony()
{
	return ancrage.y;
}

void Cercle::setPositiony(int positiony)
{
	ancrage.y=positiony;
}

void Cercle::afficher(ostream & s)
{
	cout<<"Cercle(x="<<ancrage.x<<",y="<<ancrage.y<<",r="<<rayon<<",aire="<<PI*rayon*rayon<<")"<<endl;
}

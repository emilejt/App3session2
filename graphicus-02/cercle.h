#ifndef CERCLE_H
#define CERCLE_H
#include "forme.h"
#define PI 3.1415926
#include <iostream>
using namespace std;

class Cercle: public Forme
{
	private:
		int rayon;
	public:
	Cercle(int x1=0, int y1=0, int rayonCercle = 0);
	double aire();
	~Cercle();
	void afficher(ostream & s);
	int getrayon();
	void setrayon(int rayonCercle);
};
#endif
	

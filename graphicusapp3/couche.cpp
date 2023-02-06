/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/
#include "couche.h"
#include <cstring>

using namespace std;

Couche::Couche()
{
	etat= 1;
}

Couche::~Couche()
{}

bool Couche::ajoutForme(Forme *pForme)
{
	if(etat==2)
	{
		vect.ajoutFin(pForme);
	}
	else
	{
		return false;
	}
	return true;
}

Forme* Couche::obtenirForme(int index)
{
	return vect.getForme(index);
}

Forme * Couche::retraitForme(int index)
{
	if(etat==2)
	{
		return vect.retirerForme(index);
	}
	else
	{
		return NULL;
	}
	return NULL;
}

double Couche::aireTotale()
{
	double aire_totale=0.0;
	for(int i=0; i<vect.getTaille();i++)
	{
		Forme *pForme;
		pForme=vect.getForme(i);
		aire_totale+=pForme->aire();
	}
	if(aire_totale<0.0000001)
	{
		return 0;
	}
	return aire_totale;
}

bool Couche::translaterCouche(int x1,int y1)
{
	if(etat==2)
	{
		for(int i=0;i<vect.getTaille();i++)
		{
			Forme *pForme;
			pForme=vect.getForme(i);
			pForme->translater(x1,y1);
		}
	}
	else
	{
		return false;
	}
	return true;
}

bool Couche::reinitialiser()
{
	vect.clearVecteur();
	etat= 1;
	return true;
}


bool Couche::changerEtat(char* etatDemande)
{
	if(strcmp(etatDemande,"active")==0)
	{
		etat=2;
	}
	else if(strcmp(etatDemande, "inactive")==0)
	{
		etat=3;
	}
	else
	{
		return false;
	}
	return true;
}

void Couche::afficherCouche()
{
	vect.afficherForme(cout);
}

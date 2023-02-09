/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/
#include "couche.h"
#include <string>

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
		
		vect += pForme;
	}
	else
	{
		//cout<<"prout"<<endl;
		return false;
	}
	//cout<<vect.getTaille()<<endl;
	return true;
}

Forme* Couche::obtenirForme(int index)
{
	return vect[index];
}

Forme * Couche::retraitForme(int index)
{
	if(etat==2)
	{
		return vect.retireritem(index);
	}
	else
	{
		return NULL;
	}
	return NULL;
}

double Couche::aireTotale()
{
	double aire_totale = 0.0;
	for(int i=0; i<vect.getTaille();i++)
	{
		Forme *pForme;
		pForme=vect.getitem(i);
		aire_totale+=pForme->aire();
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
			pForme=vect.getitem(i);
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
	return true;
}


bool Couche::changerEtat(string etatDemande)
{
	if(etatDemande.compare("active")==0)
	{
		etat=2;
	}
	else if(etatDemande.compare("inactive")==0)
	{
		etat=3;
	}
	else if (etatDemande.compare("initialise") == 0)
	{
		etat = 1;
	}
	else if (etatDemande.compare("cache") == 0)
	{
		etat = 4;
	}
	else
	{
		return false;
	}
	return true;
}

int Couche::getEtat() {
	return etat;
}

void Couche::afficherCouche(ostream & s)
{
	vect.afficherForme(cout);
}

bool Couche::isEmpty()
{
	if(vect.isEmpty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Couche::getTailleCouche()
{
	return vect.getTaille();
}
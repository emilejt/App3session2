/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"
Canevas::Canevas()
{
	char rendreactif[]="active";
	couches[0].changerEtat(rendreactif);
}

Canevas::~Canevas()
{
}

bool Canevas::reinitialiser()
{
	for(int i=0;i<MAX_COUCHES;i++)
	{
		couches[i].reinitialiser();
	}
	char rendreactif[]="active";
	couches[0].changerEtat(rendreactif);
   return true;
}

bool Canevas::activerCouche(int index)
{
	if(index<MAX_COUCHES)
	{
		for(int i=0;i<MAX_COUCHES;i++)
		{
			if(couches[i].translaterCouche(0,0)==1)
			{
				char rendreinactif[]="inactive";
				couches[i].changerEtat(rendreinactif);
			}
		}
		char rendreactif[]="active";
		couches[index].changerEtat(rendreactif);
	}
	else
	{
		return false;
	}
		
   return true;
}

bool Canevas::ajouterForme(Forme *p_forme)
{
	for(int i=0; i<MAX_COUCHES;i++)
	{
		if(couches[i].translaterCouche(0,0)==1)
		{
			couches[i].ajoutForme(p_forme);
			return true;
		}
	}
   return false;
}

bool Canevas::retirerForme(int index)
{
	for(int i=0;i<MAX_COUCHES;i++)
	{
		if(couches[i].translaterCouche(0,0)==1)
		{
			couches[i].retraitForme(index);
			return true;
		}
	}
   return false;
}

double Canevas::aire()
{
	double aire_totale=0.0;
	for(int i=0;i<MAX_COUCHES;i++)
	{
		
		aire_totale+=couches[i].aireTotale();
	}
	
        return aire_totale;
        
}

bool Canevas::translater(int deltaX, int deltaY)
{
	for(int i=0;i<MAX_COUCHES;i++)
	{
		if(couches[i].translaterCouche(0,0)==1)
		{
			couches[i].translaterCouche(deltaX, deltaY);
			return true;
		}
	}
   return false;
}

void Canevas::afficher(ostream & s)
{
	for(int i=0;i<MAX_COUCHES;i++)
	{
		cout<<"Couche "<<i<<endl;
		if(couches[i].aireTotale()==0)
		{
			cout<<"Couche initialisee"<<endl;
		}
		else
		{
			couches[i].afficherCouche();
		}
	}
}

bool Canevas::initialiser(int index)
{
	couches[index].reinitialiser();
	return true;
}

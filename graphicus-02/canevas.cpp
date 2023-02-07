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
	string active = "active";
	couches[0].changerEtat(active);
	
	
}

Canevas::~Canevas()
{
}

bool Canevas::reinitialiser()
{
	for(int i=0; i<MAX_COUCHES; i++)
	{
		couches[i].reinitialiser();
	}
	string active = "active";
	couches[0].changerEtat(active);
	return true;
	
}

bool Canevas::activerCouche(int index)
{
	string inactive = "inactive";
	if (index<0)
	{
		return false;
	}
	if (index>MAX_COUCHES-1)
	{
		return false;
	}
	for(int i=0; i<MAX_COUCHES; i++)
	{
		if(couches[i].getEtat() == 2)
		{
			couches[i].changerEtat(inactive);
		}
	}
	
	
	string active = "active";
	couches[index].changerEtat(active);

   	return true;
   	
   	
}
void Canevas::reinitialiserCouche(int index)
{
	couches[index].reinitialiser();
}



bool Canevas::ajouterForme(Forme *p_forme)
{
	for(int i=0; i<MAX_COUCHES; i++)
	{
		couches[i].ajoutForme(p_forme);
	}
   	return true;
}

bool Canevas::retirerForme(int index)
{
	for(int i=0; i<MAX_COUCHES;i++)
	{
		if (couches[i].getEtat() == 2)
		{
			couches[i].retraitForme(index);
		}
	}
   	return true;
}

double Canevas::aire()
{
	
	double aireCanevas = 0;
	for (int i=0; i<MAX_COUCHES; i++)
	{
		if(couches[i].isEmpty() == false)
		{
			aireCanevas += couches[i].aireTotale();
			//cout<<"Aire couche "<<i<<" : "<<couches[i].aireTotale()<<endl;
		}
		else
		{
			//cout<<"Aire couche "<<i<<" : 0 "<<endl;
		}
	}
		
   	return aireCanevas;
}

bool Canevas::translater(int deltaX, int deltaY)
{
	for (int i=0; i<MAX_COUCHES; i++)
	{
		couches[i].translaterCouche(deltaX, deltaY);
		
	}
	
   	return true;
}

void Canevas::afficher(ostream & s)
{
	for (int i=0; i<MAX_COUCHES; i++)
	{
		if(couches[i].isEmpty())
		{
			cout << "----- Couche "<< i<<endl;
			cout << "Couche initialisee" << endl;
		}
		else
		{
			cout << "----- Couche "<< i<<endl;
			couches[i].afficherCouche(cout);
		}
	}
}
	
		
		
		
		
		
		
		
		
		
		
		


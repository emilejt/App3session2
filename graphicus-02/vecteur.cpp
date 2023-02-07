#include "vecteur.h"

Vecteur::Vecteur(int laCapacite)
{
	capacite = laCapacite;
	taille = 0;
	tableau = new Forme*[capacite];
}

Vecteur::~Vecteur()
{}

int Vecteur::getTaille()
{
	return taille;
}

int Vecteur::getCapacite()
{
	return capacite;
}

bool Vecteur::ajoutFin(Forme* pForme)
{
	if (taille < capacite)
	{
		tableau[taille] = pForme;
		taille++;
		return true;
	}
	else
	{
		capacite = capacite * 2;
		Forme** tableaub = new Forme*[capacite];
		for (int a=0; a < capacite/2; a++)
		{
			tableaub[a] = tableau[a];
		}
		delete[] tableau;
		tableau = tableaub;
		tableau[taille] = pForme;
		taille++;
		
		return true;
	}
	return false;
}

bool Vecteur::isEmpty()
{
	if(taille == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
	
void Vecteur::clearVecteur()
{
	delete[] tableau;
	capacite = CAPACITE_INITIALE;
	 tableau = new Forme*[capacite];
	taille = 0;
}

Forme* Vecteur::retirerForme(int index)
{
	Forme* pForme;
	if(index > taille)
	{
		return pForme = NULL;
	}
	else
	{
		pForme = tableau[index];
		for (int a = index; a<taille-1; a++)
		{
			tableau[a] = tableau[a+1];
		}
		taille--;
		/*if(taille <= capacite/2)
		{
			capacite = capacite/2;
		}*/
		return pForme;
	}
}

Forme* Vecteur::getForme(int index)
{
	Forme* pForme;
	if(index > taille)
	{
		return pForme = NULL;
	}
	else
	{
		pForme = tableau[index];
		return pForme;
	}
}
void Vecteur::afficherForme(ostream & s)
{
	for(int a=0; a<taille; a++)
	{
		tableau[a]->afficher(cout);
	}
}
































		
		
		
		
		
		
		

#include "vecteur.h"

Vecteur::Vecteur(int laCapacite)
{
	capacite=laCapacite;
	taille=0;
	tableau = new Forme*[capacite];
}

Vecteur::~Vecteur()
{}

int Vecteur::getCapacite()
{
	return capacite;
}

int Vecteur::getTaille()
{
	return taille;
}

bool Vecteur::ajoutFin(Forme* pForme)
{
	if (taille<capacite)
	{
	tableau[taille]=pForme;
	taille++;
	return true;
	}
	else
	{
		Forme** tableaub= new Forme*[capacite*2];
		for (int a=0; a<taille;a++)
		{
			tableaub[a]=tableau[a];
		}
		tableaub[taille]=pForme;
		delete [] tableau;
		tableau=tableaub;
		taille++;
		capacite=capacite*2;
		return true;
	}
	return false;
}

void Vecteur::clearVecteur()
{
	delete tableau;
	capacite = CAPACITE_INITIALE;
	Forme** tableau = new Forme*[capacite];
	taille=0;
}

bool Vecteur::isEmpty()
{
	if (taille==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Forme * Vecteur::retirerForme(int index)
{
	Forme *pForme;
	if (index>taille)
	{
		return pForme = NULL;
	}
	else
	{
		pForme=tableau[index];
		int a;
		for(a=index;a<taille-1;a++)
		{
			tableau[a]=tableau[a+1];
		}
		taille--;
		if (taille<=capacite/2)
		{
			capacite=capacite/2;
		}
		return pForme;
	}
}

Forme * Vecteur::getForme(int index)
{
	Forme* pForme;
	if(index>taille)
	{
		return pForme = NULL;
	}
	else
	{
		pForme=tableau[index];
		return pForme;
	}
}

void Vecteur::afficherForme(ostream & s)
{
	for (int a=0;a<taille;a++)
	{
		tableau[a]->afficher(cout);
	}
}

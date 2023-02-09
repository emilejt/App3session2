/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/
#include "Canevas.h"

Canevas::Canevas()
{
	string active = "active";
	indexactif = 0;
	
}

Canevas::~Canevas()
{
}

void Canevas::reinitialiserCanevas()
{
	vectcan.clearVecteur();
	
}

/*bool Canevas::activerCouche(int index)
{
	string inactive = "inactive";
	if (index<0)
	{
		return false;
	}
	if (index>MAX_COUCHES)
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
*/
void Canevas::afficher(ostream & s)
{
	for (int i=0; i<vectcan.getTaille(); i++)
	{
		if(vectcan[i].isEmpty())
		{
			cout << "----- Couche "<< i<<endl;
			cout << "Couche initialisee" << endl;
		}
		else
		{
			cout << "----- Couche "<< i<<endl;
			vectcan[i].afficherCouche(cout);
		}
	}
}
	
		
void Canevas::coucheAjouter()
{
	Couche couche;
	vectcan += couche;
	string initialise = "initialise";
	couche.changerEtat(initialise);
}

void Canevas::couchePremiere()
{
	string active = "active";
	string inactive = "inactive";
	if (vectcan[indexactif].getEtat() == 4)
	{
		vectcan[indexactif].changerEtat(active);
		return;
	}

	vectcan[indexactif].changerEtat(inactive);
	indexactif = 0;
	vectcan[indexactif].changerEtat(active);

	if (vectcan.getindexcourant() > 0)
	{
		for (int i = vectcan.getindexcourant(); i = 0; i--) {
			--vectcan;
		}
	}


}
void Canevas::coucheCacher()
{
	string cache = "cache";
	vectcan[indexactif].changerEtat(cache);
}
		
void Canevas::coucheSuivante()
{

	string inactive = "inactive";
	string active = "active";
	if (vectcan[indexactif].getEtat() == 4)
	{
		indexactif++;
		vectcan[indexactif].changerEtat(active);
		return;
	}
	vectcan[indexactif].changerEtat(inactive);
	indexactif++;
	vectcan[indexactif].changerEtat(active);

	if (vectcan.getindexcourant() > 0)
	{
		for (int i = vectcan.getindexcourant(); i = 0; i--) {
			--vectcan;
		}
	}
}
		
void Canevas::couchePrecedente()
{
	string inactive = "inactive";
	string active = "active";
	if (vectcan[indexactif].getEtat() == 4)
	{
		indexactif--;
		vectcan[indexactif].changerEtat(active);
		return;
	}
	vectcan[indexactif].changerEtat(inactive);
	indexactif--;
	vectcan[indexactif].changerEtat(active);

	if (vectcan.getindexcourant() > 0)
	{
		for (int i = vectcan.getindexcourant(); i = 0; i--) {
			--vectcan;
		}
	}
}


		
void Canevas::coucheDerniere()
{
	string inactive = "inactive";
	string active = "active";
	vectcan[indexactif].changerEtat(inactive);
	indexactif = vectcan.getTaille()-1;
	vectcan[indexactif].changerEtat(active);
}

void Canevas::ajouterCercle(int x, int y, int rayon)
{
	Forme* pCercle = new Cercle(x, y, rayon);
	vectcan[indexactif].ajoutForme(pCercle);
}

void Canevas::ajouterRectangle(int x, int y, int longueur, int largeur)
{
	Forme* pRectangle = new Rectangle(x, y, longueur, largeur);
	vectcan[indexactif].ajoutForme(pRectangle);
}

void Canevas::ajouterCarre(int x, int y, int cote)
{
	Forme* pCarre = new Carre(x, y, cote);
	vectcan[indexactif].ajoutForme(pCarre);
}

void Canevas::formePremiere()
{
	if (vectcan.getindexcourant() > 0)
	{
		for (int i = vectcan.getindexcourant(); i > 0; i--) {
			--vectcan;
		}
	}
}

void Canevas::formePrecedente()
{
	if (vectcan.getindexcourant() == 0)
	{
		return;
	}
	--vectcan;
}

void Canevas::formeSuivante()
{
	if (vectcan.getindexcourant() == vectcan[indexactif].getTailleCouche())
	{
		return;
	}
	++vectcan;

}

void Canevas::formeDerniere()
{
	if (vectcan.getindexcourant() < vectcan[indexactif].getTailleCouche())
	{
		for (int i = vectcan.getindexcourant(); i < vectcan[indexactif].getTailleCouche(); i++) {
			++vectcan;
		}
	}
}

void Canevas::coucheTranslater(int deltaX, int deltaY)
{
	
	vectcan[indexactif].translaterCouche(deltaX,deltaY);
	
}

void Canevas::coucheRetirer()
{
	
	vectcan.retireritem(indexactif);
}

void Canevas::retirerForme()
{
	vectcan[indexactif].retraitForme(vectcan.getindexcourant());
}
int Canevas::getTailleCanevas() const
{
	return vectcan.getTaille();
}

string Canevas::etatCoucheString(int index) const
{
	if (vectcan[index].getEtat() == 1)
	{
		return "i";
	}
	else if (vectcan[index].getEtat() == 2)
	{
		return "a";
	}
	else if (vectcan[index].getEtat() == 3)
	{
		return "x";
	}
	else if (vectcan[index].getEtat() == 4)
	{
		return "c";
	}
}

ostringstream& operator <<(ostringstream& str,const Canevas& can)
{
	for (int i = 0; i < can.getTailleCanevas(); i++)
	{
		str << "L " <<can.etatCoucheString(i)<< endl;
		for (int j = 0; j < can.vectcan[i].getTailleCouche(); j++)
		{
			str << can.vectcan[i][j]->affichage() << endl;
		}
	}
	return str;
}


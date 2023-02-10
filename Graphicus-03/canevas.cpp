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
	indexActif = -1;
}

Canevas::~Canevas()
{
}

void Canevas::coucheAjouter() {
	
	Couche couche;
	vectcanevas += couche;
	string initialise = "initialise";
	couche.changerEtat(initialise);
	return;
}

void Canevas::reinitialiserCanevas()
{
	vectcanevas.clearVecteur();
}

void Canevas::coucheCache()
{
	string cachee = "cachee";
	vectcanevas[indexActif].changerEtat(cachee);
}

void Canevas::couchePremiere()
{
	string active = "active";
	string inactive = "inactive";
	if (vectcanevas[indexActif].getEtat() == 4)
	{
		indexActif = 0;
		vectcanevas[indexActif].changerEtat(active);
		return;
	}
	vectcanevas[indexActif].changerEtat(inactive);
	indexActif = 0;
	vectcanevas[indexActif].changerEtat(active);

	if (vectcanevas.getindexcourant() > 0)
	{
		for (int i = vectcanevas.getindexcourant(); i >= 0; i--)
		{
			--vectcanevas;
		}
	}
}

void Canevas::coucheSuivante()
{
	if (indexActif == vectcanevas.getTaille()-1)
	{
		return;
	}
	string active = "active";
	string inactive = "inactive";
		if (vectcanevas[indexActif].getEtat() == 4)
		{
			indexActif++;
			vectcanevas[indexActif].changerEtat(active);
			return;
		}
	vectcanevas[indexActif].changerEtat(inactive);
	
	indexActif++;
	vectcanevas[indexActif].changerEtat(active);

	if (vectcanevas.getindexcourant() > 0)
	{
		for (int i = vectcanevas.getindexcourant(); i > 0; i--)
		{
			--vectcanevas;
		}
	}

}

void Canevas::couchePrecedente()
{
	string inactive = "inactive";
	string active = "active";
	if (vectcanevas[indexActif].getEtat() == 4)
	{
		indexActif--;
		vectcanevas[indexActif].changerEtat(active);
		return;
	}
	vectcanevas[indexActif].changerEtat(inactive);
	indexActif--;
	vectcanevas[indexActif].changerEtat(active);

	if (vectcanevas.getindexcourant() > 0)
	{
		for (int i = vectcanevas.getindexcourant(); i >= 0; i--)
		{
			--vectcanevas;
		}
	}
}

void Canevas::coucheDerniere()
{
	string inactive = "inactive";
	vectcanevas[indexActif].changerEtat(inactive);
	string active = "active";
	indexActif = vectcanevas.getTaille()-1;
	vectcanevas[indexActif].changerEtat(active);

	if (vectcanevas.getindexcourant() > 0)
	{
		for (int i = vectcanevas.getindexcourant(); i >= 0; i--)
		{
			--vectcanevas;
		}
	}
}

void Canevas::ajouterCercle(int x, int y, int rayon)
{
	Forme* pCercle = new Cercle(x, y, rayon);
	vectcanevas[indexActif].ajoutForme(pCercle);
	return;
} 

void Canevas::ajouterRectangle(int x, int y, int longueur, int largeur)
{
	Forme* pRectangle = new Rectangle(x, y, longueur, largeur);
	vectcanevas[indexActif].ajoutForme(pRectangle);
	return;
}

void Canevas::ajouterCarre(int x, int y, int cote)
{
	Forme* pCarre = new Carre(x, y, cote);
	vectcanevas[indexActif].ajoutForme(pCarre);
	return;
}
void Canevas::formePremiere()
{
	if (vectcanevas.getindexcourant() > 0)
	{
		vectcanevas.resetindexcourant();
	}
	return;
}
void Canevas::formePrecedente()
{
	if (vectcanevas.getindexcourant() == 0)
	{
		return;
	}
	--vectcanevas;
}

void Canevas::formeSuivante()
{
	if (vectcanevas.getindexcourant() >= vectcanevas[indexActif].getTailleCouche()-1)
	{
		return;
	}
	++vectcanevas;
}

void Canevas::formeDerniere()
{
	for (int i = 0; i < vectcanevas[indexActif].getTailleCouche()-1; i++)
	{
		++vectcanevas;
	}
}

void Canevas::coucheTranslater(int deltaX, int deltaY)
{
	vectcanevas[indexActif].translaterCouche(deltaX, deltaY);
	return;
}

void Canevas::retirerForme()
{
	vectcanevas[indexActif].retraitForme(vectcanevas.getindexcourant());
	
}

void Canevas::coucheRetirer()
{
	if (vectcanevas.getTaille() == 0)
	{
		return;
	}
	if (indexActif < 0) {
		return;
	}
	vectcanevas[indexActif].effacerCouche();
	vectcanevas.diminuerTaille();
}

int Canevas::getTailleCanevas() 
{
	return vectcanevas.getTaille();
}

string Canevas::etatCoucheString(int index) 
{
	if (vectcanevas[index].getEtat() == 1)
	{
		return "i";
	}
	else if (vectcanevas[index].getEtat() == 2)
	{
		return "a";
	}
	else if (vectcanevas[index].getEtat() == 3)
	{
		return "x";
	}
	else if (vectcanevas[index].getEtat() == 4)
	{
		return "c";
	}
}

ostringstream& operator <<(ostringstream& str,  Canevas& can)
{
	for (int i = 0; i < can.getTailleCanevas(); i++)
	{
		str << "L " << can.etatCoucheString(i) << endl;
		for (int j = 0; j < can.vectcanevas[i].getTailleCouche(); j++)
		{
			str << can.vectcanevas[i][j]->affichage() << endl;
		}
	}
	return str;
}

void Canevas::updateInfo(Informations& info) {
	info.nbCouches = 0;      // Nombre total de couches
	info.nbFormesCanevas = 0; // Nombre total de formes
	 info.coucheActive = -1;    // la couche active, si < 0, pas de couche active
	 info.aireCanevas = 0;  // Aire totale
	// Pour la couche active du canevas, s'il y en a une
	 info.nbFormesCouche = 0;  // Nombre de formes de la couche
	 // État de la couche en format libre
	 info.aireCouche = 0;   // Aire totale de la couche
	 info.formeActive = 0;    // la forme active, si < 0, pas de forme active
	// Pour la forme active de la couche active, s'il y en a une
	 info.coordX = 0, info.coordY = 0;  // Coordonnées de la forme
	 info.aireForme = 0;  // Aire de la forme
	 // Informations format libre: rayon, etc.
	
	
	
	
	
	
	info.nbCouches = vectcanevas.getTaille();
	info.nbFormesCanevas = 0;
	info.aireCanevas = 0;
	for (int i = 0; i <= vectcanevas.getTaille(); i++)
	{
		info.aireCanevas += vectcanevas[i].aireTotale();
		for (int j = 0; j < vectcanevas[i].getTailleCouche(); j++)
		{
			info.nbFormesCanevas++;	
		}
	}
	if (indexActif >= 0) {

		info.coucheActive = indexActif+1;
	}

	
	if (etatCoucheString(indexActif) == "i")
	{
		info.etatCouche[0] = 'i';
	}
	if (etatCoucheString(indexActif) == "a")
	{
		info.etatCouche[0] = 'a';
	}
	if (etatCoucheString(indexActif) == "i")
	{
		info.etatCouche[0] = 'x';
	}
	if (etatCoucheString(indexActif) == "c")
	{
		info.etatCouche[0] = 'c';
	}

	info.nbFormesCouche = vectcanevas[indexActif].getTailleCouche();
	if (indexActif >= 0) {
		if (vectcanevas[indexActif].getTailleCouche() > 0)
		{
			info.aireCouche = vectcanevas[indexActif].aireTotale();
		}
	}

	





	if (vectcanevas[indexActif].getTailleCouche() == 0)
	{
		info.formeActive = -1;
	}
	else {
		info.formeActive = vectcanevas.getindexcourant()+1;
	}
	//if (indexActif > 0)
	//{
	//	if (vectcanevas.getindexcourant() > 0)
	//	{
	//		info.coordX = vectcanevas[indexActif][vectcanevas.getindexcourant()]->ancragex().x;
	//		info.coordY = vectcanevas[indexActif][vectcanevas.getindexcourant()]->ancragey().y;
	//	}
	//}


	//if (indexActif > 0)
	//{
	//	if (vectcanevas.getindexcourant() >= 0)
	//	{

	//		info.aireForme = vectcanevas[indexActif][vectcanevas.getindexcourant()]->aire();
	//	}
	//}
}

void Canevas::inversePile(bool mode) {
	inversionPile = mode;
}



//
//bool Canevas::activerCouche(int index)
//{
//	string inactive = "inactive";
//	if (index<0)
//	{
//		return false;
//	}
//	if (index>MAX_COUCHES-1)
//	{
//		return false;
//	}
//	for(int i=0; i<MAX_COUCHES; i++)
//	{
//		if(couches[i].getEtat() == 2)
//		{
//			couches[i].changerEtat(inactive);
//		}
//	}
//	
//	
//	string active = "active";
//	couches[index].changerEtat(active);
//
//   	return true;
//   	
//   	
//}
//void Canevas::reinitialiserCouche(int index)
//{
//	couches[index].reinitialiser();
//}
//
//
//
//bool Canevas::ajouterForme(Forme *p_forme)
//{
//	for (int i = 0; i < MAX_COUCHES; i++)
//	{
//		v += p_forme;
//	}
//   	return true;
//}
//
//bool Canevas::retirerForme(int index)
//{
//	for(int i=0; i<MAX_COUCHES;i++)
//	{
//		if (couches[i].getEtat() == 2)
//		{
//			couches[i].retraitForme(index);
//		}
//	}
//   	return true;
//}
//
double Canevas::aire()
{
	
	double aireCanevas = 0;
	for (int i=0; i<MAX_COUCHES; i++)
	{
		if(vectcanevas[i].isEmpty() == false)
		{
			aireCanevas += vectcanevas[i].aireTotale();
			//cout<<"Aire couche "<<i<<" : "<<couches[i].aireTotale()<<endl;
		}
		else
		{
			//cout<<"Aire couche "<<i<<" : 0 "<<endl;
		}
	}
		
   	return aireCanevas;
}
//
//bool Canevas::translater(int deltaX, int deltaY)
//{
//	for (int i=0; i<MAX_COUCHES; i++)
//	{
//		couches[i].translaterCouche(deltaX, deltaY);
//		
//	}
//	
//   	return true;
//}
//
//void Canevas::afficher(ostream & s)
//{
//	for (int i=0; i<MAX_COUCHES; i++)
//	{
//		if(couches[i].isEmpty())
//		{
//			cout << "----- Couche "<< i<<endl;
//			cout << "Couche initialisee" << endl;
//		}
//		else
//		{
//			cout << "----- Couche "<< i<<endl;
//			couches[i].afficherCouche(cout);
//		}
//	}
//}
	
		
		
		
		
		
		
		
		
		
		
		


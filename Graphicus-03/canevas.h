/********
 * Fichier: canevas.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration de la classe Canevas. La classe gere un
 *    tableau de couches en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef DESSIN_H
#define DESSIN_H

#include <iostream>
#include <istream>
#include <string>
#include "forme.h"
#include "couche.h"
#include "cercle.h"
#include "rectangle.h"
#include "carre.h"
#include "vecteur.h"
#include "graphicusGUI.h"
#include "coordonnee.h"




const int MAX_COUCHES = 5;

using namespace std;

class Canevas
{
public:
   Canevas();
   ~Canevas();
   void coucheAjouter();
   
   void reinitialiserCanevas();
   void coucheCache();
   void couchePremiere();
   void coucheSuivante();
   void couchePrecedente();
   void coucheDerniere();
   void ajouterCercle(int x, int y, int rayon);
   void ajouterRectangle(int x, int y, int longueur, int largeur);
   void ajouterCarre(int x, int y, int cote);
   void formePremiere();
   void formePrecedente();
   void formeSuivante();
   void formeDerniere();
   void coucheTranslater(int deltaX, int deltaY);
   void retirerForme();
   void coucheRetirer();
   int getTailleCanevas();
   string etatCoucheString(int index);
   friend ostringstream& operator <<(ostringstream& str,  Canevas& can);
   void updateInfo(Informations& info);
   double aire();
   void inversePile(bool mode);


   /*friend ostream& operator << (ostream& cout, Canevas& caneva) {
	   if (caneva.inversionPile) {
		   for (int i = (caneva.vectcanevas.getTaille() - 1); i >= 0; i--) {
			   cout << caneva.vectcanevas<<endl;
		   }
	   }
	   else {
		   for (int i = 0; i < caneva.vectcanevas.getTaille(); i++) {
			   cout << caneva.vectcanevas<<endl;
		   }
	   }

	   return cout;
   }*/

   Vecteur<Couche> vectcanevas;
   
  /* bool activerCouche(int index);
   
   
   bool ajouterForme(Forme *p_forme);
   bool retirerForme(int index);
   
   double aire();
   bool translater(int deltaX, int deltaY);
   void afficher(ostream & s);
   void reinitialiserCouche(int index);*/

private:
	bool inversionPile;
    int indexActif = -1;
};

#endif

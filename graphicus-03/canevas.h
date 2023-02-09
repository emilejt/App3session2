/********
 * Fichier: canevas.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration de la classe Canevas. La classe gere un
 *    tableau de couches en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef CANEVAS_H
#define CANEVAS_H

#include <iostream>
#include "forme.h"
#include "couche.h"
#include "vecteur.h"
#include "cercle.h"
#include "rectangle.h"
#include "carre.h"

const int MAX_COUCHES = 5;

using namespace std;

class Canevas
{
public:
   Canevas();
   ~Canevas();
   
   void reinitialiserCanevas();
   
   bool activerCouche(int index);
   
   
   bool ajouterForme(Forme *p_forme);
   bool retirerForme(int index);
   
   void coucheCacher();
   double aire();
   bool translater(int deltaX, int deltaY);
   void afficher(ostream & s);
   void reinitialiserCouche(int index);
   void coucheAjouter();
   void coucheSuivante();
   void couchePrecedente();
   void couchePremiere();
   void coucheDerniere();
   void ajouterCercle(int x, int y, int rayon);
   void ajouterRectangle(int x, int y, int longueur, int largeur);
   void ajouterCarre(int x, int y, int cote);
   void formePremiere();
   void formePrecedente();
   void formeSuivante();
   void formeDerniere();
   void coucheTranslater(int deltaX, int deltaY);
   void coucheRetirer();
   void retirerForme();
private:
    Vecteur<Couche> vectcan;
    int indexactif;
};

#endif

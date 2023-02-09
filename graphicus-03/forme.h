/********
 * Fichier: forme.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration des classes de formes geometriques. La
 *    classe Forme ne doit pas etre modifiee. Ce fichier fait partie de
 *    la distribution de Graphicus.
********/

#ifndef FORME_H
#define FORME_H

#include <iostream>
#include "coordonnee.h"
#include<string>
using namespace std;

class Forme
{
public:
  Forme(int x1 = 0, int y1 = 0); // constructeur de forme origine peut etre
  virtual ~Forme(); // destructeur de forme
  void translater(int deltaX, int deltaY);
  Coordonnee getAncrage();
  void setAncrage(Coordonnee c);
  virtual double aire() = 0; //fonction pour l'aire 
  virtual void afficher(ostream & s) = 0; 
  virtual string affichage() const = 0;
protected:
	Coordonnee ancrage;
};
#endif

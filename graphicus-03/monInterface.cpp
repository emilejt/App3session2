/********
* Fichier: monInterface.cpp
* Auteurs: C.-A. Brunet
* Date: 21 décembre 2021 (création)
* Description: Voir fichier d'entête pour informations.
*
* Copyright 2022 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#include <random>
#include <sstream>
#include "monInterface.h"

using namespace std;

MonInterface::MonInterface(const char* theName) : GraphicusGUI(theName)
{
	reinitialiserCanevas();
	clearInformations();
}

void MonInterface::reinitialiserCanevas()
{
	ostringstream os;
	random_device r;
	default_random_engine generator(r());
	uniform_int_distribution<int> coor(0, 300), dim(20, 100);

	// On s'amuse à générer aléatoirement un canevas en format texte à chaque
	// fois que la commande de réinitialisation de canevas est lancée. 
	os << "L x" << endl;
	os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "L a" << endl;
	os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "L x" << endl;
	os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "L x" << endl;
	os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
	os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	// Ensuite, on l'affiche dans Graphicus
	dessiner(os.str().c_str());
}


//Ajouter et retirer
void MonInterface::coucheAjouter()
{
	ostringstream os;
	can1.coucheAjouter();
	os << can1;
	dessiner(os.str().c_str());

}
void MonInterface::coucheRetirer()
{
	ostringstream os;
	can1.coucheRetirer();
	os << can1;
	dessiner(os.str().c_str());
}
void MonInterface::coucheCacher()
{
	ostringstream os;
	can1.coucheCacher();
	os << can1;
	dessiner(os.str().c_str());
}

void MonInterface::ajouterCercle(int x,int y,int rayon)
{
	ostringstream os;
	can1.ajouterCercle(x, y, rayon);
	os << can1;
	dessiner(os.str().c_str());
}

void MonInterface::ajouterRectangle(int x, int y, int longueur, int largeur)
{
	ostringstream os;
	can1.ajouterRectangle(x, y, longueur, largeur);
	os << can1;
	dessiner(os.str().c_str());

}
void MonInterface::ajouterCarre(int x, int y, int cote)
{
	ostringstream os;
	can1.ajouterCarre(x, y, cote);
	os << can1;
	dessiner(os.str().c_str());

}
void MonInterface::retirerForme()
{
	ostringstream os;
	can1.retirerForme();
	os << can1;
	dessiner(os.str().c_str());
}
//Deplacement
void MonInterface::couchePremiere()
{
	can1.couchePremiere();
}
void MonInterface::couchePrecedente()
{
	can1.couchePrecedente();
}

void MonInterface::coucheSuivante()
{
	can1.coucheSuivante();
}

void MonInterface::coucheDerniere()
{
	can1.coucheDerniere();
}

void MonInterface::formePremiere()
{
	can1.formePremiere();
}
void MonInterface::formePrecedente()
{
	can1.formePrecedente();
}
void MonInterface::formeSuivante()
{
	can1.formeSuivante();
}
void MonInterface::formeDerniere()
{
	can1.formeDerniere();
}

/********
* Fichier: monInterface.h
* Auteurs: C.-A. Brunet
* Date: 21 décembre 2021 (création)
* Description: La classe MonInterface teste l'interface usager GraphicusGUI.
*
* Copyright 2022 Département de génie électrique et génie informatique
*                Université de Sherbrooke
********/

#ifndef MONINTERFACE_H
#define MONINTERFACE_H

#include "graphicusGUI.h"
#include "canevas.h"
class MonInterface : public GraphicusGUI
{
public:
	MonInterface(const char* theName = nullptr);
	virtual void reinitialiserCanevas();
	void coucheAjouter();
	void coucheRetirer();
	void coucheCacher();
	void ajouterCercle(int x, int y, int rayon);
	void ajouterRectangle(int x, int y, int longueur, int largeur);
	void ajouterCarre(int x, int y, int cote);
	void couchePremiere();
	void couchePrecedente();
	void coucheSuivante();
	void coucheDerniere();
	void formePremiere();
	void formePrecedente();
	void formeSuivante();
	void formeDerniere();
	void retirerForme();
	bool ouvrirFichier(const char* fichier);
	void modePile(bool mode);
	void coucheTranslater(int deltaX, int deltaY);
	/*bool sauvegarderFichier(const char* c_fileName);*/
private:
	Canevas can1;

	Informations info;
};

#endif // MONINTERFACE_H
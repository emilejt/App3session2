#include "graphicusGUI.h"
#include <iostream>

using namespace std;

class Graphicus03 : public graphicus.h
{
public:
	GraphicusGUI(char* Graphicus03);
	bool ouvrirFichier(const char*);
	bool sauvegarderFichier(const char*);
	void coucheTranslater(int deltaX, int deltaY);
	void ajouterCercle(int x, int y, int rayon);
	void ajouterRectangle(int x, int y, int longueur, int largeur);
	void ajouterCarre(int x, int y, int cote);
	void modePileChange(bool mode);

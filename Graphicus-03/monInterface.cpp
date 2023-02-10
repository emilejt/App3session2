

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
#include "vecteur.h"
#include <queue>

using namespace std;

MonInterface::MonInterface(const char* theName) : GraphicusGUI(theName)
{
	//reinitialiserCanevas();
	clearInformations();
	can1.updateInfo(info);
	setInformations(info);

}

bool MonInterface::ouvrirFichier(const char* fichier)
{
	ostringstream os;
	ifstream fichier1;
	fichier1.open(fichier, ios_base::in);

	if (fichier1.is_open())
	{
		queue<int> etatcouche;
		int indexActif = 0;
		// on commence la lecture
		while (fichier1.good()) {

			string fBuffer;
			fichier1 >> fBuffer;

			switch (fBuffer[0])
			{
			case 'L':
				can1.coucheAjouter();
				os << can1;
				dessiner(os.str().c_str());
				fichier1 >> fBuffer;
				switch (fBuffer[0]) {
				case 'a':
					etatcouche.push(2);
					indexActif = etatcouche.size();
					break;
				case 'x':
					etatcouche.push(3);
					break;
				case 'c':
					etatcouche.push(4);
					break;
				case 'i':
					etatcouche.push(1);
					break;
				default:
					cout << "erreur" << endl;
					return false;
				}
				break;
			case 'R':
				int shapeInfo[4];
				for (int i = 0; i < 4; i++) {
					fichier1 >> shapeInfo[i];
				}
				can1.ajouterRectangle(shapeInfo[0], shapeInfo[1], shapeInfo[2], shapeInfo[3]);
				os << can1;
				dessiner(os.str().c_str());
				break;
			case 'K':
				for (int i = 0; i < 3; i++) {
					fichier1 >> shapeInfo[i];
				}
				can1.ajouterCarre(shapeInfo[0], shapeInfo[1], shapeInfo[2]);
				os << can1;
				dessiner(os.str().c_str());
				break;
			case 'C':
				for (int i = 0; i < 3; i++) {
					fichier1 >> shapeInfo[i];
				}
				can1.ajouterCercle(shapeInfo[0], shapeInfo[1], shapeInfo[2]);
				os << can1;
				dessiner(os.str().c_str());
				break;
			case ' ':
			case '\n':
			case '\0':
				cout << "WARNING: empty line in file\n";
				break;
			default:
				cout << "erreur";
				return false;
			}
		}


		std::cout << "Finished reading file, will close now" << endl;
		fichier1.close();

		//couchePremiere();
		//coucheRetirer(); // enlève la première couche qui est là par défault

		//for (int i = 0; i < (indexActif - 1); i++) { // move to the active layer
		//	coucheSuivante();
		//}

		//int tempNbCouches = etatcouche.size();
		//for (int i = 0; i < tempNbCouches; i++) // set layers to their proper state
		//{
		//	can1.vectcanevas[i].changerEtat((const int)etatcouche.front());
		//	etatcouche.pop();
		//}


		


	return true;
	}
}

//
//bool MonInterface::sauvegarderFichier(const char* c_fileName) 
//{	ofstream outFile;
//	outFile.open(c_fileName);
//	if (outFile.is_open()) {
//		outFile << outFile;
//	else return false;
//
//}

void MonInterface::reinitialiserCanevas()
{
	can1.reinitialiserCanevas();
	can1.updateInfo(info);
	setInformations(info);
	
	//ostringstream os;
	//random_device r;
	//default_random_engine generator(r());
	//uniform_int_distribution<int> coor(0, 300), dim(20, 100);

	//// On s'amuse à générer aléatoirement un canevas en format texte à chaque
	//// fois que la commande de réinitialisation de canevas est lancée. 
	//os << "L x" << endl;
	//os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	//os << "L a" << endl;
	//os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	//os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	//os << "L x" << endl;
	//os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
	//os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	//os << "L x" << endl;
	//os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
	//os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;

	//os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	//// Ensuite, on l'affiche dans Graphicus
	//dessiner(os.str().c_str());
}


//Ajouter et retirer
void MonInterface::coucheAjouter()
{
	
	ostringstream os;
	can1.coucheAjouter();
	can1.updateInfo(info);
	setInformations(info);
	os << can1;
	dessiner(os.str().c_str());

}
void MonInterface::coucheRetirer()
{
	
	ostringstream os;
	can1.coucheRetirer();
	can1.updateInfo(info);
	setInformations(info);
	os << can1;
	dessiner(os.str().c_str());
}
void MonInterface::coucheCacher()
{
	
	ostringstream os;
	can1.coucheCache();
	can1.updateInfo(info);
	setInformations(info);
	os << can1;
	dessiner(os.str().c_str());
}

void MonInterface::ajouterCercle(int x, int y, int rayon)
{

	ostringstream os;
	can1.ajouterCercle(x, y, rayon);
	can1.updateInfo(info);
	setInformations(info);
	os << can1;
	dessiner(os.str().c_str());
}

void MonInterface::ajouterRectangle(int x, int y, int longueur, int largeur)
{

	ostringstream os;
	can1.ajouterRectangle(x, y, longueur, largeur);
	can1.updateInfo(info);
	setInformations(info);
	os << can1;
	dessiner(os.str().c_str());

}
void MonInterface::ajouterCarre(int x, int y, int cote)
{

	ostringstream os;
	can1.ajouterCarre(x, y, cote);
	can1.updateInfo(info);
	setInformations(info);
	os << can1;
	dessiner(os.str().c_str());

}
void MonInterface::retirerForme()
{
	
	ostringstream os;
	can1.retirerForme();
	can1.updateInfo(info);
	setInformations(info);
	os << can1;
	dessiner(os.str().c_str());
}
//Deplacement
void MonInterface::couchePremiere()
{

	can1.couchePremiere();
	can1.updateInfo(info);
	setInformations(info);
}
void MonInterface::couchePrecedente()
{

	can1.couchePrecedente();
	can1.updateInfo(info);
	setInformations(info);
}

void MonInterface::coucheSuivante()
{

	can1.coucheSuivante();
	can1.updateInfo(info);
	setInformations(info);
}

void MonInterface::coucheDerniere(){

	can1.coucheDerniere();
	can1.updateInfo(info);
	setInformations(info);
}

void MonInterface::formePremiere()
{
	
	can1.formePremiere();
	can1.updateInfo(info);
	setInformations(info);
}
void MonInterface::formePrecedente()
{
	can1.formePrecedente();
	can1.updateInfo(info);
	setInformations(info);
}
void MonInterface::formeSuivante()
{
	can1.formeSuivante();
	can1.updateInfo(info);
	setInformations(info);
}
void MonInterface::formeDerniere()
{
	can1.formeDerniere();
	can1.updateInfo(info);
	setInformations(info);
}

void MonInterface::modePile(bool mode)
{
	can1.inversePile(mode);
	can1.updateInfo(info);
	setInformations(info);

}

void MonInterface::coucheTranslater(int deltaX, int deltaY)
{
	ostringstream os;
	can1.coucheTranslater(deltaX, deltaY);
	os << can1;
	dessiner(os.str().c_str());
}

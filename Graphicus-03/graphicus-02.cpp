/********
 * Fichier: graphicus-01.cpp
 * Auteurs: Raphael Barrette barr1306 - Emile Jacques-Tighe jace1402
 * Date: 08 janvier 2018 (creation)
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/
#include "tests.h"
#include <QApplication>
#include "monInterface.h"

using namespace std;

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	MonInterface gui("TestGraphicusGUI 1.0");
	
	return app.exec();



   /*Tests tests;
   
   tests.tests_application();
   tests.tests_unitaires_formes();
   tests.tests_unitaires_vecteur();
   tests.tests_unitaires_couche();
   tests.tests_unitaires_canevas();*/
   return 0;
}


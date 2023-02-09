/********
 * Fichier: graphicus-01.cpp
 * Auteurs: Raphael Barrette barr1306 - Emile Jacques-Tighe jace1402
 * Date: 08 janvier 2018 (creation)
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/
#include "tests.h"
#include "vecteur.h"
using namespace std;
#include <Qapplication>
#include "monInterface.h"
int main(int argc,char**argv)
{
   //Tests tests; 
   //tests.tests_application();
   //tests.tests_unitaires_formes();
  //tests.tests_unitaires_vecteur();
  // tests.tests_unitaires_couche();
  // tests.tests_unitaires_canevas();
	QApplication app(argc, argv);
	MonInterface Gui("test1");
   return app.exec();
}


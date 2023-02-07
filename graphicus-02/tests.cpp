/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests. 
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "tests.h"
#include "forme.h"
#include "cercle.h"
#include "rectangle.h"
#include "carre.h"
#include "vecteur.h"
#include "couche.h"


void Tests::tests_unitaires_formes()
{
   /*Cercle cercle1(0,0,3);
   cercle1.afficher(std::cout);
   Rectangle rectangle1(0,0,3,2);
   rectangle1.afficher(std::cout);
   Carre carre1(0,0,3);
   carre1.afficher(std::cout);*/
}

void Tests::tests_unitaires_vecteur()
{
    //Tests sur la classe Vecteur
   /*Vecteur vecteur1;
   Forme* pCercle = new Cercle(1,1,1);
   Forme* pCercle1 = new Cercle(2,2,2);
   //Forme* pCercle2 = new Cercle(3,3,3);
   //Forme* pCercle3 = new Cercle(4,4,4);
   //Forme* pRectangle = new Rectangle(1,1,1,1);
   //Forme* pCercle4 = new Cercle(5,5,5);
   //Forme* pCercle5 = new Cercle(6,6,6);
   vecteur1.ajoutFin(pCercle);
   vecteur1.ajoutFin(pCercle1);
   //vecteur1.ajoutFin(pCercle2);
   //vecteur1.ajoutFin(pCercle3);
   //vecteur1.ajoutFin(pRectangle);
   
   //vecteur1.ajoutFin(pCercle4);
   //vecteur1.ajoutFin(pCercle5);
   //vecteur1.retirerForme(0);
   vecteur1.clearVecteur();
   vecteur1.afficherForme(cout);
   cout<<"taille="<<vecteur1.getTaille()<<endl;
   cout<<"capacite="<<vecteur1.getCapacite()<<endl;*/
}

void Tests::tests_unitaires_couche()
{
   // Tests sur la classe Couche
   /*Couche couche1;
   string active = "active";
   couche1.changerEtat(active);
    Forme* pCercle = new Cercle(1,1,1);
   Forme* pCercle1 = new Cercle(2,2,2);
   Forme* pCercle2 = new Cercle(3,3,3);
   couche1.ajoutForme(pCercle);
   couche1.ajoutForme(pCercle1);
   couche1.ajoutForme(pCercle2);
   couche1.afficherCouche(cout);
   couche1.reinitialiser();
   couche1.afficherCouche(cout);
   //cout <<couche1.aireTotale()<<endl;
   cout << couche1.isEmpty() <<endl;*/
}

void Tests::tests_unitaires_canevas()
{
   // Tests sur la classe Canevas
   /*Canevas canevas1;
   Forme* pCercle = new Cercle(1,1,1);
   Forme* pCercle1 = new Cercle(2,2,2);
   Forme* pCercle2 = new Cercle(3,3,3);
   Forme* pCercle3 = new Cercle(4,4,4);
   Forme* pRectangle = new Rectangle(1,1,1,1);
   Forme* pCercle4 = new Cercle(5,5,5);
   Forme* pCercle5 = new Cercle(6,6,6);
   canevas1.ajouterForme(pCercle);
   canevas1.ajouterForme(pRectangle);
   canevas1.activerCouche(2);
   canevas1.ajouterForme(pCercle1);
   canevas1.activerCouche(4);
   canevas1.ajouterForme(pCercle4);
   canevas1.ajouterForme(pCercle5);
   canevas1.afficher(cout);
   cout <<canevas1.aire()<< endl;*/
   
   
   
   
}

void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   tests_unitaires_formes();
   tests_unitaires_vecteur();
   tests_unitaires_couche();
   tests_unitaires_canevas();
}

void Tests::tests_application()
{
   // Fait tous les tests applicatifs
   tests_application_cas_01();
   //tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
   cout << "TESTS APPLICATION (CAS 01)" << endl;
   cout<<endl; 
   Canevas canevas1;
   cout << "Etape 1 : Activation de la couche 1"<<endl;
   cout<<endl; 
   canevas1.activerCouche(1);
   cout<<"Etape 2 : Ajout des trois formes geometrique suivantes : "<<endl;
   cout<<"	-Un rectangle (x=0, y=0, largeur=2, hauteur=3)"<<endl;
   cout<<"	-Un carré (x=2, y=3, côté=4)"<<endl;
   cout<<"	-Un cercle (x=7, y=8, rayon=6)"<<endl;
   cout<<endl; 
   Forme* pRectangle = new Rectangle(0,0,2,3);
   Forme* pCarre = new Carre(2,3,4);
   Forme* pCercle = new Cercle(7,8,6);
   canevas1.ajouterForme(pRectangle);
   canevas1.ajouterForme(pCarre);
   canevas1.ajouterForme(pCercle);
   cout<<"Etape 3 : Activation de la couche 2"<<endl;
   cout<<endl; 
   canevas1.activerCouche(2);
   cout<<"Etape 4 : Ajout de la forme geometrique suivante :"<<endl;
   cout<<"	-Un rectangle (x=0, y=0, largeur=4, hauteur=5)"<<endl;
   cout<<endl; 
   Forme* pRectangle1 = new Rectangle(0,0,4,5);
   canevas1.ajouterForme(pRectangle1);
   cout<<"Etape 5 : Affichage du canevas"<<endl;
   cout<<endl; 
   canevas1.afficher(cout);
   cout<<endl; 
   cout<<"Etape 6 : Affichage de l'aire du canevas "<<canevas1.aire()<<endl;
   cout<<endl; 
   
   
   cout<<"Etape 7 : Activation de la couche 0 et ajout des trois formes geometrique suivante : "<<endl;
   
   cout<<"	-Un rectangle (x=0, y=0, largeur=1, hauteur=1)"<<endl;
   cout<<"	-Un carré (x=0, y=0, côté=1)"<<endl;
   cout<<"	-Un cercle (x=0, y=0, rayon=1)"<<endl;
   cout<<endl; 
   canevas1.activerCouche(0);
   Forme* pRectangle2 = new Rectangle(0,0,1,1);
   Forme* pCarre1 = new Carre(0,0,1);
   Forme* pCercle1 = new Cercle(0,0,1);
   canevas1.ajouterForme(pRectangle2);
   canevas1.ajouterForme(pCarre1);
   canevas1.ajouterForme(pCercle1);
   cout<<"Etape 8 : Activation et translation de la couche 1 selon : x=5 et y=5"<<endl;
   cout<<endl; 
   canevas1.activerCouche(1);
   canevas1.translater(5,5);
   cout<<"Etape 9 : Initialisation de la couche 2"<<endl;
   cout<<endl; 
   canevas1.reinitialiserCouche(2);
   cout<<"Etape 10 : Initialisation de la couche 3"<<endl;
   cout<<endl; 
   cout<<"Etape 11 : Initialisation de la couche 4"<<endl;
   cout<<endl; 
   cout<<"Etape 12 : Affichage du canevas"<<endl;
   cout<<endl; 
   canevas1.afficher(cout);
   cout<<endl; 
   cout<<"Etape 13 : Affichage de l'aire du canevas "<<canevas1.aire()<<endl;
   cout<<endl; 
   
   cout<<"Etape 14 : Retrait de la premiere forme de la couche 1"<<endl;
   cout<<endl; 
   canevas1.retirerForme(0);
   cout<<"Etape 15 : Affichage du canevas"<<endl;
   cout<<endl; 
   canevas1.afficher(cout);
   cout<<endl; 
   cout<<"Etape 16 : Affichage de l'aire du canevas "<<canevas1.aire()<<endl;
   cout<<endl; 
   
   cout<<"Etape 17 : Reinitialisation du canevas"<<endl;
   cout<<endl; 
   canevas1.reinitialiser();
   cout<<"Etape 18 : Affichage du canevas"<<endl;
   cout<<endl; 
   canevas1.afficher(cout);
   cout<<endl; 
   cout<<"Etape 19 : Affichage de l'aire du canevas "<<canevas1.aire()<<endl;
   
   
   
   
   
   
   
   // Il faut ajouter les operations realisant ce scenario de test.
}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;  
    // Il faut ajouter les operations realisant ce scenario de test.
}

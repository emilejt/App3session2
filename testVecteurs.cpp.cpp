// testVecteurs.cpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

class EnsembleDeNombres
{
public:
	EnsembleDeNombres(int laCapacite = 1)
	{
		capacite = laCapacite;
		taille = 0;
		tableau = new double[capacite];
	}

	~EnsembleDeNombres()
	{}

	void afficher() const
	{
		for (int a = 0; a < taille; a++)
		{
			cout << tableau[a] << endl;
		}
	}

	void ajoutFin(double N)
	{
		if (taille < capacite)
		{
			tableau[taille] = N;
			taille++;
		}
		else
		{
			capacite = capacite * 2;
			double* tableaub = new double[capacite];
			for (int a = 0; a < capacite / 2; a++)
			{
				tableaub[a] = tableau[a];
			}
			delete[] tableau;
			tableau = tableaub;
			tableau[taille] = N;
			taille++;
			
		}
	}

	int getCapacite()
	{
		return capacite;
	}

	void supprimerDebut()
	{
		for (int a = 0; a < taille; a++)
		{
			tableau[a] = tableau[a + 1];
		}
		taille--;
		cout << tableau[0] << endl;
	}
	 const double operator[] (int index) const  {
		 return tableau[index];
	}
	 double& operator[] (int index) {
		 return tableau[index];
	 }
	 void operator+= (double N) {
		 if (taille < capacite)
		 {
			 tableau[taille] = N;
			 taille++;
		 }
		 else
		 {
			 capacite = capacite * 2;
			 double* tableaub = new double[capacite];
			 for (int a = 0; a < capacite / 2; a++)
			 {
				 tableaub[a] = tableau[a];
			 }
			 delete[] tableau;
			 tableau = tableaub;
			 tableau[taille] = N;
			 taille++;

		 }
	 }
	 friend ostream& operator<<(ostream& os, const EnsembleDeNombres& v)
	 {
		 for (int a = 0; a < v.taille; a++)
		 {
			 os <<"index "<<a<<" : "<< v.tableau[a] << endl;
		 }
		 return os;
	 }

	 friend ofstream& operator <<(ofstream& fich, const EnsembleDeNombres& v)
	 {
		
		 for (int a = 0; a < v.taille; a++)
		 {
			 fich <<"index " << a << " : " << v.tableau[a] << endl;
		 }
		 
		 return fich;
		
	 }

	 friend ostringstream& operator <<(ostringstream& str, const EnsembleDeNombres& v)
	 {
		 for (int a = 0; a < v.taille; a++)
		 {
			 str << "index " << a << " : " << v.tableau[a] << endl;
		 }

		 return str;

	 }
	 friend void operator >>(istream& os,  EnsembleDeNombres& v)
	 {
		 double chiffre;
		 int verification = 0;
		 while (1) {
			 cout << "1 : nouveau chiffre  2 : fin" << endl;
			 cin >> verification;
			 if (verification == 1)
			 {
				 cout << "Entrer un chiffre : " << endl;
				 cin >> chiffre;
				 v += chiffre;
			 }
			 if (verification == 2)
			 {
				 break;
			 }
		 }
		 
		
	 }

	 friend void operator >>(ifstream& fich, EnsembleDeNombres& v)
	 {
		 double chiffre;
		 while (1) {
			 if (fich.eof())
			 {
				 break;
			 }
			 fich >> chiffre;
			 v += chiffre;
			 }
	 }
		 
	 
	


private:
	int taille;
	double* tableau;
	int capacite;
};

int main()
{
	ifstream fich;
	ofstream fich1;
	fich.open("cacain.txt");
	fich1.open("cacaout.txt");
	EnsembleDeNombres ensemble;
	/*ostringstream str;
	ofstream fich;
	fich.open("caca.txt");
	EnsembleDeNombres ensemble;
	ensemble.ajoutFin(0.1);
	ensemble.ajoutFin(1.0);
	ensemble.ajoutFin(2.0);
	ensemble.ajoutFin(0.1);
	ensemble.ajoutFin(1.0);
	ensemble.ajoutFin(2.0);
	cout << "kev est gay" << endl;
	ensemble.afficher();
	cout << "test operateur" << endl;
	cout << "-----------------" << endl;
	cout << ensemble[2] << endl;
	ensemble[2] = 3.0;
	cout << ensemble[2] << endl;
	cout << ensemble.getCapacite() << endl;
	ensemble += 10.0;
	cout << ensemble[6] << endl;
	cout << ensemble;
	fich << ensemble;
	str << ensemble;*/
	//cin >> ensemble;
	fich >> ensemble;
	//cout << ensemble;
	fich1 << ensemble;
	
	
	
	
	return 0;
}
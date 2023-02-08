#ifndef VECTEUR_H
#define VECTEUR_H
#include <iostream>
#include <sstream>
#include <fstream>
#include "forme.h"
using namespace std;
#define CAPACITE_INITIALE 2
template <typename T>

class Vecteur
{
private:
	int indexcourant;
	int taille;
	T* tableau;
	int capacite;

	
public: 
	Vecteur(int laCapacite = CAPACITE_INITIALE);
	~Vecteur();
	int getCapacite();
	int getTaille();
	void augmenterTaille();
	bool ajoutFin(T pForme);
	void clearVecteur();
	void afficherForme(ostream & s);
	T retirerForme(int index);
	T getForme(int index);
	bool isEmpty();
	int getindexcourant();

	const T operator[] (int index) const {
		return tableau[index];
	}

	T& operator[] (int index) {
		return tableau[index];
	}
	
	void operator+= (T pforme) {
		if (taille < capacite)
		{
			tableau[taille] = pforme;
			taille++;
		}
		else
		{
			capacite = capacite * 2;
			T* tableaub = new T[capacite];
			for (int a = 0; a < capacite / 2; a++)
			{
				tableaub[a] = tableau[a];
			}
			delete[] tableau;
			tableau = tableaub;
			tableau[taille] = pforme;
			taille++;

		}
	}

	friend ostream& operator<<(ostream& os, const Vecteur& v)
	{
		for (int a = 0; a < v.taille; a++)
		{
			os << "index " << a << " : " << v.tableau[a] << endl;
		}
		return os;
	}

	friend void operator >>(istream& os, Vecteur& v)
	{
		T chiffre;
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

	void operator ++() {
		if (indexcourant >= taille) {
			return;
		}
		++indexcourant;
	}

	void operator --() {
		if (indexcourant == 0) {
			return;
		}
		--indexcourant;
	}

};

template <typename T>
Vecteur<T>::Vecteur(int laCapacite)
{
	indexcourant = 0;
	capacite = laCapacite;
	taille = 0;
	tableau = new T[capacite];

}
template <typename T>
Vecteur<T>::~Vecteur()
{}
template <typename T>
int Vecteur<T>::getTaille()
{
	return taille;
}
template <typename T>
int Vecteur<T>::getCapacite()
{
	return capacite;
}
template <typename T>
bool Vecteur<T>::ajoutFin(T pForme)
{
	if (taille < capacite)
	{
		tableau[taille] = pForme;
		taille++;
		return true;
	}
	else
	{
		capacite = capacite * 2;
		T* tableaub = new T[capacite];
		for (int a = 0; a < capacite / 2; a++)
		{
			tableaub[a] = tableau[a];
		}
		delete[] tableau;
		tableau = tableaub;
		tableau[taille] = pForme;
		taille++;

		return true;
	}
	return false;
}

template <typename T>
bool Vecteur<T>::isEmpty()
{
	if (taille == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <typename T>
void Vecteur<T>::clearVecteur()
{
	delete[] tableau;
	capacite = CAPACITE_INITIALE;
	tableau = new T[capacite];
	taille = 0;
}
template <typename T>
T Vecteur<T>::retirerForme(int index)
{
	T pForme;
	pForme = tableau[index];
	for (int a = index; a < taille - 1; a++)
	{
		tableau[a] = tableau[a + 1];
	}
	taille--;
	/*if(taille <= capacite/2)
	{
		capacite = capacite/2;
	}*/
	return pForme;

}
template <typename T>
T Vecteur<T>::getForme(int index)
{
	T pForme;
	if (index > taille)
	{
		return pForme = NULL;
	}
	else
	{
		pForme = tableau[index];
		return pForme;
	}
}
template <typename T>
void Vecteur<T>::afficherForme(ostream& s)
{
	for (int a = 0; a < taille; a++)
	{
		tableau[a]->afficher(cout);
	}
}
template <typename T>
void Vecteur<T>::augmenterTaille() {
	taille++;
}
template <typename T>
int Vecteur<T>::getindexcourant()
{
	return indexcourant;
}

#endif


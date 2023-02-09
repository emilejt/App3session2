
template<typename T>
Vecteur<T>::Vecteur(int laCapacite)
{
	capacite = laCapacite;
	taille = 0;
	tableau = new T[capacite];
	indexcourant = 0;
}

template<typename T>
Vecteur<T>::~Vecteur()
{}
template<typename T>
int Vecteur<T>::getTaille() const
{
	return taille;
}
template<typename T>
int Vecteur<T>::getCapacite()
{
	return capacite;
}
template<typename T>
bool Vecteur<T>::ajoutFin(T donnee)
{
	if (taille < capacite)
	{
		tableau[taille] = donnee;
		taille++;
		return true;
	}
	else
	{
		capacite = capacite * 2;
		T* tableaub = new T[capacite];
		for (int a=0; a < capacite/2; a++)
		{
			tableaub[a] = tableau[a];
		}
		delete[] tableau;
		tableau = tableaub;
		tableau[taille] = donnee;
		taille++;
		
		return true;
	}
	return false;
}
template<typename T>
bool Vecteur<T>::isEmpty()
{
	if(taille == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template<typename T>
void Vecteur<T>::clearVecteur()
{
	delete[] tableau;
	capacite = CAPACITE_INITIALE;
	 tableau = new T[capacite];
	taille = 0;
}
template<typename T>
T Vecteur<T>::retireritem(int index)
{
	T donnee;
	if(index > taille)
	{
		return donnee;
	}
	else
	{
		donnee = tableau[index];
		for (int a = index; a<taille-1; a++)
		{
			tableau[a] = tableau[a+1];
		}
		taille--;
		if(taille <= capacite/2)
		{
			capacite = capacite/2;
		}
		return donnee;
	}
}
template<typename T>
T Vecteur<T>::getitem(int index)
{
	T donnee;
	if(index > taille)
	{
		return donnee = NULL;
	}
	else
	{
		donnee = tableau[index];
		return donnee;
	}
}
template<typename T>
void Vecteur<T>::afficher(ostream & s)
{
	for(int a=0; a<taille; a++)
	{
		tableau[a]->afficher(cout);
	}
}

template<typename T>
T& Vecteur<T>::operator[](int index)
{
	return tableau[index];
}

template<typename T>
const T& Vecteur<T>::operator[](int index) const
{
	return tableau[index];
}

template<typename T>
void Vecteur<T>::operator+= (T N) {
	if (taille < capacite)
	{
		tableau[taille] = N;
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
		tableau[taille] = N;
		taille++;

	}
}

template<typename T>
ostream& operator << (ostream& os, Vecteur<T>const& v)
{
	for (int a = 0; a < v.taille; a++)
	{
		os << "index " << a << " : " << v.tableau[a] << endl;
	}
	return os;
}

template<typename T>
void Vecteur<T>::operator ++() {
	if (indexcourant >= taille)
	{
		return;
	}
	++indexcourant;
}

template<typename T>
void Vecteur<T>::operator --() {
	if (indexcourant <= 0)
	{
		return;
	}
	--indexcourant;
}

template<typename T>
void Vecteur<T>::augmentetaille() {
	taille++;
}


template<typename T>
int Vecteur<T>::getindexcourant() {
	return indexcourant;
}

template <typename T>
void Vecteur<T>::afficherForme(ostream& s)
{
	for (int i = 0; i < taille; i++)
	{
		tableau[i]->afficher(cout);

	}
}





















		
		
		
		
		
		
		

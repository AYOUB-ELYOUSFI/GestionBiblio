#pragma once
#include "Livre.h"
namespace biblio{
class Bibliotheque
{
private:
	string nom;
	Livre** livres;
	int nbLivres, capacite;
	static int nbBibliotheques;

public:
	Bibliotheque(string, int);
	Bibliotheque(const Bibliotheque&);
	Bibliotheque& operator=(const Bibliotheque&);
	Bibliotheque& operator+=(const Livre& L);
	void rechercher(int);
	void rechercher(string);
	Livre& ajouterLivre(const Livre& L);
	~Bibliotheque();
	



};

}
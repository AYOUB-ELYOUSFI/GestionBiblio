#pragma once
#include "Date.h"

#include<iostream>
using namespace std;
namespace biblio {
	class Livre
	{
	protected:
		int const id;
	private:
		string titre, auteur;
		int* notes;
		int nbNotes;//taille
		Date parution;
		static int compteurId, nbInstances;
		int NoteCourant;
		                          
	public:
		Livre(int, string, string, int, Date);
		Livre(const Livre&);
		Livre();
		void afficher() const;
		~Livre();
		Livre& operator=(const Livre& );
		Livre& operator+=(const int&);   // ajouter une note au livre
		double CalculerMoyenne() const;
		void AjouterNote(int);

	};
}

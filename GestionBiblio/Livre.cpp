#include "Livre.h"
int biblio::Livre::compteurId = 0;
int biblio::Livre::nbInstances = 0;
using namespace biblio;

biblio::Livre::Livre( int id,string tr, string aut, int max, Date d):id(++compteurId)
{
	this->titre = tr;
	this->auteur = aut;
	this->parution = d;
	this->nbNotes = max;
	this->notes = new int[max];
	this->NoteCourant = 0;
	nbInstances++ ;
}

biblio::Livre::Livre(const Livre& L):id(++compteurId)
{
	this->titre = L.titre;
	this->auteur = L.auteur;
	this->nbNotes = L.nbNotes;
	this->NoteCourant = L.NoteCourant;
	this->notes = nullptr;
	if(L.nbNotes>0){
	  this->notes = new int[this->nbNotes];
	  for (int i = 0;i < nbNotes;i++) {
	    this->notes[i] =L.notes[i];
	}
	}
	nbInstances++;
}

Livre& biblio::Livre::operator=(const Livre& L)
{
	this->titre = L.titre;
	this->auteur = L.auteur;
	this->nbNotes = L.nbNotes;
	this->NoteCourant = L.NoteCourant;
	int* tempnote = nullptr;
	if (L.nbNotes > 0) {
		tempnote = new int[L.nbNotes];
		for (int i=0;i < nbNotes;i++) {
			tempnote[i] = L.notes[i];      /// pour liberer lancien allocation memoire du tableau de 
			                               /// lobjet courant et lui affecter le tableau de L
		}
	}
	delete[]this->notes;
	this->notes = tempnote;
	return *this;
}

Livre& biblio::Livre::operator+=(const int& n)
{
	this->AjouterNote(n);
	return *this;
}

double biblio::Livre::CalculerMoyenne() const
{
	double moyenne=0;
	if (NoteCourant != 0) {

		for (int i = 0;i < this->NoteCourant;i++) {
			moyenne += this->notes[i];
		}
		return moyenne /= (this->NoteCourant);
	}
	else return 0;
}

void biblio::Livre::AjouterNote(int n) 
{
	if (n>=0 && n<=20)
	{
	   if ((this->nbNotes > 0) && (this->NoteCourant < this->nbNotes)) {
		this->notes[NoteCourant] = n;
		++NoteCourant;
	    }
	   else cerr << "Tableau vide ou plein" << endl;
	}
	else
	{
		cerr << "Entrer une note entre 0 et 20" << endl;
	}
}


void biblio::Livre::afficher() const
{

	cout << "id:  " << this->id << endl;
	cout << "titre:  " << this->titre << endl;
	cout << "auteur:  " << this->auteur << endl;
	cout << "date d'edition:  ";
	this->parution.afficher();
	cout << endl;
	cout << "Notes:  ";
	for (int i = 0;i < this->nbNotes;i++) {
		cout << this->notes[i];
	}
	cout << endl;

}





biblio::Livre::~Livre()
{
	nbInstances--;
	delete[]notes;
	notes = nullptr;
}

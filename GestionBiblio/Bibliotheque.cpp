#include "Bibliotheque.h"
int biblio::Bibliotheque::nbBibliotheques = 0;

biblio::Bibliotheque::Bibliotheque(string n, int c)
{
    this->nom = n;
    this->capacite = c;
    this->nbLivres = 0;

    if (this->capacite > 0) {
        this->livres = new Livre * [this->capacite];

        for (int i = 0; i < this->capacite; i++) {
            this->livres[i] = nullptr;
        }
    }
    nbBibliotheques++;
}

biblio::Bibliotheque::Bibliotheque(const Bibliotheque& b)
{
    this->nom = b.nom;
    this->capacite = b.capacite;
    this->nbLivres = b.nbLivres;

    if (capacite > 0) {
        this->livres = new Livre * [this->capacite];

        for (int i = 0; i < this->capacite; i++) {
            this->livres[i] = nullptr;
        }

        for (int i = 0; i < this->nbLivres; i++) {
            livres[i] = new Livre(*b.livres[i]);
        }
    }
    nbBibliotheques++;
}

Bibliotheque& biblio::Bibliotheque::operator=(const Bibliotheque& b)
{
    if (this != &b)
    {
       
        for (int i = 0; i < nbLivres; i++)
        {
            delete livres[i];
        }

        delete[] livres;

       
        this->nom = b.nom;
        this->capacite = b.capacite;
        this->nbLivres = b.nbLivres;
        this->livres = nullptr;

        
        if (this->capacite > 0)
        {
            this->livres = new Livre * [this->capacite];

            for (int i = 0; i < this->capacite; i++)
            {
                this->livres[i] = nullptr;
            }

            
            for (int i = 0; i < this->nbLivres; i++)
            {
                this->livres[i] = new Livre(*b.livres[i]);
            }
        }
    }
    return*this;
}

Bibliotheque& biblio::Bibliotheque::operator+=(const Livre& L)
{
    if (this->nbLivres < this->capacite)
    {
        ajouterLivre(L);
    }
    else
    {
        cerr << "La bibliotheque est pleine !" << endl;
    }

    return *this;
}

void biblio::Bibliotheque::rechercher(int id)
{
    for (int i = 0; i < nbLivres; i++)
    {
        if (this->livres[i]->id == id) // pour etre qccesible on fait protected
        {
            cout << "Livre trouve :" << endl;
            this->livres[i]->afficher();
            return;
        }
    }

    cout << "Aucun livre avec cet identifiant." << endl;
}

void biblio::Bibliotheque::rechercher(string)
{
    for (int i = 0; i < nbLivres; i++)
    {
        if (livres[i]->titre == titre)
        {
            cout << "Livre trouve :" << endl;
            livres[i]->afficher();
            return;
        }
    }

    cout << "Aucun livre avec ce titre." << endl;
}




Livre& biblio::Bibliotheque::ajouterLivre(const Livre& L)
{
    if (this->nbLivres < this->capacite) {

        this->livres[nbLivres] = new Livre(L);

        this->nbLivres++;
    
    return *this->livres[this->nbLivres - 1];
    }
}

biblio::Bibliotheque::~Bibliotheque()
{
    for (int i = 0; i < nbLivres; i++) {
        delete livres[i];
    }

    delete[] livres;

    nbBibliotheques--;
}

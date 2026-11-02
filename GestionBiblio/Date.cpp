#include "Date.h"
#include <iostream>
using namespace std;
biblio::Date::Date(int j, int m, int a):jour(1),mois(1),annee(2000)
{
	if (estValide(j,m,a)) {
		this->jour = j;
		this->mois = m;
		this->annee = a;
	}
	else 
	{
	  std::cerr << "Entrez une date valide svp";
	}
}

biblio::Date::Date()
{
}



bool biblio::Date::estBissextile(int b)
{
	if ((b % 4 == 0 && b % 100 != 0)|| b%400==0) return true;
	else return false;
}

bool biblio::Date::estValide(int j, int m, int a)
{


	if (j <= 0 || j > 31 || m > 12 || m <= 0 || a <= 0) return false;
	else if (m <= 7) {
		if (m % 2 == 0) {

			if (m == 2) {

				if (estBissextile(a) && j <= 29)
					return true;
				else if (!estBissextile(a) && j <= 28)
					return true;
				else return false;
			}

			else {
				if (j <= 30) return true;
				else return false;
			}
		}
		else if (m % 2 != 0) {

			if (j <= 31) return true;
			else return false;
		}
	}
	else {

		if (m % 2 != 0) {

			if (j <= 30) return true;
			else return false;
		}
        else {
			if (j <= 31) return true;
			else return false;
		}
	}
 return false;
}
bool biblio::Date::operator==(const Date& d) const
{
	if (this->jour == d.jour && this->mois == d.mois && this->annee == d.annee)
		return true;
	else return false;
}

bool biblio::Date::operator<(const Date& d) const
{
	if (this->annee < d.annee) return true;
	else if (this->mois < d.mois) return true;
	else if (this->jour < d.jour)return true;
	else return false;
}

void biblio::Date::afficher() const
{
	cout << this->jour << "/" << this->mois << "/" << this->annee << endl;
}

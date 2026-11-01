#pragma once
 namespace biblio{
	 class Date {

  private:
	  int jour, mois, annee;

  public:
	  Date(int, int, int);
	  Date();
	  static bool estBissextile(int);
	  static bool estValide(int, int, int);
	  bool operator==(const Date& ) const;
	  bool operator<(const Date& ) const;
	  void afficher() const;
};
 }

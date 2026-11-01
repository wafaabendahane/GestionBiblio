#include "Date.h"
#include<iostream>
using namespace std;
using namespace Biblio;
Biblio::Date::Date(int j, int m, int a)
{
	this->jour = j;
	this->mois = m;
	this->annee = a;
}

bool Biblio::Date::estBissextile(int a)
{
	if (a%4==0&& a%100!=0||a%400==0)
		return true;
	else
		return false;
}

bool Biblio::Date::estValide(int j, int m, int a)
{
	if (a < 1 || m < 1 || m>12 || j < 1) return false;
	int tab[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (estBissextile(a)) {
		tab[1] = 29;
	}
	if (m <= 0 || m > 12) {
		return false;
	}
	else {
		if (j<1 || j>tab[m - 1])
			return false;
	}

}

bool Biblio::Date::operator==(const Date& d) const
{
	return this->annee == d.annee && this->jour == d.jour && this->mois == d.mois;
}

bool Biblio::Date::operator<(const Date& d) const
{
	{
		if (this->annee != d.annee) return this->annee < d.annee;
		if (this->mois != d.mois) return this->mois < d.mois;
		return this->jour < d.jour;
	}

}




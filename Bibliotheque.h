#pragma once
#include"Livre.h"
using namespace std;
using namespace Biblio;
#include<iostream>
class Bibliotheque
{
private:
	string nom;
	int nbLivre;
	int capacite;
	int static nbBibliotheques;
	Livre** livre;
public:
	Bibliotheque(string, int);
	Bibliotheque(const Bibliotheque& b);
	~Bibliotheque();
	Bibliotheque& operator=(const Bibliotheque& b);
	Bibliotheque& operator+=(const Livre& L);
	Bibliotheque& ajouterLivre(const Livre& L);
	void afficher() const;
	int getNbLivres() const;
	string getNom() const;
};


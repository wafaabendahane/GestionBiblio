#include "Bibliotheque.h"
#pragma once
#include"Livre.h"
using namespace std;
using namespace Biblio;
#include<iostream>
int Bibliotheque::nbBibliotheques = 0;
Bibliotheque::Bibliotheque(string n,  int c)
{
	this->nom = n;
	this->capacite = c;
	this->nbLivre = 0;
	this->livre = new Livre * [this->capacite];
	for (int i = 0; i < this->capacite; i++) {
		this->livre[i] = nullptr;
	}
	nbBibliotheques++;
};

Bibliotheque::Bibliotheque(const Bibliotheque& b)
{
	this->nom = b.nom;
	this->capacite = b.capacite;
	this->nbLivre = b.nbLivre;
	this->livre = new Livre * [this->capacite];
	for (int i = 0; i < this->nbLivre; i++) {
		this->livre[i] = new Livre(*b.livre[i]);
	}
	nbBibliotheques++;
}

Bibliotheque::~Bibliotheque()
{
	delete[] livre;
	nbBibliotheques--;
}

Bibliotheque& Bibliotheque::operator=(const Bibliotheque& b)
{
	if (this != &b) {
		delete [] this->livre;
		this->nom = b.nom;
		this->nbLivre = b.nbLivre;
		this->capacite = b.capacite;
		this->livre = new Livre * [b.capacite];
		for (int i = 0; i < nbLivre; i++)
			livre[i] = new Livre(*b.livre[i]);

	}
	return *this;
}

Bibliotheque& Bibliotheque::operator+=(const Livre& L)
{
	return this->ajouterLivre(L);
}

Bibliotheque& Bibliotheque::ajouterLivre(const Livre& L)
{
	if (this->nbLivre < this->capacite) {
		this->livre[this->nbLivre] = new Livre(L);
		nbLivre++;
	}
	return *this;
}
int Bibliotheque::getNbLivres() const {
	return this->nbLivre;
}

string Bibliotheque::getNom() const {
	return this->nom;
};

void Bibliotheque::afficher() const {
	std::cout << " BIBLIOTHEQUE : " << this->nom  << std::endl;
	std::cout << "Capacite : " << this->capacite << std::endl;
	std::cout << "Nombre de livres actuels : " << this->nbLivre << std::endl;
	if (this->nbLivre == 0) {
		std::cout << "La bibliotheque est vide." << std::endl;
	}
	else {
		for (int i = 0; i < this->nbLivre; i++) {
			std::cout << "Livre " << (i + 1) << " :" << std::endl;
			std::cout << "  - ID : " << this->livre[i]->getId() << std::endl;
			std::cout << "  - Titre : " << this->livre[i]->getTitre() << std::endl;
			std::cout << "  - Auteur : " << this->livre[i]->getAuteur() << std::endl;
			std::cout << "----------------------------------------" << std::endl;
			
		}
	}
}




#pragma once
#include<iostream>
#include"Date.h"
using namespace std;
using namespace Biblio;
	class Livre
	{
	private:
		int const id;
		string titre;
		string auteur;
		Date* parution;
		int* notes;
		int nbNotes;
		int static compteurId;
		int static nbInstance;
	public:
		Livre( string, string, int, int*, Date*p);
		Livre(const Livre& L);
		Livre& operator=(const Livre& L);
		Livre& operator+=(int note);
		~Livre();
		int getId() const;
		string getTitre() const;
		string getAuteur() const;



	};

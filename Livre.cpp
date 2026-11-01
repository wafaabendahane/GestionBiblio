#include "Livre.h"
#include "Date.h"
#include <iostream>

using namespace Biblio; 

int Livre::compteurId = 0;

Livre::Livre( string t, string a, int nb, int* n, Date* p) : id(++compteurId)
{
    this->titre = t;
    this->auteur = a;
    this->nbNotes = nb;
    this->parution = p;
    this->notes = n;
};

Livre::Livre(const Livre& L) : id(++compteurId)
{
    this->titre = L.titre;
    this->auteur = L.auteur;
    this->nbNotes = L.nbNotes;

    
    this->parution = L.parution;

    this->notes = new int[L.nbNotes];
    for (int i = 0; i < nbNotes; i++) {
        this->notes[i] = L.notes[i];
    }
}
Livre& Livre::operator=(const Livre& L)
{
    if (this != &L) {
        delete[] this->notes; 

        this->titre = L.titre;
        this->auteur = L.auteur;
        this->nbNotes = L.nbNotes;
        this->parution = L.parution; 
        this->notes = new int[L.nbNotes];
        for (int i = 0; i < nbNotes; i++) {
            this->notes[i] = L.notes[i];
        }
    }
    return *this;
}
Livre& Livre::operator+=(int note) {
    int* nouveauNotes = new int[this->nbNotes + 1];
    for (int i = 0; i < this->nbNotes; i++) {
        nouveauNotes[i] = this->notes[i];
    }
    nouveauNotes[this->nbNotes] = note;
    delete[] this->notes;
    this->notes = nouveauNotes;
    this->nbNotes++;
    return *this;
}


Livre::~Livre()
{
    delete[] notes; 
}
int Livre::getId() const {
    return this->id;
}

string Livre::getTitre() const {
    return this->titre;
}

string Livre::getAuteur() const {
    return this->auteur;
}

// GestionBiblio.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Date.h"
#include "Livre.h"
#include "Bibliotheque.h"

using namespace std;
using namespace Biblio;

int main()
{
    int tabNotes[] = { 12, 14, 16, 15, 18 };
    Date d1(20, 10, 2020);
    Date d2(15, 5, 2022);
    Livre L1("C++", "Ghizlane", 5, tabNotes, &d1);
    Livre L2("C", "Hssina", 5, tabNotes, &d2);
    Date d3(15, 5, 2022);
    Livre L3("dev web", "Kissi", 5, tabNotes, &d3);
    Bibliotheque B1("Ma Bibliotheque", 4);
    B1.ajouterLivre(L1);
    B1.ajouterLivre(L2);
    B1 += L3;
    Livre L4 = L3;
    B1 += L4;
    cout << "\n B1:" << endl;
    B1.afficher();
    cout << "\n " << endl;
    Bibliotheque B2 = B1;
    cout << "\n B2:" << endl;
    B2.afficher();
    
}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.

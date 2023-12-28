
//---------- Réalisation de la classe <noeud> (fichier noeud.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "noeud.h"
#include "sousnoeud.h"

//-------------------------------------------- Constructeurs - destructeur
noeud::noeud(const noeud &unnoeud)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <noeud>" << endl;
#endif
} //----- Fin de noeud (constructeur de copie)

noeud::noeud()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <noeud>" << endl;
#endif
    hits = 0; // on initialise le nb de hits à 0
    nbinstances++;
    numinstance = nbinstances;
} //----- Fin de noeud

noeud::~noeud()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <noeud>" << endl;
#endif
} //----- Fin de ~noeud

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

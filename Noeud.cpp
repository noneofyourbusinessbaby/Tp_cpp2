//---------- Réalisation de la classe <Noeud> (fichier Noeud.cpp) ------------
#include "Noeud.h"

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

#include <iostream>

//------------------------------------------------------ Include personnel
#include "SousNoeud.h"

//-------------------------------------------- Constructeurs - destructeur
Noeud::Noeud(const Noeud &unnoeud)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Noeud>" << endl;
#endif
} //----- Fin de Noeud (constructeur de copie)

Noeud::Noeud()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Noeud>" << endl;
#endif

    hits = 0; // on initialise le nb de hits à 0

    static int nbinstances = 0;

    numinstance = ++nbinstances;
} //----- Fin de Noeud

Noeud::~Noeud()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Noeud>" << endl;
#endif
} //----- Fin de ~Noeud

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

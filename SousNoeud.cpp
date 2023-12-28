//---------- Réalisation de la classe <SousNoeud> (fichier SousNoeud.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "SousNoeud.h"

//-------------------------------------------- Constructeurs - destructeur
SousNoeud::SousNoeud ( const SousNoeud & unsousnoeud )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <SousNoeud>" << endl;
#endif
} //----- Fin de SousNoeud (constructeur de copie)


SousNoeud::SousNoeud ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <SousNoeud>" << endl;
#endif
} //----- Fin de SousNoeud


SousNoeud::~SousNoeud ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <SousNoeud>" << endl;
#endif
} //----- Fin de ~SousNoeud


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

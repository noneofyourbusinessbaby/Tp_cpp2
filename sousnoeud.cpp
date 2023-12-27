//---------- Réalisation de la classe <sousnoeud> (fichier sousnoeud.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "sousnoeud.h"

//-------------------------------------------- Constructeurs - destructeur
sousnoeud::sousnoeud ( const sousnoeud & unsousnoeud )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <sousnoeud>" << endl;
#endif
} //----- Fin de sousnoeud (constructeur de copie)


sousnoeud::sousnoeud ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <sousnoeud>" << endl;
#endif
} //----- Fin de sousnoeud


sousnoeud::~sousnoeud ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <sousnoeud>" << endl;
#endif
} //----- Fin de ~sousnoeud


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

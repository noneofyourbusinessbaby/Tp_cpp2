//---------- Interface de la classe <sousnoeud> (fichier sousnoeud.h) ----------------
#if ! defined ( sousnoeud_H )
#define sousnoeud_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <iostream>

#include "Graph.h"

using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <sousnoeud>
// Sous noeud permet de stocker les infos communes à une cible et un réfreur
// donc le nb de hits commun au deux et les logs
//------------------------------------------------------------------------

class sousnoeud
{
//----------------------------------------------------------------- AMITIE
    friend class Graph;
//----------------------------------------------------------------- PUBLIC

public:

//-------------------------------------------- Constructeurs - destructeur
    
    sousnoeud ( const sousnoeud & unsousnoeud );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    
    // TODO: const string & unLog
    sousnoeud(string unLog);
    // Mode d'emploi :
    //
    // Contrat :
    //

    sousnoeud ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~sousnoeud ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

private:
//----------------------------------------------------- Méthodes privées
    vector<string> vecteur_logs; // pour un un réfreur et une cible
    int nbhits; // nb de hits depuis un réfreur spécifique vers une cible
//----------------------------------------------------- Attributs privées

};

//-------------------------------- Autres définitions dépendantes de <sousnoeud>

#endif // sousnoeud_H


//---------- Interface de la classe <SousNoeud> (fichier SousNoeud.h) ----------------
#if ! defined ( sousnoeud_H )
#define sousnoeud_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <iostream>

#include "Graph.h"

using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <SousNoeud>
// Sous Noeud permet de stocker les infos communes à une cible et un réfreur
// donc le nb de hits commun au deux et les logs
//------------------------------------------------------------------------

class SousNoeud
{
//----------------------------------------------------------------- AMITIE
    friend class Graph;
//----------------------------------------------------------------- PUBLIC

public:

//-------------------------------------------- Constructeurs - destructeur
    
    SousNoeud ( const SousNoeud & unsousnoeud );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    
    // TODO: const string & unLog
    SousNoeud(string unLog);
    // Mode d'emploi :
    //
    // Contrat :
    //

    SousNoeud ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~SousNoeud ( );
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

//-------------------------------- Autres définitions dépendantes de <SousNoeud>

#endif // sousnoeud_H


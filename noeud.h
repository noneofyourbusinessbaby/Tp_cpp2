//---------- Interface de la classe <noeud> (fichier noeud.h) ----------------
#if ! defined ( noeud_H )
#define noeud_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <iostream>
#include "sousnoeud.h"
#include "graph.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <noeud>
//
//
//------------------------------------------------------------------------

class noeud
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Amitié
    friend class graph;
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    noeud & operator = ( const noeud & unnoeud );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    noeud ( const noeud & unnoeud );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    noeud ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~noeud ( );
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
    map<string,sousnoeud> dictionnaire_sous_noeuds;
    int hits;
    // il s'agit des ensembles de liens atteignables depuis une origine associée le sous noeud va contenir 
    // l'ensemble des logs communs aux deux ainsi que le nb de hits depuis la clé du dictionnaire vers le noeud

//----------------------------------------------------- Attributs privées

};

//-------------------------------- Autres définitions dépendantes de <noeud>

#endif // noeud_H

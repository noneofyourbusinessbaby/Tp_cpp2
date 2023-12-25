//---------- Interface de la classe <sousnoeud> (fichier sousnoeud.h) ----------------
#if ! defined ( sousnoeud_H )
#define sousnoeud_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <iostream>
#include <log.h>
#include <graph.h>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <sousnoeud>
//
//
//------------------------------------------------------------------------

class sousnoeud
{
//----------------------------------------------------------------- AMITIE
    friend class graph;
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    sousnoeud & operator = ( const sousnoeud & unsousnoeud );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    sousnoeud ( const sousnoeud & unsousnoeud );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    
    sousnoeud(log unLog);
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
    vector<log> vecteur_logs; // pour un noeud donné 
    int nbhits;
//----------------------------------------------------- Attributs privées

};

//-------------------------------- Autres définitions dépendantes de <sousnoeud>

#endif // sousnoeud_H


//---------- Interface de la classe <graph> (fichier graph.h) ----------------
#if ! defined ( graph_H )
#define graph_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <iostream>
#include <noeud.h>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <graph>
//
//
//------------------------------------------------------------------------

class graph
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    graph & operator = ( const graph & ungraph );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    graph ( const graph & ungraph );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    graph ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~graph ( );
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
    map<string,noeud> dictionnaire_noeuds; // un graphe a comme clé un objet de type string qui est un réfreur le noeud est un dictionnaire soit un ensemble des liens qu'n peut atteindre depuis de refreur 
//----------------------------------------------------- Attributs privées

};

//-------------------------------- Autres définitions dépendantes de <graph>

#endif // graph_H


//---------- Interface de la classe <graph> (fichier graph.h) ----------------
#if ! defined ( graph_H )
#define graph_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <iostream>
#include <vector>
#include "lecturelog.h"
using namespace std;
//------------------------------------------------------------- Constantes
#define NB_SOMMETS 10
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <graph>
// Graphe est la classe qui va contenir et gérer l'ensemble des logs dans
// dictionnaire 
//------------------------------------------------------------------------
class noeud;
class graph
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void afficheHitsMax();
    // Permet d'afficher le top 10 des cibles % au nb de hits 

    void ajouteLogAuDictionnaire(string refreur, string cible, string log);
    // Permet d'ajouter un Log au map qui est l'attribut de la classe

    //------------------------------------------------- Surcharge d'opérateurs
    ostream& operator << (ostream & out) const;
    // surcharge de l'opérateur << pour l'affichage du graphe

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
//----------------------------------------------------- Attributs privées
    map<string,noeud> dictionnaire_noeuds;
    // un graphe a comme clé un objet de type string qui est un réfreur le noeud est lui même un dictionnaire soit un ensemble de cibles qu'on peut atteindre depuis de refreur
};

//-------------------------------- Autres définitions dépendantes de <graph>

#endif // graph_H


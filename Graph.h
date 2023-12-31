//---------- Interface de la classe  Graph> (fichier Graph.h) ----------------
#if ! defined ( Graph_H )
#define Graph_H

//--------------------------------------------------- Interfaces utilisées

#include <map>
#include <string>
#include <iostream>

#include "LectureLog.h"

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe  Graph>
// Graphe est la classe qui va contenir et gérer l'ensemble des logs dans
// dictionnaire 
//------------------------------------------------------------------------
class Noeud;

class Graph
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void AfficheHitsMax();
    // Permet d'afficher le top 10 des cibles % au nb de hits 

    void AjouteLogAuDictionnaire(const string& refreur, const string& cible, const string& log);
    // Permet d'ajouter un Log au map qui est l'attribut de la classe

    //------------------------------------------------- Surcharge d'opérateurs
    friend ostream& operator<<(ostream & out, const Graph& graph);
    // surcharge de l'opérateur << pour l'affichage du Graphe

//-------------------------------------------- Constructeurs - destructeur
 Graph ( const Graph & graph);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

 Graph ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Graph ( );
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
    map<string,Noeud> dictionnaire_noeuds;
    // un Graphe a comme clé un objet de type string qui est un réfreur le Noeud est lui même un dictionnaire soit un ensemble de cibles qu'on peut atteindre depuis de refreur
};

//-------------------------------- Autres définitions dépendantes de  Graph>

#endif // Graph_H


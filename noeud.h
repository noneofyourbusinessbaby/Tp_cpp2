//---------- Interface de la classe <noeud> (fichier noeud.h) ----------------
#if !defined(noeud_H)
#define noeud_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <iostream>
#include "graph.h"
#include "sousnoeud.h"

//------------------------------------------------------------------------
// Rôle de la classe <noeud>
// Cette classe permet de stocker les cibles atteignables depuis un réfreur 
// donné qui est une clé du map de la classe graph
//------------------------------------------------------------------------

class noeud
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Amitié
    friend class graph; 
    
    //-------------------------------------------- Constructeurs - destructeur
    noeud(const noeud &unnoeud);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    noeud();
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    void ajouteSousNoeud(string cible, sousnoeud unSousNoeud);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~noeud();
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
    map<string, sousnoeud> dictionnaire_sous_noeuds; // la clé ici est la cible depuis réfreur sous noaud contient les logs communs au réfreur et à la cible + nb de hits communs
    int hits; // correspond au nb de hits total de la clé (oui elle est enregistrée dans noeud)
    static int nbinstances; // permet de numéroter les insatnces de noeud pour la génération du graphe
    int numinstance;
    //----------------------------------------------------- Attributs privées
};

//-------------------------------- Autres définitions dépendantes de <noeud>

#endif // noeud_H

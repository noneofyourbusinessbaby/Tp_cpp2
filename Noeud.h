//---------- Interface de la classe <Noeud> (fichier Noeud.h) ----------------
#if !defined(noeud_H)
#define noeud_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <iostream>

#include "Graph.h"
#include "SousNoeud.h"

//------------------------------------------------------------------------
// Rôle de la classe <Noeud>
// Cette classe permet de stocker les cibles atteignables depuis un réfreur 
// donné qui est une clé du map de la classe graph
//------------------------------------------------------------------------

class Noeud
{

    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Amitié    

    //-------------------------------------------- Constructeurs - destructeur
    Noeud(const Noeud &unnoeud);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    inline int GetNumInstance() const {
        return numinstance;
    }

    inline int GetHits() const {
        return hits;
    }

    inline void Hit()  {
        ++hits;
    }

    inline const map<string, SousNoeud>& GetDictionnaireSousNoeud() const {
        return dictionnaire_sous_noeuds;
    }

    inline void AddLogCibleNoeud(const string & cible,const string & unLog) {
                
        if (dictionnaire_sous_noeuds.count(cible) > 0) // si la cible est déjà dedans on rajoute le log au sous Noeud
        {
            SousNoeud& sousnoeud = dictionnaire_sous_noeuds[cible];

            sousnoeud.AjouteLog(unLog);
        }
        else // sinon on la crée
        {
            SousNoeud sousnoeud;

            sousnoeud.AjouteLog(unLog);

            dictionnaire_sous_noeuds[cible] = sousnoeud;
        }
    }

    Noeud();
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    virtual ~Noeud();
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
    map<string, SousNoeud> dictionnaire_sous_noeuds; // la clé ici est la cible depuis réfreur sous noaud contient les logs communs au réfreur et à la cible + nb de hits communs
    
    int hits; // correspond au nb de hits total de la clé (oui elle est enregistrée dans Noeud)

    int numinstance;
    //----------------------------------------------------- Attributs privées
};

//-------------------------------- Autres définitions dépendantes de <Noeud>

#endif // noeud_H

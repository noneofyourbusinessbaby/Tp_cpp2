//---------- Interface de la classe <SousNoeud> (fichier SousNoeud.h) ----------------
#if ! defined ( sousnoeud_H )
#define sousnoeud_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <iostream>

using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <SousNoeud>
// Sous Noeud permet de stocker les infos communes à une cible et un réfreur
// donc le nb de hits commun au deux et les logs
//------------------------------------------------------------------------

class SousNoeud
{
//----------------------------------------------------------------- AMITIE
//----------------------------------------------------------------- PUBLIC

public:

//-------------------------------------------- Constructeurs - destructeur
    inline int GetNbhits() const {
        return nbhits;
    }

    inline void Hit() {
        ++nbhits;
    }

    inline void AjouteLog(const string & unLog)  {

        vecteur_logs.push_back(std::move(unLog));

        Hit();
    }

    SousNoeud (const SousNoeud & unsousnoeud );
    // Mode d'emploi (constructeur de copie) :
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
    int nbhits; // nb de hits depuis un réfreur spécifique vers une cible
    vector<string> vecteur_logs; // pour un un réfreur et une cible
//----------------------------------------------------- Attributs privées

};

//-------------------------------- Autres définitions dépendantes de <SousNoeud>

#endif // sousnoeud_H


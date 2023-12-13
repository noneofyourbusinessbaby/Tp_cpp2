//---------- Interface de la classe <ecrituredot> (fichier ecrituredot.h) ----------------
#if ! defined ( ecrituredot_H )
#define ecrituredot_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ecrituredot>
//
//
//------------------------------------------------------------------------

class ecrituredot
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
    ecrituredot & operator = ( const ecrituredot & unecrituredot );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ecrituredot ( const ecrituredot & unecrituredot );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ecrituredot ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ecrituredot ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <ecrituredot>

#endif // ecrituredot_H


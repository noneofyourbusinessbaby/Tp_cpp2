//---------- Interface de la classe <log> (fichier log.h) ----------------
#if ! defined ( log_H )
#define log_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <iostream>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <log>
//
//
//------------------------------------------------------------------------

class log
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
    log & operator = ( const log & unlog );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    log ( const log & unlog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    log ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~log ( );
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
    string ligne_log;
//----------------------------------------------------- Attributs privées

};

//-------------------------------- Autres définitions dépendantes de <log>

#endif // log_H

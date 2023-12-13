//---------- Interface de la classe <lecturelog> (fichier lecturelog.h) ----------------
#if ! defined ( lecturelog_H )
#define lecturelog_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <lecturelog>
//
//
//------------------------------------------------------------------------

class lecturelog
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
    lecturelog & operator = ( const lecturelog & unlecturelog );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    lecturelog ( const lecturelog & unlecturelog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    lecturelog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~lecturelog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <lecturelog>

#endif // lecturelog_H


//---------- Interface de la classe <lecturelog> (fichier lecturelog.h) ----------------
#if !defined(lecturelog_H)
#define lecturelog_H
using namespace std;
//--------------------------------------------------- Interfaces utilisées
#include <string>
class graph;

// Rôle de la classe <lecturelog>
// Le rôle de cette classe est de réaliser la lecture du fichier log
// elle permet de filtrer les logs selon les différents critères de sélection
//------------------------------------------------------------------------
class lecturelog
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    void lectureFichier(graph &unGraphe, bool optionE, int heure);
    // permet d'exporter les données depuis le fichier de logs fourni

    lecturelog &operator=(const lecturelog &unlecturelog);

    //-------------------------------------------- Constructeurs - destructeur
    lecturelog(const lecturelog &unlecturelog);

    lecturelog(string);

    virtual ~lecturelog();
    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
private:
    //----------------------------------------------------- Méthodes privées

    // ces méthodes permettent de réaliser des insertions dans le dictionnaire selon les filtres appliqués
    void insertionSansOptions(string ligneLog, graph &unGraphe);

    void insertionsOptionE(string ligneLog, graph &unGraphe);

    void insertionsOptionHeure(string ligneLog, graph &unGraphe, int heure);

    void insertionsOptionHeureEtE(string ligneLog, graph &unGraphe, int heure);

    //----------------------------------------------------- Attributs privés
    string nomFichier;
};

//-------------------------------- Autres définitions dépendantes de <lecturelog>

#endif // lecturelog_H

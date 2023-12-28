//---------- Interface de la classe <lecturelog> (fichier lecturelog.h) ----------------
#if !defined(lecturelog_H)
#define lecturelog_H
using namespace std;
//--------------------------------------------------- Interfaces utilisées
#include <string>
class Graph;

// Rôle de la classe <lecturelog>
// Le rôle de cette classe est de réaliser la lecture du fichier log
// elle permet de filtrer les logs selon les différents critères de sélection
//------------------------------------------------------------------------
class lecturelog
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    void lectureFichier(Graph &unGraphe, bool optionE, int heure);
    // permet d'exporter les données depuis le fichier de logs fourni

    lecturelog &operator=(const lecturelog &unlecturelog);

    //-------------------------------------------- Constructeurs - destructeur
    lecturelog(const lecturelog &unlecturelog);

    // TODO: ???????? const string& nomFichier
    lecturelog(string);

    virtual ~lecturelog();
    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
private:
    //----------------------------------------------------- Méthodes privées

    // ces méthodes permettent de réaliser des insertions dans le dictionnaire selon les filtres appliqués
    // TODO: const string& ligneLog
    void insertionSansOptions(string ligneLog, Graph &unGraphe);

    // TODO: const string& ligneLog
    void insertionsOptionE(string ligneLog, Graph &unGraphe);

    // TODO: const string& ligneLog
    void insertionsOptionHeure(string ligneLog, Graph &unGraphe, int heure);

    // TODO: const string& ligneLog
    void insertionsOptionHeureEtE(string ligneLog, Graph &unGraphe, int heure);

    //----------------------------------------------------- Attributs privés
    string nomFichier;
};

//-------------------------------- Autres définitions dépendantes de <lecturelog>

#endif // lecturelog_H

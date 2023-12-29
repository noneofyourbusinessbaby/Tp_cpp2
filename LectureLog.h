//---------- Interface de la classe <LectureLog> (fichier LectureLog.h) ----------------
#if !defined(lecturelog_H)
#define lecturelog_H
//--------------------------------------------------- Interfaces utilisées

#include <string>

using namespace std;

class Graph;

// Rôle de la classe <LectureLog>
// Le rôle de cette classe est de réaliser la lecture du fichier log
// elle permet de filtrer les logs selon les différents critères de sélection
//------------------------------------------------------------------------
class LectureLog
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    LectureLog(const string& fichier);

    void LectureFichier(Graph &unGraphe, bool optionE, int heure);
    // permet d'exporter les données depuis le fichier de logs fourni

    LectureLog &operator=(const LectureLog &unlecturelog);

    //-------------------------------------------- Constructeurs - destructeur
    LectureLog(const LectureLog &unlecturelog);

    virtual ~LectureLog();
    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
private:
    //----------------------------------------------------- Méthodes privées

    // ces méthodes permettent de réaliser des insertions dans le dictionnaire selon les filtres appliqués
    void insertionSansOptions(const string& ligneLog, Graph &unGraphe);

    void insertionsOptionE(const string& ligneLog, Graph &unGraphe);

    void insertionsOptionHeure(const string& ligneLog, Graph &unGraphe, int heure);

    void insertionsOptionHeureEtE(const string& ligneLog, Graph &unGraphe, int heure);

    //----------------------------------------------------- Attributs privés
    string nomFichier;
};

//-------------------------------- Autres définitions dépendantes de <LectureLog>

#endif // lecturelog_H

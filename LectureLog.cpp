//---------- Réalisation de la classe <LectureLog> (fichier LectureLog.cpp) ------------
#include "LectureLog.h"

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel

#include "Graph.h"

#include <regex>

//------------------------------------------------------------- Constantes

#define apacheLogRegex1 "(\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3})( - - \\[\\d{2}\\/[a-zA-Z]{3}\\/\\d{4}:\\d{2}:\\d{2}:)(\\d{2})( )(\\+|\\-)(\\d{4})(]\\ )((\")(GET|POST|HEAD|OPTIONS)( ))(\\/.+)(\\.)(.+)( )(HTTP\\/1\\.(1|0))(\")( )(\\d{3})( )(\\d+)( )(\")"
#define apacheLogRegex2 "(.+)(\")( )((\")(.+)(\"))"

#define serveur "(http:\\/\\/intranet-if.insa-lyon.fr)"

#define apacheLogRegex apacheLogRegex1 serveur apacheLogRegex2

static const string extention="html";

static const int posHeure=3;
static const int posRefreur=26;
static const int posExtCible=14;
static const int posPointCible=13;
static const int posCibleSansExt=12;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void LectureLog::LectureFichier(Graph &unGraphe, bool optionE, int heure)
{
    string line;
    ifstream file;
    file.open(nomFichier);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (!optionE && heure < 0)
            {
                insertionSansOptions(line, unGraphe);
            }
            else if (optionE && heure < 0)
            {
                insertionsOptionE(line, unGraphe);
            }
            else if (!optionE && heure >= 0)
            {
                insertionsOptionHeure(line, unGraphe, heure);
            }
            else
            {
                insertionsOptionHeureEtE(line, unGraphe, heure);
            }
        }

        file.close();
    }
    else {
        std::cerr << "Impossible d'ouvrir le fichier de log apache" << std::endl;
    }

}
//----- Fin de Méthode

void LectureLog::insertionSansOptions(const string & ligneLog, Graph &unGraphe)
{
    std::regex apacheLogRgex(apacheLogRegex);
    
    std::smatch matches;

    if (regex_match(ligneLog, matches, apacheLogRgex))
    {
        std::string cible = matches[posCibleSansExt];

        cible += matches[posPointCible];
        cible += matches[posExtCible];

        unGraphe.AjouteLogAuDictionnaire(matches[posRefreur], cible, ligneLog);
    }
}
//----- Fin de Méthode

void LectureLog::insertionsOptionE(const string& ligneLog, Graph &unGraphe)
{
    std::regex apacheLogRgex(apacheLogRegex);

    std::smatch matches;

    if (regex_match(ligneLog, matches, apacheLogRgex))
    {
        if (matches[posExtCible] == extention)
        {
            std::string cible = matches[posCibleSansExt];

            cible += matches[posPointCible];
            cible += matches[posExtCible];

            unGraphe.AjouteLogAuDictionnaire(matches[posRefreur], cible, ligneLog);
        }
    }
}
//----- Fin de Méthode

void LectureLog::insertionsOptionHeure(const string& ligneLog, Graph &unGraphe, int heure)
{
    std::regex apacheLogRgex(apacheLogRegex);

    std::smatch matches;

    if (regex_match(ligneLog, matches, apacheLogRgex))
    {
        int heureLog =std::stoi(matches[posHeure]);
        
        if (heureLog == heure)
        {  
            std::string cible = matches[posCibleSansExt];

            cible += matches[posPointCible];
            cible += matches[posExtCible];

            unGraphe.AjouteLogAuDictionnaire(matches[posRefreur], cible, ligneLog);
        }
    }
}
//----- Fin de Méthode

void LectureLog::insertionsOptionHeureEtE(const string& ligneLog, Graph &unGraphe, int heure)
{
    std::regex apacheLogRgex(apacheLogRegex);

    std::smatch matches;

    if (regex_match(ligneLog, matches, apacheLogRgex))
    {
        int heureLog = std::stoi(matches[posHeure]);
        
        if (matches[posExtCible] == extention && (heureLog == heure))
        {
            std::string cible = matches[posCibleSansExt];

            cible += matches[posPointCible];
            cible += matches[posExtCible];
            
            unGraphe.AjouteLogAuDictionnaire(matches[posRefreur], cible, ligneLog);
        }
    }
}
//----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
LectureLog::LectureLog(const LectureLog &unlecturelog)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <LectureLog>" << endl;
#endif
} //----- Fin de LectureLog (constructeur de copie)

LectureLog::LectureLog(const string& unNomFichier)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LectureLog>" << endl;
#endif
    nomFichier = std::move(unNomFichier);
} //----- Fin de LectureLog

LectureLog::~LectureLog()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LectureLog>" << endl;
#endif
} //----- Fin de ~LectureLog

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

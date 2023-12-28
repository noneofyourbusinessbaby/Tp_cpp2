//---------- Réalisation de la classe <lecturelog> (fichier lecturelog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "lecturelog.h"
#include "Graph.h"
#include <regex>

//------------------------------------------------------------- Constantes

// TODO: static const
string apacheLogRegex1= "(\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3})( - - \\[\\d{2}\\/[a-zA-Z]{3}\\/\\d{4}:\\d{2}:\\d{2}:)(\\d{2})( )(\\+|\\-)(\\d{4})(]\\ )((\")(GET|POST|HEAD|OPTIONS)( ))(\\/.+)(\\.)(.+)( )(HTTP\\/1\\.(1|0))(\")( )(\\d{3})( )(\\d+)( )(\")";
string serveur= "(http:\\/\\/intranet\\-if.insa-lyon.fr)";
string apacheLogRegex2="(.+)(\")( )((\")(.+)(\"))";

const string apacheLogRegex=apacheLogRegex1+serveur+apacheLogRegex2;
const string extention="html";
const int posCibleSansExt=12;
const int posPointCible=13;
const int posExtCible=14;
const int posRefreur=26;
const int posHeure=3;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// TODO: optionE et heure en paramètre ne doivent pas avoir la valeur par default ici mais QUE dans le .h !!!
void lecturelog::lectureFichier(Graph &unGraphe, bool optionE = false, int heure = -1)
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
    }
    file.close();
}
//----- Fin de Méthode

void lecturelog::insertionSansOptions(string ligneLog, Graph &unGraphe)
{

    std::regex apacheLogRgex(apacheLogRegex);
    std::smatch ensembleElements;
    if (regex_match(ligneLog, ensembleElements, apacheLogRgex))
    {
        std::string cible = ensembleElements[posCibleSansExt];
        cible += ensembleElements[posPointCible];
        cible += ensembleElements[posExtCible];
        unGraphe.ajouteLogAuDictionnaire(ensembleElements[posRefreur], cible, ligneLog);
    }
}
//----- Fin de Méthode

void lecturelog::insertionsOptionE(string ligneLog, Graph &unGraphe)
{

    std::regex apacheLogRgex(apacheLogRegex);
    std::smatch ensembleElements;
    if (regex_match(ligneLog, ensembleElements, apacheLogRgex))
    {
        if (ensembleElements[posExtCible] == extention)
        {
            std::string cible = ensembleElements[posCibleSansExt];
            cible += ensembleElements[posPointCible];
            cible += ensembleElements[posExtCible];
            unGraphe.ajouteLogAuDictionnaire(ensembleElements[posRefreur], cible, ligneLog);
        }
    }
}
//----- Fin de Méthode

void lecturelog::insertionsOptionHeure(string ligneLog, Graph &unGraphe, int heure)
{
    std::regex apacheLogRgex(apacheLogRegex);
    std::smatch ensembleElements;
    if (regex_match(ligneLog, ensembleElements, apacheLogRgex))
    {
        int heureLog =std::stoi(ensembleElements[posHeure]);
        
        if (heureLog == heure )
        {  
            std::string cible = ensembleElements[posCibleSansExt];
            cible += ensembleElements[posPointCible];
            cible += ensembleElements[posExtCible];
            unGraphe.ajouteLogAuDictionnaire(ensembleElements[posRefreur], cible, ligneLog);
        }
    }
}
//----- Fin de Méthode

void lecturelog::insertionsOptionHeureEtE(string ligneLog, Graph &unGraphe, int heure)
{

    std::regex apacheLogRgex(apacheLogRegex);
    std::smatch ensembleElements;
    if (regex_match(ligneLog, ensembleElements, apacheLogRgex))
    {
        int heureLog = std::stoi(ensembleElements[posHeure]);
        if (ensembleElements[posExtCible] == extention && (heureLog == heure))
        {
            std::string cible = ensembleElements[posCibleSansExt];
            cible += ensembleElements[posPointCible];
            cible += ensembleElements[posExtCible];
            unGraphe.ajouteLogAuDictionnaire(ensembleElements[posRefreur], cible, ligneLog);
        }
    }
}
//----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
lecturelog::lecturelog(const lecturelog &unlecturelog)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <lecturelog>" << endl;
#endif
} //----- Fin de lecturelog (constructeur de copie)

lecturelog::lecturelog(string unNomFichier)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <lecturelog>" << endl;
#endif
    nomFichier = unNomFichier;
} //----- Fin de lecturelog

lecturelog::~lecturelog()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <lecturelog>" << endl;
#endif
} //----- Fin de ~lecturelog

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

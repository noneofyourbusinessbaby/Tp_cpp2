using namespace std;
#include <iostream>
#include <string>
#include <log.h>

//------------------------------------------------------ Include personnel
#include "graph.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type graph::Méthode ( liste des paramètres )
void graph::ajouteNoeudAuDictionnaire(string refreur,string cible,string unLog)
// Algorithme :
//
{   
    log classelog=log(unLog);

    if (dictionnaire_noeuds.count(refreur)) // si on a déjà le tuple du réfreur
    {
        if (dictionnaire_noeuds[refreur].dictionnaire_sous_noeuds.count(cible)) // si la cible est déjà dedans on rajoute le log au sous noeud
        {
            dictionnaire_noeuds[refreur].dictionnaire_sous_noeuds[cible].nbhits++;
            dictionnaire_noeuds[refreur].dictionnaire_sous_noeuds[cible].vecteur_logs.push_back(classelog); //ATTENTION ICI ce n'est pas une référence comment créer une référence
        }
        else // sinon on la crée
        {
            dictionnaire_noeuds[refreur].dictionnaire_sous_noeuds[cible]=sousnoeud(classelog);
        }
        
    }
    else // le tuple du réfreur n'existe pas il faut créer un noeud en plus de tout ça
    {
        noeud leNoeud=noeud(); // on appelle le constructeur de la classe
        sousnoeud lesousnoeud=sousnoeud(classelog);
        leNoeud.dictionnaire_sous_noeuds[cible]=lesousnoeud;
        dictionnaire_noeuds[refreur]=leNoeud;
    }

    // on incrémente des hits de la destination
    if (dictionnaire_noeuds.count(cible)) // si on a déjà le tuple du réfreur
    {
        dictionnaire_noeuds[cible].hits++;
    }
    else
    {
        dictionnaire_noeuds[cible]=noeud();
    }

} //----- Fin de Méthode

vector<vector<string,int>> graph::faitClassement()
// Algorithme :
//
{
    vector<vector<string,int>> unVecteur;
    
}
//------------------------------------------------- Surcharge d'opérateurs
graph & graph::operator = ( const graph & ungraph )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
graph::graph ( const graph & ungraph )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <graph>" << endl;
#endif
} //----- Fin de graph (constructeur de copie)


graph::graph ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <graph>" << endl;
#endif
} //----- Fin de graph


graph::~graph ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <graph>" << endl;
#endif
} //----- Fin de ~graph


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

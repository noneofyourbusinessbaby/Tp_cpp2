using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Graph.h"
#include "Noeud.h"
#include "SousNoeud.h"

//------------------------------------------------------------- Constantes
static const int NB_SOMMETS = 10;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Graph::Méthode ( liste des paramètres )

void Graph::AjouteLogAuDictionnaire(const string& refreur, const string& cible, const string& unLog)
// Algorithme :
//
{
    if (dictionnaire_noeuds.count(refreur) > 0) // si on a déjà le tuple du réfreur
    {        
        Noeud& noeud_refreur = dictionnaire_noeuds[refreur];

        noeud_refreur.AddLogCibleNoeud(cible, unLog);
    }
    else // le tuple du réfreur n'existe pas il faut créer un Noeud en plus de tout ça
    {
        dictionnaire_noeuds[refreur] = Noeud();
        dictionnaire_noeuds[refreur].AddLogCibleNoeud(cible, unLog);      
    }

    // on incrémente des hits de la destination
    if (dictionnaire_noeuds.count(cible)) // si on a déjà le tuple de la cible
    {
        dictionnaire_noeuds[cible].Hit();
    }
    else
    {
        dictionnaire_noeuds[cible] = Noeud();
        dictionnaire_noeuds[cible].Hit(); // on incrémente le nb de hits 
    }
} //----- Fin de Méthode

void Graph::AfficheHitsMax()
{
    // on génère un multimap où hits sont en clé et la cible en string on fait en sorte d'insérer en triant par ordre croissant
    multimap<int, string> dictionnaire;

    int compteur = 0;

    for (map<string, Noeud>::const_iterator iterateur = dictionnaire_noeuds.begin(); iterateur != dictionnaire_noeuds.end(); ++iterateur)
    {
        multimap<int, string>::iterator position = dictionnaire.lower_bound(iterateur->second.GetHits());
        dictionnaire.emplace_hint(position, iterateur->second.GetHits(), iterateur->first);
    }

    // on parcourt dans le sens inverse
    int prevVal=-1;
    for (map<int, string>::const_reverse_iterator iterateur = dictionnaire.rbegin(); iterateur != dictionnaire.rend(); ++iterateur) // on incrémente à gauche pour pas créer de copies
    {
        cout << iterateur->second << " " << "(" << iterateur->first << " hits)" << endl;

        if (iterateur->first != prevVal)
        {
            compteur++;
        }

        if (compteur==NB_SOMMETS){
            break;
        }

        prevVal=iterateur->first;
    }
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

ostream &operator<<(std::ostream &out, const Graph& graph)
{
    // étape 1 : on imprime les noeuds
    out << "digraph {" << endl;

    for (map<string, Noeud>::const_iterator iterateur = graph.dictionnaire_noeuds.begin(); iterateur != graph.dictionnaire_noeuds.end(); ++iterateur) // on incrémente à gauche pour pas créer de copies
    {
        out << "node" << iterateur->second.GetNumInstance() << " [label=\"" << iterateur->first << "\"];" << endl;
    }

    // étape 2 : on imprime les arrêtes
    for (map<string, Noeud>::const_iterator iterateur = graph.dictionnaire_noeuds.begin(); iterateur != graph.dictionnaire_noeuds.end(); ++iterateur) // on incrémente à gauche pour pas créer de copies
    {
        for (map<string, SousNoeud>::const_iterator iterateur2 = iterateur->second.GetDictionnaireSousNoeud().begin(); iterateur2 != iterateur->second.GetDictionnaireSousNoeud().end(); ++iterateur2) // on incrémente à gauche pour pas créer de copies
        {
            map<string, Noeud>::const_iterator iterateur3 = graph.dictionnaire_noeuds.find(iterateur2->first);
            out << "node" << iterateur->second.GetNumInstance() << " -> node" << iterateur3->second.GetNumInstance() << " [label=\"" << iterateur2->second.GetNbhits() << "\"];" << endl;
        }
    }
    out << "}";
    
    return out;
} //----- Fin de operator <<

//-------------------------------------------- Constructeurs - destructeur
Graph::Graph(const Graph &unGraph)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Graph>" << endl;
#endif
} //----- Fin de Graph (constructeur de copie)

Graph::Graph()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Graph>" << endl;
#endif
} //----- Fin de Graph

Graph::~Graph()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Graph>" << endl;
#endif
} //----- Fin de ~Graph

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

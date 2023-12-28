using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Graph.h"
#include "noeud.h"
#include "sousnoeud.h"

//------------------------------------------------------------- Constantes
#define NB_SOMMETS 10
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Graph::Méthode ( liste des paramètres )

void Graph::ajouteLogAuDictionnaire(string refreur, string cible, string unLog)
// Algorithme :
//
{
    if (dictionnaire_noeuds.count(refreur) > 0) // si on a déjà le tuple du réfreur
    {
        // TODO: la if faut absolument que tu garde dictionnaire_noeuds[refreur] dans une variable sinon il va parcourir ton dic et le chercher à chaque fois
        // const auto& noeud_refreur = dictionnaire_noeuds[refreur];
        
        if (dictionnaire_noeuds[refreur].dictionnaire_sous_noeuds.count(cible) > 0) // si la cible est déjà dedans on rajoute le log au sous noeud
        {
            dictionnaire_noeuds[refreur].dictionnaire_sous_noeuds[cible].nbhits++;
            dictionnaire_noeuds[refreur].dictionnaire_sous_noeuds[cible].vecteur_logs.push_back(unLog);
        }
        else // sinon on la crée
        {
            dictionnaire_noeuds[refreur].dictionnaire_sous_noeuds[cible] = sousnoeud();
            dictionnaire_noeuds[refreur].dictionnaire_sous_noeuds[cible].nbhits = 1;
            dictionnaire_noeuds[refreur].dictionnaire_sous_noeuds[cible].vecteur_logs.push_back(unLog);
        }
    }
    else // le tuple du réfreur n'existe pas il faut créer un noeud en plus de tout ça
    {

        dictionnaire_noeuds[refreur] = noeud();
        dictionnaire_noeuds[refreur].dictionnaire_sous_noeuds[cible] = sousnoeud();
        dictionnaire_noeuds[refreur].dictionnaire_sous_noeuds[cible].nbhits = 1;
        dictionnaire_noeuds[refreur].dictionnaire_sous_noeuds[cible].vecteur_logs.push_back(unLog);
    }

    // on incrémente des hits de la destination
    if (dictionnaire_noeuds.count(cible)) // si on a déjà le tuple de la cible
    {
        dictionnaire_noeuds[cible].hits++;
    }
    else
    {
        dictionnaire_noeuds[cible] = noeud();
        dictionnaire_noeuds[cible].hits=1;
    }

} //----- Fin de Méthode

void Graph::afficheHitsMax()
{
    // on génère un multimap où hits sont en clé et la cible en string on fait en sorte d'insérer en triant par ordre croissant
    multimap<int, string> dictionnaire;

    int compteur = 0;

    for (map<string, noeud>::const_iterator iterateur = dictionnaire_noeuds.begin(); iterateur != dictionnaire_noeuds.end(); ++iterateur)
    {
        multimap<int, string>::iterator position = dictionnaire.lower_bound(iterateur->second.hits);
        dictionnaire.emplace_hint(position, iterateur->second.hits, iterateur->first);
    }

    // on parcourt dans le sens inverse
    int prevVal=-1;
    for (map<int, string>::const_reverse_iterator iterateur = dictionnaire.rbegin(); iterateur != dictionnaire.rend(); ++iterateur) // on incrémente à gauche pour pas créer de copies
    {
        cout << iterateur->second << " "
             << "(" << iterateur->first << " hits)" << endl;

        if (iterateur->first != prevVal)
        {
            compteur++;
        }
        if (compteur==10){break;}
        prevVal=iterateur->first;
    }
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

ostream &Graph::operator<<(std::ostream &out) const
{
    // TODO: UTILISER OUT PAS COUT PARTOUT
    // étape 1 : on imprime les noeuds
    out << "digraph {" << endl;

    for (map<string, noeud>::const_iterator iterateur = dictionnaire_noeuds.begin(); iterateur != dictionnaire_noeuds.end(); ++iterateur) // on incrémente à gauche pour pas créer de copies
    {
        out << "node" << iterateur->second.numinstance << " [label=\"" << iterateur->first << "\"];" << endl;
    }

    // étape 2 : on imprime les arrêtes
    for (map<string, noeud>::const_iterator iterateur = dictionnaire_noeuds.begin(); iterateur != dictionnaire_noeuds.end(); ++iterateur) // on incrémente à gauche pour pas créer de copies
    {
        for (map<string, sousnoeud>::const_iterator iterateur2 = iterateur->second.dictionnaire_sous_noeuds.begin(); iterateur2 != iterateur->second.dictionnaire_sous_noeuds.end(); ++iterateur2) // on incrémente à gauche pour pas créer de copies
        {
            map<string, noeud>::const_iterator iterateur3 = dictionnaire_noeuds.find(iterateur2->first);
            out << "node" << iterateur->second.numinstance << " -> node" << iterateur3->second.numinstance << " [label=\"" << iterateur2->second.nbhits << "\"];" << endl;
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

using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "graph.h"
#include "noeud.h"
#include "sousnoeud.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type graph::Méthode ( liste des paramètres )

void graph::ajouteLogAuDictionnaire(string refreur, string cible, string unLog)
// Algorithme :
//
{
    if (dictionnaire_noeuds.count(refreur) > 0) // si on a déjà le tuple du réfreur
    {
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

void graph::afficheHitsMax()
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
    for (map<int, string>::const_reverse_iterator iterateur = dictionnaire.rbegin(); iterateur != dictionnaire.rend() && compteur < NB_SOMMETS; ++iterateur) // on incrémente à gauche pour pas créer de copies
    {
        cout << iterateur->second << " "
             << "(" << iterateur->first << " hits)" << endl;

        if (iterateur->first != prevVal)
        {
            compteur++;
        }
        prevVal=iterateur->first;
    }
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

ostream &graph::operator<<(std::ostream &out) const
{
    // étape 1 : on imprime les noeuds
    cout << "digraph {" << endl;
    for (map<string, noeud>::const_iterator iterateur = dictionnaire_noeuds.begin(); iterateur != dictionnaire_noeuds.end(); ++iterateur) // on incrémente à gauche pour pas créer de copies
    {
        cout << "node" << iterateur->second.numinstance << " [label=\"" << iterateur->first << "\"];" << endl;
    }

    // étape 2 : on imprime les arêtes
    for (map<string, noeud>::const_iterator iterateur = dictionnaire_noeuds.begin(); iterateur != dictionnaire_noeuds.end(); ++iterateur) // on incrémente à gauche pour pas créer de copies
    {
        for (map<string, sousnoeud>::const_iterator iterateur2 = iterateur->second.dictionnaire_sous_noeuds.begin(); iterateur2 != iterateur->second.dictionnaire_sous_noeuds.end(); ++iterateur2) // on incrémente à gauche pour pas créer de copies
        {
            map<string, noeud>::const_iterator iterateur3 = dictionnaire_noeuds.find(iterateur2->first);
            cout << "node" << iterateur->second.numinstance << " -> node" << iterateur3->second.numinstance << " [label=\"" << iterateur2->second.nbhits << "\"];" << endl;
        }
    }
    cout << "}";
    return out;
} //----- Fin de operator <<

//-------------------------------------------- Constructeurs - destructeur
graph::graph(const graph &ungraph)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <graph>" << endl;
#endif
} //----- Fin de graph (constructeur de copie)

graph::graph()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <graph>" << endl;
#endif
} //----- Fin de graph

graph::~graph()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <graph>" << endl;
#endif
} //----- Fin de ~graph

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

#include "main.h"

#include "Graph.h"
#include "Noeud.h"
#include "LectureLog.h"

#include <cstring>
#include <fstream>
#include <iostream>

// TODO: #define opE "-e"
const char *opE = "-e";
const char *opT ="-t";
const char *opG = "-g";

// TODO: Supprimer
enum tests
{
    Test0,
    Test1,
    Test2,
    Test3
};

// TODO: Tu peux pas faire ca ! Tu est pas sensé modifier la classe Noeud depuis le main
int Noeud::nbinstances = 0;

// void genereFichierDot(const string& nomGraph, const Graph &leGraphe)
void genereFichierDot(string nomGraph, const Graph &leGraphe)
{
    ofstream out(nomGraph);

    std::ofstream fichierDot(nomGraph);
    std::streambuf *base = std::cout.rdbuf();

    std::cout.rdbuf(fichierDot.rdbuf()); // attention à retourner la sortie
    
    // TODO: Ca c'est moche, leGraph << cout !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    leGraphe.operator<<(cout);    

    std::cout.rdbuf(base);
}

int main(int argc, char *argv[])
{

    if (argc == 1)
    {
        std::cout << "Veuillez saisir un nom de fichier (.log) au lancement de l'application" << std::endl;
    }
    else
    {
        bool optionE = false;

        // TODO: string nomGraph; PAS BESOIN DE " ". Pour verifier que nomGraph est vide, on fait nomGraph.empty()
        std::string nomGraph = " ";
        std::string nomFichier = " ";

        int heure = -1, i = 1;

        while (i < argc)
        {
            // TODO: if(argv[i] == opE)
            if (std::strcmp(argv[i], opE) == 0)
            {
                optionE = true;
                i++;
            }
            else if (std::strcmp(argv[i], opT) == 0)
            {             
                heure = std::stoi(argv[i + 1]);
             
                if (heure < 0 || heure > 23)
                {
                    std::cout << "L'heure doit être comprise entre 0 et 23" << std::endl;

                    return 0;
                }
             
                i += 2; // on récupère l'heure et on la saute
            }
            else if (std::strcmp(argv[i], opG) == 0)
            {
                // TODO: nomGraph = argv[i + 1];
                nomGraph = std::string(argv[i + 1]);
                i += 2; // on récupère le nom et on le saute
            }
            else // sinon on est sûr de récupérer le nom du fichier
            {
                // TODO: nomFichier = argv[i];
                nomFichier = std::string(argv[i]);

                i++;
            }
        }
        // std::cout << "Ensemble des options sélectionnées" << std::endl;
        // std::cout << optionE << " " << nomGraph << " " << heure << " " << nomFichier << std::endl;

        // on génère le Graphe à partir des arguments
        Graph leGraphe;

        LectureLog classeLecture = LectureLog(nomFichier);

        classeLecture.lectureFichier(leGraphe, optionE, heure);

        // on dénère le fichier dot

        // TODO: !nomGraph.empty()
        if (nomGraph != " ")
        {
            genereFichierDot(nomGraph, leGraphe); // on affiche les 10 premiers avec le plus de hits

            std::cout << "Dot-file " << nomGraph << " generated" << std::endl;

            
        }
        leGraphe.afficheHitsMax();
    }

    return 0;
}

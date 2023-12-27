#include <iostream>
#include <cstring>
#include "lecturelog.h"
#include "graph.h"
#include "noeud.h"
#include <fstream>
const char *opE = "-e";
const char *opT = "-t";
const char *opG = "-g";

string liste_repos[] = {
    "tests/Test0/unFichier.dot.outfile",
    "tests/Test1/unFichier.dot.outfile",
    "tests/Test2/unFichier.dot.outfile",
    "tests/Test3/unFichier.dot.outfile",
};

enum tests
{
    Test0,
    Test1,
    Test2,
    Test3
};

int noeud::nbinstances = 0;

void genereFichierDot(string nomGraph, const graph &leGraphe)
{
    ofstream out(nomGraph);
    std::ofstream fichierDot(nomGraph);
    std::streambuf *base = std::cout.rdbuf();
    std::cout.rdbuf(fichierDot.rdbuf()); // attention à retourner la sortie
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
        std::string nomGraph = " ";
        std::string nomFichier = " ";
        int heure = -1, i = 1;
        while (i < argc)
        {
            if (std::strcmp(argv[i], opE) == 0)
            {
                optionE = true;
                i++;
            }
            else if (std::strcmp(argv[i], opT) == 0)
            {
                heure = std::stoi(argv[i + 1]);
                i += 2; // on récupère l'heure et on la saute
            }
            else if (std::strcmp(argv[i], opG) == 0)
            {
                nomGraph = std::string(argv[i + 1]);
                i += 2; // on récupère le nom et on le saute
            }
            else // sinon on est sûr de récupérer le nom du fichier
            {
                nomFichier = std::string(argv[i]);
                i++;
            }
        }
        // std::cout << "Ensemble des options sélectionnées" << std::endl;
        // std::cout << optionE << " " << nomGraph << " " << heure << " " << nomFichier << std::endl;

        // on génère le graphe à partir des arguments
        graph leGraphe;
        lecturelog classeLecture = lecturelog(nomFichier);
        classeLecture.lectureFichier(leGraphe, optionE, heure);

        // on dénère le fichier dot
        if (nomGraph != " ")
        {

            if (optionE && heure < 0)
            {
                genereFichierDot(liste_repos[Test2], leGraphe);
            }
            else if (!optionE && heure >= 0)
            {
                genereFichierDot(liste_repos[Test1], leGraphe);
            }
            else if (!optionE && heure < 0)
            {
                genereFichierDot(liste_repos[Test0], leGraphe);
            }
            else
            {
                genereFichierDot(liste_repos[Test3], leGraphe);
            }

            genereFichierDot(nomGraph, leGraphe);
            std::cout << "Dot-file " << nomGraph << " generated" << std::endl;
        }

        // on affiche les 10 premiers avec le plus de hits
        leGraphe.afficheHitsMax();
    }

    return 0;
}

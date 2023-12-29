#include "main.h"

#include "Graph.h"
#include "Noeud.h"
#include "LectureLog.h"

#include <fstream>
#include <iostream>

static const std::string opE = "-e";
static const std::string opT = "-t";
static const std::string opG = "-g";

static void genereFichierDot(const std::string& nomGraph, const Graph &leGraphe)
{
    ofstream out(nomGraph);

    std::ofstream fichierDot(nomGraph);
    std::streambuf *base = std::cout.rdbuf();

    std::cout.rdbuf(fichierDot.rdbuf()); // attention à retourner la sortie
    
    cout<<leGraphe;

    std::cout.rdbuf(base);
}

int main(int argc, char *argv[])
{

    // Ce code permet d'appeler les bons services selon les options, it assumes les bons paramètres sont donnés

    if (argc == 1)
    {
        std::cerr << "Veuillez saisir un nom de fichier (.log) au lancement de l'application" << std::endl;

        return 0;
    }
    else
    {
        bool optionE = false;

        std::string nomGraph;
        std::string nomFichier;

        int heure = -1, i = 1;

        while (i < argc)
        {
            if (argv[i] == opE)
            {
                optionE = true;
                i++;
            }
            else if (argv[i]==opT)
            {             
                heure = std::stoi(argv[i + 1]);
             
                if (heure < 0 || heure > 23)
                {
                    std::cerr << "L'heure doit être comprise entre 0 et 23" << std::endl;

                    return 0;
                }
             
                i += 2; // on récupère l'heure et on la saute
            }
            else if (argv[i] == opG) 
            {
                nomGraph = argv[i + 1];

                i += 2; // on récupère le nom et on le saute
            }
            else // sinon on est sûr de récupérer le nom du fichier
            {
                nomFichier = argv[i];

                i++;
            }
        }
        // on génère le Graphe à partir des arguments
        Graph leGraphe;

        LectureLog classeLecture(nomFichier);

        classeLecture.LectureFichier(leGraphe, optionE, heure);

        // on génère le fichier dot

        if (!nomGraph.empty())
        {
            genereFichierDot(nomGraph, leGraphe); // on affiche les 10 premiers avec le plus de hits

            std::cout << "Dot-file " << nomGraph << " generated" << std::endl;
        }

        leGraphe.AfficheHitsMax();
    }

    return 0;
}

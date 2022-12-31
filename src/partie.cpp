#include <iostream>
#include <utility>
#include "partie.h"
#include "fauve.h"
#include "terrain.h"

partie::partie() : d_terrain{}
{}

partie::partie(terrain& t) : d_terrain{std::move(t)}
{}

void partie::afficher_terrain() {
    std::cout << '\n';
    for (int i = 0; i < d_terrain.getHauteur(); i++) {
        for (int j = 0; j < d_terrain.getLargeur(); j++) {
            // Affiche le joueur
            if (j == d_terrain.getJoueurColonne() && i == d_terrain.getJoueurLigne()) {
                std::cout << " J ";
                continue;
            }

            // Affiche les fauves
            bool fauve_trouve = false;
            for (const auto& f : d_terrain.getFauves()) {
                if (f->getColonne() == j && f->getLigne() == i && f->getEstVivant()) {
                    std::cout << " " << f->getSymbole() << " ";
                    fauve_trouve = true;
                    break;
                }
            }
            if (fauve_trouve) continue;

            // Affiche les pièges
            bool piege_trouve = false;
            for (const piege& p : d_terrain.getPieges()) {
                if (p.getColonne() == j && p.getLigne() == i) {
                    std::cout << " P ";
                    piege_trouve = true;
                    break;
                }
            }
            if (piege_trouve) continue;

            // Affiche une case vide
            std::cout << " . ";
        }
        std::cout << std::endl;
    }
    std::cout << '\n';
}

bool partie::est_deplacement_dans_bordures() {
    return (!(d_terrain.getJoueurColonne() > d_terrain.getLargeur()-1 || d_terrain.getJoueurColonne() < 0 || d_terrain.getJoueurLigne() < 0 || d_terrain.getJoueurLigne() > d_terrain.getHauteur()-1));
}

bool partie::joueur_se_deplace() {
    std::cout << "Où souhaitez-vous déplacer le joueur ?" << '\n';
    std::cout << "(1) Haut" << '\n';
    std::cout << "(2) Bas" << '\n';
    std::cout << "(3) Droite" << '\n';
    std::cout << "(4) Gauche" << '\n';
    std::cout << "(5) Haut-Gauche" << '\n';
    std::cout << "(6) Haut-Droite" << '\n';
    std::cout << "(7) Bas-Gauche" << '\n';
    std::cout << "(8) Bas-Droite" << '\n';

    int direction;
    std::cin >> direction;
    bool deplacementValide = true;

    switch (direction) {
        case 1:
            d_terrain.setJoueurLigne(d_terrain.getJoueurLigne()-1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.setJoueurLigne(d_terrain.getJoueurLigne()+1);
                deplacementValide = false;
            }
            break;
        case 2:
            d_terrain.setJoueurLigne(d_terrain.getJoueurLigne()+1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.setJoueurLigne(d_terrain.getJoueurLigne()-1);
                deplacementValide = false;
            }
            break;
        case 3:
            d_terrain.setJoueurColonne(d_terrain.getJoueurColonne()+1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.setJoueurColonne(d_terrain.getJoueurColonne()-1);
                deplacementValide = false;
            }
            break;
        case 4:
            d_terrain.setJoueurColonne(d_terrain.getJoueurColonne()-1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.setJoueurColonne(d_terrain.getJoueurColonne()+1);
                deplacementValide = false;
            }
            break;
        case 5:
            d_terrain.setJoueurColonne(d_terrain.getJoueurColonne()-1);
            d_terrain.setJoueurLigne(d_terrain.getJoueurColonne()-1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.setJoueurColonne(d_terrain.getJoueurColonne()+1);
                d_terrain.setJoueurLigne(d_terrain.getJoueurColonne()+1);
                deplacementValide = false;
            }
            break;
        case 6:
            d_terrain.setJoueurColonne(d_terrain.getJoueurColonne()+1);
            d_terrain.setJoueurLigne(d_terrain.getJoueurColonne()-1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.setJoueurColonne(d_terrain.getJoueurColonne()-1);
                d_terrain.setJoueurLigne(d_terrain.getJoueurColonne()+1);
                deplacementValide = false;
            }
            break;
        case 7:
            d_terrain.setJoueurColonne(d_terrain.getJoueurColonne()-1);
            d_terrain.setJoueurLigne(d_terrain.getJoueurColonne()+1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.setJoueurColonne(d_terrain.getJoueurColonne()+1);
                d_terrain.setJoueurLigne(d_terrain.getJoueurColonne()-1);
                deplacementValide = false;
            }
            break;
        case 8:
            d_terrain.setJoueurColonne(d_terrain.getJoueurColonne()+1);
            d_terrain.setJoueurLigne(d_terrain.getJoueurColonne()+1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.setJoueurColonne(d_terrain.getJoueurColonne()-1);
                d_terrain.setJoueurLigne(d_terrain.getJoueurColonne()-1);
                deplacementValide = false;
            }
            break;
        default:
            deplacementValide = false;
    }

    if (!deplacementValide) std::cout << "Déplacement invalide veuillez ressayer !\n";
    return deplacementValide;
}

void partie::faire_bouger_fauves() {
    for (const auto& fauve : d_terrain.getFauves()) {
        fauve->deplacement(d_terrain);
    }
}

bool partie::joueur_en_vie() {
    for (const auto & fauve : d_terrain.getFauves()) {
        if (fauve->getColonne() == d_terrain.getJoueurColonne() && fauve->getLigne() == d_terrain.getJoueurLigne() && fauve->getEstVivant()) {
            return false;
        }
    }
    return true;
}

bool partie::fauves_en_vie() {
    for (const auto& fauve : d_terrain.getFauves()) {
        if (fauve->getEstVivant()) return true;
    }
    return false;
}

void partie::run() {
    while (joueur_en_vie() && fauves_en_vie()) {
        // Affichage du terrain
        afficher_terrain();

        // Déplacement du joueur
        while (!joueur_se_deplace());

        // Déplacement des fauves
        faire_bouger_fauves();
    }

    // Fin de la partie
    if (joueur_en_vie()) {
        std::cout << "Vous avez gagné !" << std::endl;
    } else {
        std::cout << "Vous avez perdu !" << std::endl;
    }

    afficher_terrain();
}









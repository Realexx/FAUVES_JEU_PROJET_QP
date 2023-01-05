#include <iostream>
#include <utility>
#include "partie.h"
#include "fauve.h"
#include "terrain.h"

partie::partie() : d_terrain{}
{}

partie::partie(terrain& t) : d_terrain{std::move(t)}, d_copy_terrain_initial{std::move(t)} // TODO debugger pour que 'd_copy_terrain_initial' contienne la même chose que 'd_terrain' (il faudrait probablement utiliser un constructeur par recopie ou une surcharge d'opérateur =)
// le move fait bugger imo
{}

bool partie::est_deplacement_dans_bordures() {
    return (!(d_terrain.get_joueur_colonne() > d_terrain.get_largeur() - 1 || d_terrain.get_joueur_colonne() < 0 ||
            d_terrain.get_joueur_ligne() < 0 || d_terrain.get_joueur_ligne() > d_terrain.get_hauteur() - 1));
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
            d_terrain.set_joueur_ligne(d_terrain.get_joueur_ligne() - 1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.set_joueur_ligne(d_terrain.get_joueur_ligne() + 1);
                deplacementValide = false;
            }
            break;
        case 2:
            d_terrain.set_joueur_ligne(d_terrain.get_joueur_ligne() + 1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.set_joueur_ligne(d_terrain.get_joueur_ligne() - 1);
                deplacementValide = false;
            }
            break;
        case 3:
            d_terrain.set_joueur_colonne(d_terrain.get_joueur_colonne() + 1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.set_joueur_colonne(d_terrain.get_joueur_colonne() - 1);
                deplacementValide = false;
            }
            break;
        case 4:
            d_terrain.set_joueur_colonne(d_terrain.get_joueur_colonne() - 1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.set_joueur_colonne(d_terrain.get_joueur_colonne() + 1);
                deplacementValide = false;
            }
            break;
        case 5:
            d_terrain.set_joueur_colonne(d_terrain.get_joueur_colonne() - 1);
            d_terrain.set_joueur_ligne(d_terrain.get_joueur_colonne() - 1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.set_joueur_colonne(d_terrain.get_joueur_colonne() + 1);
                d_terrain.set_joueur_ligne(d_terrain.get_joueur_colonne() + 1);
                deplacementValide = false;
            }
            break;
        case 6:
            d_terrain.set_joueur_colonne(d_terrain.get_joueur_colonne() + 1);
            d_terrain.set_joueur_ligne(d_terrain.get_joueur_colonne() - 1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.set_joueur_colonne(d_terrain.get_joueur_colonne() - 1);
                d_terrain.set_joueur_ligne(d_terrain.get_joueur_colonne() + 1);
                deplacementValide = false;
            }
            break;
        case 7:
            d_terrain.set_joueur_colonne(d_terrain.get_joueur_colonne() - 1);
            d_terrain.set_joueur_ligne(d_terrain.get_joueur_colonne() + 1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.set_joueur_colonne(d_terrain.get_joueur_colonne() + 1);
                d_terrain.set_joueur_ligne(d_terrain.get_joueur_colonne() - 1);
                deplacementValide = false;
            }
            break;
        case 8:
            d_terrain.set_joueur_colonne(d_terrain.get_joueur_colonne() + 1);
            d_terrain.set_joueur_ligne(d_terrain.get_joueur_colonne() + 1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.set_joueur_colonne(d_terrain.get_joueur_colonne() - 1);
                d_terrain.set_joueur_ligne(d_terrain.get_joueur_colonne() - 1);
                deplacementValide = false;
            }
            break;
        default:
            deplacementValide = false;
    }

    if (!deplacementValide) std::cout << "Déplacement invalide veuillez ressayer !\n";
    return deplacementValide;
}

bool partie::joueur_se_deplaceExpert() {
    std::cout << "Où souhaitez-vous déplacer le joueur ?" << '\n';
    std::cout << "(1) Haut" << '\n';
    std::cout << "(2) Bas" << '\n';
    std::cout << "(3) Droite" << '\n';
    std::cout << "(4) Gauche" << '\n';

    int direction;
    std::cin >> direction;
    bool deplacementValide = true;

    switch (direction) {
        case 1:
            d_terrain.set_joueur_ligne(d_terrain.get_joueur_ligne() - 1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.set_joueur_ligne(d_terrain.get_joueur_ligne() + 1);
                deplacementValide = false;
            }
            break;
        case 2:
            d_terrain.set_joueur_ligne(d_terrain.get_joueur_ligne() + 1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.set_joueur_ligne(d_terrain.get_joueur_ligne() - 1);
                deplacementValide = false;
            }
            break;
        case 3:
            d_terrain.set_joueur_colonne(d_terrain.get_joueur_colonne() + 1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.set_joueur_colonne(d_terrain.get_joueur_colonne() - 1);
                deplacementValide = false;
            }
            break;
        case 4:
            d_terrain.set_joueur_colonne(d_terrain.get_joueur_colonne() - 1);
            if (!est_deplacement_dans_bordures()) {
                d_terrain.set_joueur_colonne(d_terrain.get_joueur_colonne() + 1);
                deplacementValide = false;
            }
            break;
        default:
            deplacementValide = false;
    }
    if (!deplacementValide) std::cout << "Deplacement invalide veuillez ressayer !\n";
    return deplacementValide;
}

void partie::faire_bouger_fauves() {
    for (const auto& fauve : d_terrain.get_fauves()) {
        fauve->deplacement(d_terrain);
    }
}

bool partie::joueur_en_vie() {
    for (const auto & fauve : d_terrain.get_fauves()) {
        if (fauve->get_colonne() == d_terrain.get_joueur_colonne() && fauve->get_ligne() == d_terrain.get_joueur_ligne() &&
            fauve->get_est_vivant()) {
            return false;
        }
    }
    return true;
}

bool partie::fauves_en_vie() {
    for (const auto& fauve : d_terrain.get_fauves()) {
        if (fauve->get_est_vivant()) return true;
    }
    return false;
}

void partie::run() {
    while (joueur_en_vie() && fauves_en_vie()) {
        // Affichage du terrain
        d_terrain.affiche();

        // Déplacement du joueur
        while (!joueur_se_deplace());

        // Déplacement des fauves
        faire_bouger_fauves();
    }

    // Fin de la partie
    if (joueur_en_vie()) {
        std::cout << "Vous avez gagne !" << std::endl;
    } else {
        std::cout << "Vous avez perdu !" << std::endl;
    }

    d_terrain.affiche();
}
void partie::runExpert() {
    while (joueur_en_vie() && fauves_en_vie()) {
        // Affichage du terrain
        d_terrain.affiche();

        // Déplacement du joueur
        while (!joueur_se_deplaceExpert());

        // Déplacement des fauves
        faire_bouger_fauves();
    }

    // Fin de la partie
    if (joueur_en_vie()) {
        std::cout << "Vous avez gagne !" << std::endl;
    } else {
        std::cout << "Vous avez perdu !" << std::endl;
    }

    d_terrain.affiche();
}

void partie::reinitialisation() {
    // TODO réinitialiser une partie en copiant le terrain stocké dans 'd_copy_terrain_initial' dans la variable 'd_terrain'
    // Il faut d'abord réussir à copier initialement 'd_terrain' dans 'd_copy_terrain_initial' ce qui ne marche pas pour le moment (voir ligne 10)
}










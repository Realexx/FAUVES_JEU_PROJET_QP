#include "terrain.h"
#include "fauve.h"
#include <utility>
#include <iostream>

terrain::terrain() : d_largeur{10}, d_hauteur{10} , d_position_joueur{0, 0}, d_fauves{}, d_pieges{}
{}

terrain::terrain(int largeur, int hauteur, position position_joueur)
: d_largeur{largeur}, d_hauteur{hauteur}, d_position_joueur{position_joueur}
{}

int terrain::get_largeur() const {
    return d_largeur;
}

int terrain::get_hauteur() const {
    return d_hauteur;
}

int terrain::get_joueur_ligne() const {
    return d_position_joueur.get_ligne();
}

int terrain::get_joueur_colonne() const {
    return d_position_joueur.get_colonne();
}

void terrain::set_joueur_ligne(int ligne) {
    d_position_joueur.set_ligne(ligne);
}

void terrain::set_joueur_colonne(int colonne) {
    d_position_joueur.set_colonne(colonne);
}

std::vector<piege> terrain::get_pieges() const {
    return d_pieges;
}

const std::vector<std::unique_ptr<fauve>>& terrain::get_fauves() {
    return d_fauves;
}

void terrain::ajoute_piege(piege p) {
    d_pieges.push_back(p);
}

void terrain::ajoute_fauve(std::unique_ptr<fauve> f) {
    d_fauves.push_back(std::move(f));
}

void terrain::affiche() {
    std::cout << '\n';
    for (int i = 0; i < get_hauteur(); i++) {
        for (int j = 0; j < get_largeur(); j++) {
            // Affiche le joueur
            if (j == get_joueur_colonne() && i == get_joueur_ligne()) {
                std::cout << " J ";
                continue;
            }

            // Affiche les fauves
            bool fauve_trouve = false;
            for (const auto& f : get_fauves()) {
                if (f->get_colonne() == j && f->get_ligne() == i && f->get_est_vivant()) {
                    std::cout << " " << f->get_symbole() << " ";
                    fauve_trouve = true;
                    break;
                }
            }
            if (fauve_trouve) continue;

            // Affiche les pièges
            bool piege_trouve = false;
            for (const piege& p : get_pieges()) {
                if (p.get_colonne() == j && p.get_ligne() == i) {
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



#include "terrain.h"
#include "fauve.h"
#include "tigre.h"
#include "lion.h"
#include "fonctions.h"
#include <utility>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

terrain::terrain() : d_largeur{10}, d_hauteur{10}, d_position_joueur{0, 0}, d_fauves{}, d_pieges{} {}

terrain::terrain(int larg) : d_largeur{}, d_hauteur{}, d_position_joueur{ }, d_fauves{}, d_pieges{} {}


terrain::terrain(int largeur, int hauteur, position position_joueur)
        : d_largeur{largeur}, d_hauteur{hauteur}, d_position_joueur{position_joueur} {
    // Création d'un terrain de base
    ajoute_piege({4, 4});
    ajoute_fauve(std::make_unique<tigre>(position{8, 8}));
    ajoute_fauve(std::make_unique<lion>(position{8, 0}));
}

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

const std::vector<std::unique_ptr<fauve>> &terrain::get_fauves() {
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
            for (const auto &f: get_fauves()) {
                if (f->get_colonne() == j && f->get_ligne() == i && f->get_est_vivant()) {
                    std::cout << " " << f->get_symbole() << " ";
                    fauve_trouve = true;
                    break;
                }
            }
            if (fauve_trouve) continue;

            // Affiche les pièges
            bool piege_trouve = false;
            for (const piege &p: get_pieges()) {
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


void terrain::sauvegarde() {
    // Ouvre un flux de sortie vers le fichier
    std::string nom_fichier;
    std::cout << "Comment voulez vous appeler le fichier ? ";
    std::cin >> nom_fichier;
    std::ofstream fichier(nom_fichier);

    // Écrit les informations sur le terrain dans le fichier
    fichier << get_largeur() << ' ' << get_hauteur() << '\n';
    fichier << d_position_joueur.get_ligne() << ' ' << d_position_joueur.get_colonne() << '\n';
    fichier << get_joueur_ligne() << ' ' << get_joueur_colonne() << '\n';
    fichier << d_fauves.size() << '\n';
    for (const auto &f: d_fauves) {
        fichier << f->get_symbole() << ' ' << f->get_ligne() << ' ' << f->get_colonne() << ' ' << f->get_est_vivant()
                << '\n';
    }
    fichier << d_pieges.size() << '\n';
    for (const piege &p: d_pieges) {
        fichier << p.get_ligne() << ' ' << p.get_colonne() << '\n';
    }

    // Ferme le fichier
    fichier.close();
    std::cout << "Le terrain a ete sauvegarde dans le fichier " << nom_fichier << "\n";
}

void terrain::creer_Terrain() {
    // Création du terrain
    int largeur = fonctions::demande_entier("Entrez la largeur du terrain : ");
    int hauteur =  fonctions::demande_entier("Entrez la hauteur du terrain : ");
    int ligne =  fonctions::demande_entier("Entrez la ligne du joueur : ");
    int colonne =  fonctions::demande_entier("Entrez la colonne du joueur : ");
    position position_joueur{ligne, colonne};
    terrain t{largeur, hauteur, position_joueur};

    // Ajout de fauves sur le terrain
    char reponse =  fonctions::demande_oui_non("Voulez-vous ajouter des fauves sur le terrain ? (o/n) ");
    while (reponse == 'o') {
        string type =  fonctions::demande_choix("Quel type de fauve voulez-vous ajouter ? (tigre/lion) ", {"tigre", "lion"});
        int ligne =  fonctions::demande_entier("Entrez la ligne du fauve : ");
        int colonne = fonctions:: demande_entier("Entrez la colonne du fauve : ");

        position pos{ligne, colonne};

        if (type == "tigre") {
            t.ajoute_fauve(std::make_unique<tigre>(pos));
        } else if (type == "lion") {
            t.ajoute_fauve(std::make_unique<lion>(pos));
        }
        reponse = fonctions::demande_oui_non("Voulez-vous ajouter un autre fauve ? (o/n) ");
    }

    // Ajout de pièges sur le terrain
    reponse = fonctions::demande_oui_non("Voulez-vous ajouter des pieges sur le terrain ? (o/n) ");
    while (reponse == 'o') {
        int ligne = fonctions::demande_entier("Entrez la ligne du piege : ");
        int colonne = fonctions::demande_entier("Entrez la colonne du piege : ");
        t.ajoute_piege({ligne, colonne});
        reponse = fonctions::
                demande_oui_non("Voulez-vous ajouter un autre piege ? (o/n) ");
    }

}

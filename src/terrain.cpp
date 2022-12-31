#include "terrain.h"
#include "fauve.h"
#include <utility>

terrain::terrain() : d_largeur{10}, d_hauteur{10} , d_position_joueur{0, 0}, d_fauves{}, d_pieges{}
{}

terrain::terrain(int largeur, int hauteur, position position_joueur)
: d_largeur{largeur}, d_hauteur{hauteur}, d_position_joueur{position_joueur}
{}

int terrain::getLargeur() const {
    return d_largeur;
}

int terrain::getHauteur() const {
    return d_hauteur;
}

int terrain::getJoueurLigne() const {
    return d_position_joueur.getLigne();
}

int terrain::getJoueurColonne() const {
    return d_position_joueur.getColonne();
}

void terrain::setJoueurLigne(int ligne) {
    d_position_joueur.setLigne(ligne);
}

void terrain::setJoueurColonne(int colonne) {
    d_position_joueur.setColonne(colonne);
}

std::vector<piege> terrain::getPieges() const {
    return d_pieges;
}

const std::vector<std::unique_ptr<fauve>>& terrain::getFauves() {
    return d_fauves;
}

void terrain::ajoute_piege(piege p) {
    d_pieges.push_back(p);
}

void terrain::ajoute_fauve(std::unique_ptr<fauve> f) {
    d_fauves.push_back(std::move(f));
}



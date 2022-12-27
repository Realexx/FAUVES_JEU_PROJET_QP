#include "terrain.h"

#include <utility>

terrain::terrain() : d_largeur{10}, d_hauteur{10} , d_position_joueur{0, 0}, d_fauves{}, d_pieges{}
{}

terrain::terrain(int largeur, int hauteur, position position_joueur, vector<std::unique_ptr<fauve>> fauves, vector<piege> pieges)
: d_largeur{largeur}, d_hauteur{hauteur}, d_position_joueur{position_joueur}, d_fauves{std::move(fauves)}, d_pieges{std::move(pieges)}
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

vector<piege> terrain::getPieges() const {
    return d_pieges;
}




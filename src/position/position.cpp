//
// Created by Guillaume Giannantonio on 20/12/2022.
//

#include "position.h"

position::position(int ligne, int colonne) : d_ligne{ligne}, d_colonne{colonne}
{}

// Getter & setter
int position::getLigne() const {
    return d_ligne;
}

void position::setLigne(int ligne) {
    d_ligne = ligne;
}

int position::getColonne() const {
    return d_colonne;
}

void position::setColonne(int colonne) {
    d_colonne = colonne;
}
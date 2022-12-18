//
// Created by schla on 18/12/2022.
//

#include "position.h"

position::position() : d_ligne{0}, d_colonne{0}
{}

position::position(int ligne, int colonne) : d_ligne{ligne}, d_colonne{colonne}
{}

// Getter & setter
int position::getLigne() const {
    return d_ligne;
}

void position::setLigne(int dLigne) {
    d_ligne = dLigne;
}

int position::getColonne() const {
    return d_colonne;
}

void position::setColonne(int dColonne) {
    d_colonne = dColonne;
}

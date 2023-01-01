//
// Created by schla on 18/12/2022.
//

#include "position.h"

position::position() : d_ligne{0}, d_colonne{0}
{}

position::position(int ligne, int colonne) : d_ligne{ligne}, d_colonne{colonne}
{}

// Getter & setter
int position::get_ligne() const {
    return d_ligne;
}

void position::set_ligne(int dLigne) {
    d_ligne = dLigne;
}

int position::get_colonne() const {
    return d_colonne;
}

void position::set_colonne(int dColonne) {
    d_colonne = dColonne;
}

#include "piege.h"

piege::piege() : d_position{0,0}
{}

piege::piege(int ligne, int colonne) : d_position{ligne, colonne}
{}

int piege::get_ligne() const {
    return d_position.get_ligne();
}

int piege::get_colonne() const {
    return d_position.get_colonne();
}

void piege::set_ligne(int ligne) {
    d_position.set_ligne(ligne);
}

void piege::set_colonne(int colonne) {
    d_position.set_colonne(colonne);
}




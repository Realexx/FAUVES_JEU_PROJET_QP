#include "piege.h"

piege::piege() : d_position{0,0}
{}

piege::piege(int ligne, int colonne) : d_position{ligne, colonne}
{}

int piege::getLigne() const {
    return d_position.getLigne();
}

int piege::getColonne() const {
    return d_position.getColonne();
}

void piege::setLigne(int ligne) {
    d_position.setLigne(ligne);
}

void piege::setColonne(int colonne) {
    d_position.setColonne(colonne);
}




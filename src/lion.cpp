#include "lion.h"

lion::lion() : d_pos{}, d_est_vivant{true}
{}

lion::lion(position pos) : d_pos{pos.getLigne(), pos.getColonne()}, d_est_vivant{true}
{}

int lion::getLigne() const {
    return d_pos.getLigne();
}

int lion::getColonne() const {
    return d_pos.getColonne();
}

void lion::setLigne(int ligne) {
    d_pos.setLigne(ligne);
}

void lion::setColonne(int colonne) {
    d_pos.setColonne(colonne);
}

bool lion::getEstVivant() const {
    return d_est_vivant;
}

void lion::setEstVivant(bool estVivant) {
    d_est_vivant = estVivant;
}

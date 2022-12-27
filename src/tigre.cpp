#include "tigre.h"

tigre::tigre() : d_pos{}, d_est_vivant{true}
{}

tigre::tigre(position pos) : d_pos{pos.getLigne(), pos.getColonne()}, d_est_vivant{true}
{}

int tigre::getLigne() const {
    return d_pos.getLigne();
}

int tigre::getColonne() const {
    return d_pos.getColonne();
}

void tigre::setLigne(int ligne) {
    d_pos.setLigne(ligne);
}

void tigre::setColonne(int colonne) {
    d_pos.setColonne(colonne);
}

bool tigre::getEstVivant() const {
    return d_est_vivant;
}

void tigre::setEstVivant(bool estVivant) {
    d_est_vivant = estVivant;
}



#include "tigre.h"

tigre::tigre() : d_pos{}, d_est_vivant{true}, d_symbole{"T"}
{}

tigre::tigre(position pos) : d_pos{pos.getLigne(), pos.getColonne()}, d_est_vivant{true}, d_symbole{"T"}
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

std::string tigre::getSymbole() {
    return d_symbole;
}

void tigre::deplacement(terrain &t) {
    if (getColonne() < t.getJoueurColonne() && getLigne() < t.getJoueurLigne()) {
        setColonne(getColonne()+1);
        setLigne(getLigne()+1);
    } else if (getColonne() > t.getJoueurColonne() && getLigne() > t.getJoueurLigne()) {
        setColonne(getColonne()-1);
        setLigne(getLigne()-1);
    } else if (getColonne() > t.getJoueurColonne() && getLigne() < t.getJoueurLigne()) {
        setColonne(getColonne()-1);
        setLigne(getLigne()+1);
    } else if (getColonne() < t.getJoueurColonne() && getLigne() > t.getJoueurLigne()) {
        setColonne(getColonne()+1);
        setLigne(getLigne()-1);
    } else if (getColonne() < t.getJoueurColonne() && getLigne() == t.getJoueurLigne()) {
        setColonne(getColonne()+1);
    } else if (getColonne() > t.getJoueurColonne() && getLigne() == t.getJoueurLigne()) {
        setColonne(getColonne()-1);
    } else if (getLigne() < t.getJoueurLigne() && getColonne() == t.getJoueurColonne()) {
        setLigne(getLigne()+1);
    } else if (getLigne() > t.getJoueurLigne() && getColonne() == t.getJoueurColonne()) {
        setLigne(getLigne()-1);
    }

    // Si le fauve se retrouve sur la même case qu'un autre fauve, ils s'affrontent
    for (const auto& autre_fauve : t.getFauves()) {
        if (autre_fauve.get() == this) continue; // On ignore le fauve lui-même
        if (autre_fauve->getColonne() == getColonne() && autre_fauve->getLigne() == getLigne()) {
            if (autre_fauve->getSymbole() == getSymbole()) {
                // Si les fauves sont du même type, ils essaient de s'éviter et ne bougent pas
                setColonne(getColonne());
                setLigne(getLigne());
            } else {
                // Si les fauves sont de types différents, ils s'affrontent et l'un des deux meurt
                setEstVivant(false);
                autre_fauve->setEstVivant(false);
            }
            break;
        }
    }

    // Si le fauve se retrouve sur un piège, il meurt
    for (piege& piege : t.getPieges()) {
        if (piege.getColonne() == getColonne() && piege.getLigne() == getLigne()) {
            setEstVivant(false);
            break;
        }
    }
}



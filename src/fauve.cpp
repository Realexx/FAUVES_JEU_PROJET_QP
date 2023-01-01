#include <ctime>
#include <utility>
#include "fauve.h"

fauve::fauve() : d_pos{}, d_est_vivant{true}
{}

fauve::fauve(position pos) : d_pos{pos.get_ligne(), pos.get_colonne()}, d_est_vivant{true}
{}

int fauve::get_ligne() const {
    return d_pos.get_ligne();
}

int fauve::get_colonne() const {
    return d_pos.get_colonne();
}

void fauve::set_ligne(int ligne) {
    d_pos.set_ligne(ligne);
}

void fauve::set_colonne(int colonne) {
    d_pos.set_colonne(colonne);
}

bool fauve::get_est_vivant() const {
    return d_est_vivant;
}

void fauve::set_est_vivant(bool estVivant) {
    d_est_vivant = estVivant;
}

std::string fauve::get_symbole() {
    return d_symbole;
}

void fauve::set_symbole(std::string symbole) {
    d_symbole = std::move(symbole);
}

void fauve::verif_deplacement(terrain &t) {
    // Si le fauve se retrouve sur la même case qu'un autre fauve, ils s'affrontent
    for (const auto& autre_fauve : t.get_fauves()) {
        if (autre_fauve.get() == this) continue; // On ignore le fauve lui-même
        if (autre_fauve->get_colonne() == get_colonne() && autre_fauve->get_ligne() == get_ligne()) {
            if (autre_fauve->get_symbole() == get_symbole()) {
                // Si les fauves sont du même type, ils essaient de s'éviter et ne bougent pas
                set_colonne(d_pos_precedente.get_colonne());
                set_ligne(d_pos_precedente.get_ligne());
            } else {
                // Si les fauves sont de types différents, ils s'affrontent et l'un des deux meurt
                std::srand(std::time(nullptr));
                int rand = std::rand() % 2;
                if (rand == 0) set_est_vivant(false);
                else autre_fauve->set_est_vivant(false);
            }
            break;
        }
    }

    // Si le fauve se retrouve sur un piège, il meurt
    for (piege& piege : t.get_pieges()) {
        if (piege.get_colonne() == get_colonne() && piege.get_ligne() == get_ligne()) {
            set_est_vivant(false);
            break;
        }
    }
}

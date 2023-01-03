#include <ctime>
#include <iostream>
#include "lion.h"

lion::lion() : fauve{}
{
    set_symbole("L");
}

lion::lion(position pos) : fauve{pos}
{
    set_symbole("L");
}

string lion::get_type() {
    return d_type;
}

void lion::deplacement(terrain &t) {
    // Enregistrement de la dernière position
    d_pos_precedente = d_pos;
    // Règles de déplacement
    if (get_colonne() < t.get_joueur_colonne()) {
        set_colonne(get_colonne() + 1);
    } else if (get_colonne() > t.get_joueur_colonne()) {
        set_colonne(get_colonne() - 1);
    } else if (get_ligne() < t.get_joueur_ligne()) {
        set_ligne(get_ligne() + 1);
    } else if (get_ligne() > t.get_joueur_ligne()) {
        set_ligne(get_ligne() - 1);
    }

    verif_deplacement(t);
}

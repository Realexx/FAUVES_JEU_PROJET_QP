#include <ctime>
#include <iostream>
#include "tigre.h"

tigre::tigre() : fauve{}
{
    set_symbole("T");
}

tigre::tigre(position pos) : fauve{pos}
{
    set_symbole("T");
}

void tigre::deplacement(terrain &t) {
    // Enregistrement de la dernière position
    d_pos_precedente = d_pos;
    // Règles de déplacement
    if (get_colonne() < t.get_joueur_colonne() && get_ligne() < t.get_joueur_ligne()) {
        set_colonne(get_colonne() + 1);
        set_ligne(get_ligne() + 1);
    } else if (get_colonne() > t.get_joueur_colonne() && get_ligne() > t.get_joueur_ligne()) {
        set_colonne(get_colonne() - 1);
        set_ligne(get_ligne() - 1);
    } else if (get_colonne() > t.get_joueur_colonne() && get_ligne() < t.get_joueur_ligne()) {
        set_colonne(get_colonne() - 1);
        set_ligne(get_ligne() + 1);
    } else if (get_colonne() < t.get_joueur_colonne() && get_ligne() > t.get_joueur_ligne()) {
        set_colonne(get_colonne() + 1);
        set_ligne(get_ligne() - 1);
    } else if (get_colonne() < t.get_joueur_colonne() && get_ligne() == t.get_joueur_ligne()) {
        set_colonne(get_colonne() + 1);
    } else if (get_colonne() > t.get_joueur_colonne() && get_ligne() == t.get_joueur_ligne()) {
        set_colonne(get_colonne() - 1);
    } else if (get_ligne() < t.get_joueur_ligne() && get_colonne() == t.get_joueur_colonne()) {
        set_ligne(get_ligne() + 1);
    } else if (get_ligne() > t.get_joueur_ligne() && get_colonne() == t.get_joueur_colonne()) {
        set_ligne(get_ligne() - 1);
    }

    verif_deplacement(t);
}



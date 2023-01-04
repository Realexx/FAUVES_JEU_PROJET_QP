#ifndef FAUVES_JEU_PROJET_QP_APPLICATION_H
#define FAUVES_JEU_PROJET_QP_APPLICATION_H

#include "terrain.h"
#include "partie.h"

class application {
public:
    application();
    void run();
    void set_partie(partie part);
    void set_terrain_charge(terrain& t);

private:
    static int menu_principal();

    void jouer();
    void creation_terrain();
    void edition_terrain();
    void choix_terrain();

    terrain d_terrain_charge;
    partie d_partie;
};


#endif //FAUVES_JEU_PROJET_QP_APPLICATION_H

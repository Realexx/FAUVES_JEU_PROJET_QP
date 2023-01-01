#ifndef FAUVES_JEU_PROJET_QP_APPLICATION_H
#define FAUVES_JEU_PROJET_QP_APPLICATION_H

#include "terrain.h"

class application {
public:
    application();
    void run();
private:
    static int menu_principal();

    void jouer();
    void creation_terrain();
    void edition_terrain();

    terrain d_terrain_charge;
};


#endif //FAUVES_JEU_PROJET_QP_APPLICATION_H

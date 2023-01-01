#ifndef FAUVES_JEU_PROJET_QP_PARTIE_H
#define FAUVES_JEU_PROJET_QP_PARTIE_H

#include "terrain.h"

class partie {
public:
    partie();
    partie(terrain& t);
    bool est_deplacement_dans_bordures();
    bool joueur_se_deplace();
    void faire_bouger_fauves();
    bool joueur_en_vie();
    bool fauves_en_vie();
    void run();

private:
    terrain d_terrain;
};


#endif //FAUVES_JEU_PROJET_QP_PARTIE_H

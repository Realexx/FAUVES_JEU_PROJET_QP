#ifndef FAUVES_JEU_PROJET_QP_PIEGE_H
#define FAUVES_JEU_PROJET_QP_PIEGE_H

#include "position.h"

class piege {
public:
    piege();
    piege(int ligne, int colonne);
    int get_ligne() const;
    int get_colonne() const;
    void set_ligne(int ligne);
    void set_colonne(int colonne);

private:
    position d_position;
};


#endif //FAUVES_JEU_PROJET_QP_PIEGE_H

#ifndef FAUVES_JEU_PROJET_QP_PIEGE_H
#define FAUVES_JEU_PROJET_QP_PIEGE_H

#include "position.h"

class piege {
public:
    piege();
    piege(int ligne, int colonne);
    int getLigne() const;
    int getColonne() const;
    void setLigne(int ligne);
    void setColonne(int colonne);

private:
    position d_position;
};


#endif //FAUVES_JEU_PROJET_QP_PIEGE_H

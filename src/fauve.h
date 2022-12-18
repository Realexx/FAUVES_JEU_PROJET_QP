#ifndef FAUVES_JEU_PROJET_QP_FAUVE_H
#define FAUVES_JEU_PROJET_QP_FAUVE_H


#include "position.h"
#include <vector>

using namespace std;

class fauve {
public:
    fauve();
    fauve(int ligne, int colonne);
    virtual ~fauve() = default;
    virtual vector<position> positionsSuivantesPossibles() = 0;

private:
    position d_pos;
};


#endif //FAUVES_JEU_PROJET_QP_FAUVE_H

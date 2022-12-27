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
    virtual int getLigne() const = 0;
    virtual int getColonne() const = 0;
    virtual void setLigne(int ligne) = 0;
    virtual void setColonne(int colonne) = 0;
    virtual bool getEstVivant() const = 0;
    virtual void setEstVivant(bool estVivant) = 0;

private:
    position d_pos; bool d_est_vivant;
};


#endif //FAUVES_JEU_PROJET_QP_FAUVE_H

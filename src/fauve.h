#ifndef FAUVES_JEU_PROJET_QP_FAUVE_H
#define FAUVES_JEU_PROJET_QP_FAUVE_H


#include "position.h"
#include "terrain.h"
#include <vector>
#include <string>

using namespace std;

class fauve {
public:
    virtual ~fauve() = default;
    virtual int getLigne() const = 0;
    virtual int getColonne() const = 0;
    virtual void setLigne(int ligne) = 0;
    virtual void setColonne(int colonne) = 0;
    virtual bool getEstVivant() const = 0;
    virtual void setEstVivant(bool estVivant) = 0;
    virtual std::string getSymbole() = 0;
    virtual void deplacement(terrain& t) = 0;
};


#endif //FAUVES_JEU_PROJET_QP_FAUVE_H

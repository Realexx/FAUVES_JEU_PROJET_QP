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
    fauve();
    fauve(position pos);
    int get_ligne() const;
    int get_colonne() const;
    void set_ligne(int ligne);
    void set_colonne(int colonne);
    bool get_est_vivant() const;
    void set_est_vivant(bool estVivant);
    std::string get_symbole();
    void set_symbole(std::string symbole);
    virtual void deplacement(terrain& t) = 0;
    void verif_deplacement(terrain& t);

protected:
    position d_pos, d_pos_precedente;
    bool d_est_vivant;
    std::string d_symbole;
};


#endif //FAUVES_JEU_PROJET_QP_FAUVE_H

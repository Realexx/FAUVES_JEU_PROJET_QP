#ifndef FAUVES_JEU_PROJET_QP_TERRAIN_H
#define FAUVES_JEU_PROJET_QP_TERRAIN_H

#include <memory>
#include "fauve.h"
#include "piege.h"

class terrain {
public:
    terrain();
    terrain(int largeur, int hauteur, position position_joueur, vector<std::unique_ptr<fauve>> fauves, vector<piege> pieges);
    int getLargeur() const;
    int getHauteur() const;
    int getJoueurLigne() const;
    int getJoueurColonne() const;
    void setJoueurLigne(int ligne);
    void setJoueurColonne(int colonne);
    vector<piege> getPieges() const;

private:
    int d_largeur, d_hauteur;
    vector<std::unique_ptr<fauve>> d_fauves;
    vector<piege> d_pieges;
    position d_position_joueur;
};


#endif //FAUVES_JEU_PROJET_QP_TERRAIN_H

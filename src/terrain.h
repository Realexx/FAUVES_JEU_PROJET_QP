#ifndef FAUVES_JEU_PROJET_QP_TERRAIN_H
#define FAUVES_JEU_PROJET_QP_TERRAIN_H

#include <memory>
#include "piege.h"
#include "vector"
class fauve;

class terrain {
public:
    terrain();
    terrain(int largeur, int hauteur, position position_joueur);
    int getLargeur() const;
    int getHauteur() const;
    int getJoueurLigne() const;
    int getJoueurColonne() const;
    void setJoueurLigne(int ligne);
    void setJoueurColonne(int colonne);
    std::vector<piege> getPieges() const;
    const std::vector<std::unique_ptr<fauve>>& getFauves();
    void ajoute_piege(piege p);
    void ajoute_fauve(std::unique_ptr<fauve> f);

private:
    int d_largeur, d_hauteur;
    std::vector<std::unique_ptr<fauve>> d_fauves;
    std::vector<piege> d_pieges;
    position d_position_joueur;
};


#endif //FAUVES_JEU_PROJET_QP_TERRAIN_H

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

    terrain(int larg);

    int get_largeur() const;
    int get_hauteur() const;
    void set_hauteur(int haut);
    void set_largeur(int larg);
    int get_joueur_ligne() const;
    int get_joueur_colonne() const;
    void set_joueur_ligne(int ligne);
    void set_joueur_colonne(int colonne);
    std::vector<piege> get_pieges() const;
    const std::vector<std::unique_ptr<fauve>>& get_fauves();
    void ajoute_piege(piege p);
    void ajoute_fauve(std::unique_ptr<fauve> f);
    void affiche();
    void sauvegarde();

    void creer_Terrain();

private:
    int d_largeur, d_hauteur;
    std::vector<std::unique_ptr<fauve>> d_fauves;
    std::vector<piege> d_pieges;
    position d_position_joueur;

};


#endif //FAUVES_JEU_PROJET_QP_TERRAIN_H

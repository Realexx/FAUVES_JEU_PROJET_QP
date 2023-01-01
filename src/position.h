#ifndef FAUVES_JEU_PROJET_QP_POSITION_H
#define FAUVES_JEU_PROJET_QP_POSITION_H


class position {
public:
    position();
    position(int ligne, int colonne);
    int get_ligne() const;
    void set_ligne(int dLigne);
    int get_colonne() const;
    void set_colonne(int dColonne);

private:
    int d_ligne, d_colonne;
};


#endif //FAUVES_JEU_PROJET_QP_POSITION_H

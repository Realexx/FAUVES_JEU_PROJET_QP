#ifndef FAUVES_JEU_PROJET_QP_POSITION_H
#define FAUVES_JEU_PROJET_QP_POSITION_H


class position {
public:
    position();
    position(int ligne, int colonne);
    int getLigne() const;
    void setLigne(int dLigne);
    int getColonne() const;
    void setColonne(int dColonne);

private:
    int d_ligne, d_colonne;
};


#endif //FAUVES_JEU_PROJET_QP_POSITION_H

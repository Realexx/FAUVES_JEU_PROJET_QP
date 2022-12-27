#ifndef FAUVES_JEU_PROJET_QP_TIGRE_H
#define FAUVES_JEU_PROJET_QP_TIGRE_H

#include "fauve.h"

class tigre : public fauve {
public:
    tigre();
    tigre(position pos);
    int getLigne() const override;
    int getColonne() const override;
    void setLigne(int ligne) override;
    void setColonne(int colonne) override;
    bool getEstVivant() const override;
    void setEstVivant(bool estVivant) override;

private:
    position d_pos; bool d_est_vivant;
};


#endif //FAUVES_JEU_PROJET_QP_TIGRE_H

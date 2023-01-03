#ifndef FAUVES_JEU_PROJET_QP_TIGRE_H
#define FAUVES_JEU_PROJET_QP_TIGRE_H

#include "fauve.h"
#include "terrain.h"

class tigre : public fauve {
public:
    tigre();
    tigre(position pos);

    void deplacement(terrain& t) override;
private:
    string d_type = "tigre";
};


#endif //FAUVES_JEU_PROJET_QP_TIGRE_H

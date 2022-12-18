#ifndef FAUVES_JEU_PROJET_QP_TIGRE_H
#define FAUVES_JEU_PROJET_QP_TIGRE_H

#include "fauve.h"

class tigre : public fauve {
public:
    tigre();
    tigre(position pos);
    vector<position> positionsSuivantesPossibles() override;

private:
    position d_pos;
};


#endif //FAUVES_JEU_PROJET_QP_TIGRE_H

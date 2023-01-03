#ifndef FAUVES_JEU_PROJET_QP_LION_H
#define FAUVES_JEU_PROJET_QP_LION_H

#include "fauve.h"

class lion : public fauve {
public:
    lion();
    lion(position pos);
    string get_type();
    void deplacement(terrain& t) override;
private:
    string d_type = "lion";
};


#endif //FAUVES_JEU_PROJET_QP_LION_H

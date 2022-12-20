//
// Created by Guillaume Giannantonio on 20/12/2022.
//

#ifndef UNTITLED_LION_H
#define UNTITLED_LION_H

#include "../../moovable.h"

class lion : public moovable {
public:
    std::vector<position> positionsSuivantesPossibles() override;
};


#endif //UNTITLED_LION_H

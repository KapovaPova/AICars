//
// Created by kapovapova on 11/2/26.
//

#ifndef AICARS_CAR_H
#define AICARS_CAR_H
#include <array>
#include "vec2.h"

struct Car {
    vec2 coordinates;
    unsigned int heading = 0;
    unsigned int speed = 0;
    std::array<double, 5> wallDist = {};
};

#endif //AICARS_CAR_H

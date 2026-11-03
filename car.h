//
// Created by kapovapova on 11/2/26.
//

#ifndef AICARS_CAR_H
#define AICARS_CAR_H
#include <array>
#include "vec2.h"

struct Car {
    vec2 coordinates;
    double heading = 0;
    double speed = 0;
    std::array<double, 5> wallDist = {};
};

#endif //AICARS_CAR_H

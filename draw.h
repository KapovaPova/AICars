//
// Created by kapovapova on 11/2/26.
//

#ifndef AICARS_DRAW_H
#define AICARS_DRAW_H
#include <vector>
#include "vec2.h"
#include "car.h"

void draw(const std::vector<vec2> &map, const std::vector<Car> &cars, const int &window_width, const int &window_height);

#endif //AICARS_DRAW_H

//
// Created by kapovapova on 11/2/26.
//

#ifndef AICARS_GENERATEROAD_H
#define AICARS_GENERATEROAD_H
#include <vector>
#include "vec2.h"
#include <array>

std::array<std::vector<vec2>, 2> generateRoad(const std::vector<vec2> &map,
                                              const double &minWidth, const double &maxWidth,
                                              const unsigned int &step);

#endif //AICARS_GENERATEROAD_H

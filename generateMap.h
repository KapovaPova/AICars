//
// Created by kapovapova on 11/2/26.
//

#ifndef AICARS_GENERATEMAP_H
#define AICARS_GENERATEMAP_H
#include <vector>
#include "vec2.h"

std::vector<vec2> generateMap(const double &centerX, const double &centerY, const unsigned int &count,
                              const double &minR, const double &maxR);

#endif //AICARS_GENERATEMAP_H

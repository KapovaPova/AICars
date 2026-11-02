//
// Created by kapovapova on 11/2/26.
//

#include "generateMap.h"
#include <random>
#include <cmath>

std::vector<vec2> generateMap(const unsigned int &count, const double &minR, const double &maxR) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<double> RDist(minR, maxR);

    std::vector<vec2> map;
    map.reserve(count);

    for (unsigned int i = 0; i < count; i++) {
        double angle = 2.0 * M_PI * i / count;
        double r = RDist(rng);
        map.push_back({r * std::cos(angle), r * std::sin(angle)});
    }

    return map;
}

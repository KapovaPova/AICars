//
// Created by kapovapova on 11/2/26.
//

#include "smoothMap.h"

std::vector<vec2> smoothMap(const std::vector<vec2> &map, const unsigned int &iterations) {
    std::vector<vec2> newMap = map;

    for (unsigned int it = 0; it < iterations; it++) {
        std::vector<vec2> next;

        for (unsigned int i = 0; i < newMap.size(); i++) {
            const vec2 &point1 = newMap[i];
            const vec2 &point2 = newMap[(i + 1) % newMap.size()];
            next.push_back({0.75 * point1.x + 0.25 * point2.x, 0.75 * point1.y + 0.25 * point2.y});
            next.push_back({0.25 * point1.x + 0.75 * point2.x, 0.25 * point1.y + 0.75 * point2.y});
        }

        newMap = next;
    }

    return newMap;
}
//
// Created by kapovapova on 11/2/26.
//

#include "generateRoad.h"
#include <cmath>
#include "generateWidths.h"

std::array<std::vector<vec2>, 2> generateRoad(const std::vector<vec2> &map,
                                              const double &minWidth, const double &maxWidth,
                                              const unsigned int &step) {
    if (map.size() < 3) return {};

    std::vector<vec2> left;
    left.reserve(map.size());
    std::vector<vec2> right;
    right.reserve(map.size());

    std::vector<double> widths = generateWidths(map.size(), minWidth, maxWidth, step);

    for (unsigned int i = 0; i < map.size(); i++) {
        const vec2 &prev = map[(i + map.size() - 1) % map.size()];
        const vec2 &curr = map[i];
        const vec2 &next = map[(i + 1) % map.size()];

        double dx = next.x - prev.x;
        double dy = next.y - prev.y;
        double len = std::sqrt(dx * dx + dy * dy);
        dx /= len;
        dy /= len;

        left.push_back({curr.x - dy * widths[i] / 2, curr.y + dx * widths[i] / 2});
        right.push_back({curr.x + dy * widths[i] / 2, curr.y - dx * widths[i] / 2});
    }

    return std::array<std::vector<vec2>, 2>{left, right};
}

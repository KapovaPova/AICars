//
// Created by kapovapova on 11/2/26.
//

#include "generateWidths.h"
#include <random>

std::vector<double> generateWidths(size_t n, double minW, double maxW, double step) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<double> startDist(minW, maxW);
    std::uniform_real_distribution<double> stepDist(-step, step);

    std::vector<double> widths;
    double w = startDist(rng);

    for (size_t i = 0; i < n; i++) {
        w += stepDist(rng);
        if (w < minW) w = minW;
        if (w > maxW) w = maxW;
        widths.push_back(w);
    }

    double diff = widths[n - 1] - widths[0];
    for (size_t i = 0; i < n; i++) {
        widths[i] -= diff * i / (n - 1);
    }

    return widths;
}
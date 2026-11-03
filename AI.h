//
// Created by kapovapova on 11/3/26.
//

#ifndef AICARS_AI_H
#define AICARS_AI_H
#include <vector>
#include <array>

class AI {
    std::vector<std::vector<double>> weights;
    unsigned int layers;
    unsigned int neurons;

    unsigned int layerSize(const unsigned int& layer);
public:
    AI(const unsigned int &layers, const unsigned int &neurons);
    std::array<double, 2> run(const std::array<double, 6> &input);
    std::vector<std::vector<double>> getWeights();
    void setWeights(const std::vector<std::vector<double>> &weights);
};

#endif //AICARS_AI_H

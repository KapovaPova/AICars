//
// Created by kapovapova on 11/3/26.
//

#include "AI.h"
#include <random>
#include <cmath>

unsigned int AI::layerSize(const unsigned int& layer) {
    if (layer == 0) return 6;
    if (layer == layers + 1) return 2;
    return neurons;
}

AI::AI(const unsigned int &layers, const unsigned int &neurons) : layers(layers), neurons(neurons) {
    std::random_device rd;
    std::mt19937 rng(rd());

    weights.resize(layers + 1);
    for (unsigned int i = 0; i < weights.size(); i++) {
        unsigned int in = layerSize(i);
        unsigned int out = layerSize(i + 1);
        double limit = 1.0 / std::sqrt((double)in);

        std::uniform_real_distribution<double> dist(-limit, limit);

        weights[i].resize((in + 1) * out);
        for (double &weight : weights[i]) weight = dist(rng);
    }
}
std::array<double, 2> AI::run(const std::array<double, 6> &input) {
    std::vector<double> current(input.begin(), input.end()); // числа данные сети, 6 штук

    for (unsigned int i = 0; i < weights.size(); i++) { // перебираем каждый слой весов между 2мя слоями нейеронов
        unsigned int in = layerSize(i); // сколько нейеронов в текущеем ряду
        unsigned int out = layerSize(i + 1); // сколкьо нейеронов в следующем ряду
        std::vector<double> next(out); // массив ответов для следуюзих нейеронов

        for (unsigned int j = 0; j < out; j++) { // перебираем нейероны следующего ряда
            const unsigned int start = j * (in + 1); // находим позицию, где начинается наши связи текущего нейерона, у нейерона in связей + 1 bias
            double sum = weights[i][start + in]; // сумма, уже с bias
            for (unsigned int k = 0; k < in; k++) sum += weights[i][start + k] * current[k]; // добавляем веса
            next[j] = std::tanh(sum); // ставим для следующего нейерона значение sum сжатое (-1; 1)
        }

        current = next; // делаем текущий слой нейеронов слоем следующих нейеронов(для которых считали)
    }

    return {current[0], current[1]}; // возвращаем филаьные значения выходного ряда
}

std::vector<std::vector<double>> AI::getWeights() {
    return weights;
}

void AI::setWeights(const std::vector<std::vector<double>> &weights) {
    this->weights = weights;
}
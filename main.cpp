#include "car.h"
#include <vector>
#include "draw.h"
#include "vec2.h"
#include "generateMap.h"
#include "smoothMap.h"

int main() {
    std::vector<vec2> map = generateMap(0, 0, 25, 100, 200);
    map = smoothMap(map, 2);
    std::vector<Car> cars = {{0.0f, 0.0f}};
    draw(map, cars, 800, 600);
}

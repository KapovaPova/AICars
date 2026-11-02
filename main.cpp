#include "car.h"
#include <vector>
#include "draw.h"
#include "vec2.h"
#include "generateMap.h"
#include "smoothMap.h"
#include "generateRoad.h"

int main() {
    std::vector<vec2> map = generateMap(25, 100, 200);
    map = smoothMap(map, 3);
    std::array<std::vector<vec2>, 2> road = generateRoad(map, 15, 15, 1);

    Car car1 = {map[0].x, map[0].y};
    std::vector<Car> cars = {car1};

    draw(road, cars, 800, 600);
}

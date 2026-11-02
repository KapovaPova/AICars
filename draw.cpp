//
// Created by kapovapova on 11/2/26.
//

#include "draw.h"
#include <raylib.h>

void draw(const std::vector<vec2> &map, const std::vector<Car> &cars, const int &window_width, const int &window_height) {
    InitWindow(window_width, window_height, "AICars");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        for (unsigned int i = 0; i < map.size(); i++) {
            const vec2 &point1 = map[i];
            const vec2 &point2 = map[(i + 1) % map.size()];
            DrawLine((int) window_width / 2 + (int) point1.x, (int) window_height / 2 + (int) point1.y,
                     (int) window_width / 2 + (int) point2.x, (int) window_height / 2 + (int) point2.y,
                     WHITE);
        }

        for (const Car &car: cars) {
            DrawCircle((int) window_width / 2 + car.coordinates.x,
                       (int) window_height / 2 + car.coordinates.y, 1, RED);
        }

        EndDrawing();
    }

    CloseWindow();
}

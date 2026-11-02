//
// Created by kapovapova on 11/2/26.
//

#include "draw.h"
#include <raylib.h>
#include <array>

void draw(const std::array<std::vector<vec2>, 2> &map, const std::vector<Car> &cars,
          const int &window_width, const int &window_height) {
    InitWindow(window_width, window_height, "AICars");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        for (const std::vector<vec2> &entry: map) {
            for (unsigned int i = 0; i < entry.size(); i++) {
                const vec2 &point1 = entry[i];
                const vec2 &point2 = entry[(i + 1) % entry.size()];
                DrawLine((int) window_width / 2 + (int) point1.x, (int) window_height / 2 + (int) point1.y,
                         (int) window_width / 2 + (int) point2.x, (int) window_height / 2 + (int) point2.y,
                         WHITE);
            }
        }

        for (const Car &car: cars) {
            DrawCircle((int) window_width / 2 + car.coordinates.x,
                       (int) window_height / 2 + car.coordinates.y, 1, RED);
        }

        EndDrawing();
    }

    CloseWindow();
}

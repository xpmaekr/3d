#include "dependences.hpp"

int main() {
    InitWindow(screen_v, screen_h, "raycasting");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(black_color);

        rendergrid();
        renderwalls();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

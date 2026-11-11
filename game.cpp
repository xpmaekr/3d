#include "dependences.hpp"

int main() {
    InitWindow(screen_v, screen_h, "raycasting");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        place_or_delete();

        BeginDrawing();
        ClearBackground(white_color);

        rendergrid();
        renderwalls();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

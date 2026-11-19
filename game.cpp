#include "dependences.hpp"
#include "player.hpp"

int main() {
    InitWindow(screen_w, screen_h, "raycasting");
    SetTargetFPS(60);
    load();

    Player player;

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(black_color);

        

        rendergrid();
        renderwalls();

        player.render();
        player.update();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

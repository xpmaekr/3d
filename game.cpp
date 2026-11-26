#include "dependences.hpp"
#include "player.hpp"

// Точка входа игры: окно, карта, цикл отрисовки.
int main() {
    InitWindow(screen_w, screen_h, "raycasting");
    SetTargetFPS(60);
    load(); // загрузка карты из map.txt

    Player player;

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);

        rendergrid();   // сетка
        renderwalls();  // стены

        player.render(); // игрок и направление взгляда
        player.update(); // управление

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

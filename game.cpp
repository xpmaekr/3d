#include "raylib.h"
#include <iostream>
#include <vector>

const int greedsize = 40;
const int countx = 20;
const int county = 15;
const Color white_color = RAYWHITE;
const Color greedcolor = LIGHTGRAY;

// Массив для хранения состояния стен (1 - стена есть, 0 - пусто)
int walls[county][countx] = {0};

// Функция обработки ввода и установки стен
void placing() {
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();
    
    int gridX = mouseX / greedsize;
    int gridY = mouseY / greedsize;

    // Проверка на нажатие клавиши (в символах используется IsKeyPressed)
    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
        if (gridX >= 0 && gridX < countx && gridY >= 0 && gridY < county) {
            walls[gridY][gridX] = 1;
            std::cout << "Wall placed\n";
        }
    }
}

// Функция отрисовки сетки
void render_greed() {
    for (int x = 0; x <= countx; x++) {
        DrawLine(x * greedsize, 0, x * greedsize, county * greedsize, greedcolor);
    }
    for (int y = 0; y <= county; y++) {
        DrawLine(0, y * greedsize, countx * greedsize, y * greedsize, greedcolor);
    }
}

// Функция отрисовки стен
void render_walls() {
    for (int y = 0; y < county; y++) {
        for (int x = 0; x < countx; x++) {
            if (walls[y][x] == 1) {
                DrawRectangle(x * greedsize, y * greedsize, greedsize, greedsize, DARKGRAY);
            }
        }
    }
}

int main() {
    InitWindow(countx * greedsize, county * greedsize, "raycastring");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Обработка логики
        placing();

        // Отрисовка кадра
        BeginDrawing();
        ClearBackground(white_color);

        render_greed();
        render_walls();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

#include "dependences.hpp"

// true, если клетка лежит внутри поля
bool cell_inside(int cx, int cy){
    return cx >= 0 && cx < countx && cy >= 0 && cy < county;
}

// ЛКМ — поставить стену, ПКМ — удалить.
// Белым выделяет клетку под курсором.
void place_or_delete(){
    int posx = GetMouseX();
    int posy = GetMouseY();

    if (!IsWindowFocused()) return;

    // Переводим пиксели в координаты клетки
    int cx = posx / gridsize;
    int cy = posy / gridsize;

    if (!cell_inside(cx, cy)) return;

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        walls[cy][cx] = true;
    }
    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)){
        walls[cy][cx] = false;
    }

    DrawRectangle(cx * gridsize, cy * gridsize, gridsize, gridsize, white_color);
}

// Рисует сетку для редактора
void render_grid(){
    for (int x = 0; x < screen_w; x+=gridsize){
        DrawLine(x,0,x,screen_h,gray_color);
    }

    for (int x = 0; x < screen_h; x+=gridsize){
        DrawLine(0,x,screen_w,x,gray_color);
    }
}

// Обнуляет карту
void clearmap(){
    for(int y = 0; y < county; y++){
        for (int x = 0; x < countx; x++){
            walls[y][x] = 0;
        }
    }
}

// Точка входа редактора карты.
// C — очистить карту, S — сохранить в map.txt (и сохранение на выходе).
int main(){
    InitWindow(screen_w, screen_h, "raycasting");
    SetTargetFPS(60);
    load();

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(black_color);

        rendergrid();
        renderwalls();
        place_or_delete();

        if (IsKeyPressed(KEY_C)){
            clearmap();
        }
        if (IsKeyPressed(KEY_S)){
            save();
        }

        EndDrawing();
    }

    // Автосохранение при выходе
    save();

    CloseWindow();
    return 0;
}

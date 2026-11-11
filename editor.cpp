#include "dependences.hpp"

bool cell_inside(int cx, int cy){
    return cx >= 0 && cx < countx && cy >= 0 && cy < county;
}

void place_or_delete(){
    int posx = GetMouseX();
    int posy = GetMouseY();

    if (!IsWindowFocused()) return;

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

void render_grid(){
    for (int x = 0; x < screen_v; x+=gridsize){
        DrawLine(x,0,x,screen_h,gray_color);
    }

    for (int x = 0; x < screen_h; x+=gridsize){
        DrawLine(0,x,screen_v,x,gray_color);
    }
}

void clearmap(){
    for(int y = 0; y < county; y++){
        for (int x = 0; x < countx; x++){
            walls[y][x] = 0;
        }
    }
}

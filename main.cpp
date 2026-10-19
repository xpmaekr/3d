#include<raylib.h>

const int greedsize = 20;
const Color greedcolor = {80,80,80,255};

const int countx = 800 / greedsize;
const int county = 600 / greedsize;

bool walls[county][countx] = {false};

enum class MODE{
    ADD, DEL
};

MODE mod = MODE::ADD;

void placing(){
    int posx = GetMouseX();
    int posy = GetMouseY();

    int greedx = posx / greedsize * greedsize;
    int greedy = posy / greedsize * greedsize;

    DrawRectangle(greedx,greedy,greedsize,greedsize,greedcolor);
}

void render_greed(){
    for (int x = 0; x < 800; x+=greedsize){
        DrawLine(x,0,x,600,greedcolor);
    }

    for (int x = 0; x < 600; x+=greedsize){
        DrawLine(0,x,800,x,greedcolor);
    }
}   

int main(){
    InitWindow(800,600,"raycastring");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground({0,0,0,255});

        render_greed();
        DrawRectangle(100,100,100,100,{255,0,0,255});
        placing();

        EndDrawing();
        PollInputEvents();
        SwapScreenBuffer();
    }

    CloseWindow();
}
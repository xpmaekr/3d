#include<raylib.h>
#include <iostream>
using namespace std;


const int greedsize = 20;

//colors
const Color white_color = {255,255,255,255};
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

    DrawRectangle(greedx,greedy,greedsize,greedsize,white_color);

    if (IsKeyPressed(KEY_T)){
        walls[posy / greedsize][posx / greedsize] = true;
    }

}

void render_walls(){
    cout << "ok" << "\n";
    for(int y = 0; y < county; y++){
        for (int x = 0; x < countx; x++){
            cout << "ok2" << "\n";
            if (walls[y][x]){
                cout << "ok3" << "\n";
                DrawRectangle(x * greedsize,y * greedsize, greedsize, greedsize, greedcolor);
            }
        }
    }
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

        render_walls();
        render_greed();
        placing();

        EndDrawing();
        PollInputEvents();
        SwapScreenBuffer();
    }

    CloseWindow();
}
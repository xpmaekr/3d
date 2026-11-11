#include "dependences.hpp"

bool walls[county][countx] = {false};
MODE mod = MODE::ADD;

void load(){
    ifstream file("map.txt");

    if (!file.is_open()){
        cout << "[WARN] file map.txt doesnt exist";
        return;
    }
    else{
        for (int y = 0; y < county; y++){
            for (int x = 0; x < countx; x++){
                file >> walls[y][x];
            }
        }

        file.close();
        return;
    }
}

void save(){
    ofstream file("map.txt");

    for (int y = 0; y < county; y++){
        for (int x = 0; x < countx; x++){
            file << walls[y][x] << " ";
        }
    }

    file.close();
}

void rendergrid(){
    for (int x = 0; x < screen_v; x+=gridsize){
        DrawLine(x,0,x,screen_h,gridcolor);
    }

    for (int x = 0; x < screen_h; x+=gridsize){
        DrawLine(0,x,screen_v,x,gridcolor);
    }
}

void renderwalls(){
    for(int y = 0; y < county; y++){
        for (int x = 0; x < countx; x++){
            if (walls[y][x]){
                DrawRectangle(x * gridsize, y * gridsize, gridsize, gridsize, gridcolor);
            }
        }
    }
}

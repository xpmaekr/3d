#include "dependences.hpp"

// Карта стен: walls[y][x], true — стена
bool walls[county][countx] = {false};
// Текущий режим редактора
MODE mod = MODE::ADD;

// Загружает карту из файла map.txt.
// Если файла нет, карта остаётся пустой.
void load(){
    ifstream file("map.txt");

    if (!file.is_open()){
        cout << "[WARN] file map.txt doesnt exist";
        return;
    }
    else{
        // Читаем карту построчно: по одному значению на клетку
        for (int y = 0; y < county; y++){
            for (int x = 0; x < countx; x++){
                file >> walls[y][x];
            }
        }

        file.close();
        return;
    }
}

// Сохраняет карту в файл map.txt (значения через пробел)
void save(){
    ofstream file("map.txt");

    for (int y = 0; y < county; y++){
        for (int x = 0; x < countx; x++){
            file << walls[y][x] << " ";
        }
    }

    file.close();
}

// Рисует вертикальные и горизонтальные линии сетки
void rendergrid(){
    for (int x = 0; x < screen_w; x+=gridsize){
        DrawLine(x,0,x,screen_h,gridcolor);
    }

    for (int x = 0; x < screen_h; x+=gridsize){
        DrawLine(0,x,screen_w,x,gridcolor);
    }
}

// Рисует стены: по прямоугольнику на клетку с walls[y][x] == true
void renderwalls(){
    for(int y = 0; y < county; y++){
        for (int x = 0; x < countx; x++){
            if (walls[y][x]){
                DrawRectangle(x * gridsize, y * gridsize, gridsize, gridsize, gridcolor);
            }
        }
    }
}

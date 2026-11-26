#pragma once
#include <vector>
#include "my_ray.hpp"
using namespace std;

// Игрок: позиция, угол взгляда и набор лучей обзора.
class Player{
public:
    Player();   // Центр поля, взгляд вправо (angle = 0)
    void render(); // Рисует точку игрока и луч направления
    void update(); // Обрабатывает управление (A/D — поворот, W — движение вперёд)


private:
    float x_pl;  // координата игрока (пиксели)
    float y_pl;
    float vis_pl; // длина луча обзора

    const int speed = 2; // шаг движения за кадр

    double angle; // угол взгляда в радианах

    vector<My_ray> My_rays; // лучи обзора (пока пустой, заполнение позже)
};

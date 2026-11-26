#pragma once
#include "conf.hpp"
#include <raylib.h>
#include <math.h>

// Один луч обзора игрока: задаётся углом относительно взгляда.
class My_ray
{
private:
    float distance;             // расстояние до стены вдоль луча (заполняется в update)
    const float relative_angle; // угол луча относительно взгляда игрока (радианы)
    const Color My_ray_color = YELLOW; // цвет луча
public:
    My_ray(float relative_angle); // создаёт луч с заданным относительным углом
    // Рисует луч из точки игрока (x_pl, y_pl) с учётом его угла angle_pl
    void render(float x_pl, float y_pl, float angle_pl);
    void update(); // пересчёт расстояния до стены (пока пусто)
};
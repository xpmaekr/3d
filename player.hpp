#pragma once

// Игрок: позиция, угол взгляда и луч обзора.
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
};

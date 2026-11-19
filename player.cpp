#include "player.hpp"
#include "dependences.hpp"
#include <math.h>

// Игрок стартует в центре поля, смотрит вправо (angle = 0)
Player::Player(){
    x_pl = screen_w/2;
    y_pl = screen_h/2;

    vis_pl = 80;
    angle = 0;
}

// Рисует игрока точкой и жёлтым лучом направление взгляда.
// В raylib ось Y направлена вниз, поэтому y уменьшается.
void Player::render(){
    DrawCircle(x_pl,y_pl,5,RED);
    DrawLine(x_pl,y_pl,x_pl+cos(angle)*vis_pl,y_pl-sin(angle)*vis_pl,YELLOW);
}

// Управление: A/D — поворот, W — движение вперёд по направлению взгляда
void Player::update(){
    if(IsKeyDown(KEY_D)){
        angle-=0.03;
    }
    if(IsKeyDown(KEY_A)){
        angle+=0.03;
    }
    if(IsKeyDown(KEY_W)){
        x_pl += cos(angle) * speed;
        y_pl -= sin(angle) * speed;
    }
}

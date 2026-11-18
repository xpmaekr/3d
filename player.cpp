#include "player.hpp"
#include "dependences.hpp"
#include <math.h>


Player::Player(){
    x_pl = screen_v/2;
    y_pl = screen_h/2;

    vis_pl = 80;
    angle = 0;
    const int speed = 5;

}

void Player::render(){
    DrawCircle(x_pl,y_pl,5,RED);
    DrawLine(x_pl,y_pl,x_pl+cos(angle)*vis_pl,y_pl-sin(angle)*vis_pl,YELLOW);
}

void Player::update(){
    if(IsKeyDown(KEY_D)){
        angle-=0.01;
    }
    if(IsKeyDown(KEY_A)){
        angle+=0.01;
    }
    if(IsKeyDown(KEY_W)){
        d
    }
}
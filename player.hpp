#pragma once



class Player{
public:
    Player();
    void render();
    void update();


private:
    float x_pl; 
    float y_pl;
    float vis_pl;

    const int speed = 5;

    double angle;
    
};
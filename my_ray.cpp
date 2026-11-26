#include "my_ray.hpp"

// Луч задаётся только относительным углом; distance заполнится в update
My_ray::My_ray(float local_relative_angle):relative_angle(local_relative_angle){

}

// Рисует луч: конец на расстоянии distance в направлении (relative_angle + angle_pl).
// В raylib ось Y направлена вниз, поэтому y уменьшается.
void My_ray::render(float x_pl, float y_pl, float angle_pl){
    DrawLine(x_pl, y_pl,
             x_pl + cos(relative_angle + angle_pl) * distance,
             y_pl - sin(relative_angle + angle_pl) * distance,
             My_ray_color);
}

void My_ray::update(){
    // пока пусто: логика луча (расстояние до стены) добавляется позже
}

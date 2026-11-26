#pragma once
#include <raylib.h>
#include<math.h>
#include<numbers>

#define pi 3.14159265358979323846

// Угол обзора игрока (радианы): 90 градусов
const float FOV = pi/2;

// Ограничение частоты кадров
const int FPS = 60;

// Число лучей обзора
const int NUM_RAYS = 10;
// Шаг угла между соседними лучами (FOV разбит на NUM_RAYS-1 промежутков)
const float DELTA_RAY_ANGLE = FOV/(NUM_RAYS-1);

// Размер клетки поля в пикселях
const int gridsize = 40;
// Число клеток по горизонтали
const int countx = 20;
// Число клеток по вертикали
const int county = 15;

// Размер экрана в пикселях (w — ширина, h — высота)
const int screen_w = countx * gridsize;
const int screen_h = county * gridsize;

// Цвет сетки
const Color gridcolor = LIGHTGRAY;

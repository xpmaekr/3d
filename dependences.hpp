#pragma once

#include <raylib.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Размер клетки поля в пикселях
const int gridsize = 40;
// Число клеток по горизонтали
const int countx = 20;
// Число клеток по вертикали
const int county = 15;

// Размер экрана в пикселях (w — ширина, h — высота)
const int screen_w = countx * gridsize;
const int screen_h = county * gridsize;

// Цвета
const Color white_color = RAYWHITE;
const Color gridcolor = LIGHTGRAY;
const Color gray_color = LIGHTGRAY;
const Color black_color = BLACK;

// Карта: true — стена, false — пусто
extern bool walls[county][countx];

// Режим редактора
enum class MODE {
    ADD,   // ставить стены (см. place_or_delete)
    DEL    // удалять стены
};

extern MODE mod;

// dependences.cpp: загрузка, сохранение и отрисовка карты
void load();        // читает walls из map.txt
void save();        // записывает walls в map.txt
void rendergrid();  // рисует сетку поля
void renderwalls(); // рисует стены из walls

// editor.cpp: функции режима редактора карты
bool cell_inside(int cx, int cy); // координаты клетки внутри поля
void place_or_delete();           // ставит/удаляет стену мышью
void render_grid();               // отрисовка сетки (для редактора)
void clearmap();                  // очистить карту

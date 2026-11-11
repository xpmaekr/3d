#pragma once

#include <raylib.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Размер клетки и поля в клетках
const int gridsize = 40;
const int countx = 20;
const int county = 15;

// Размер экрана в пикселях
const int screen_v = countx * gridsize;
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
    ADD,
    DEL
};

extern MODE mod;

// dependences.cpp
void load();
void save();
void rendergrid();
void renderwalls();

// editor.cpp
bool cell_inside(int cx, int cy);
void place_or_delete();
void render_grid();
void clearmap();
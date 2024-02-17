#include "Unit.hpp"
#include <iostream>
#pragma once
using namespace std;


class bomb: public Unit{
    int i_ticks;
    int p_ticks;
    SDL_Rect src;
    public:
    bool existence;
    SDL_Rect mover;
    bomb(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    void draw();
    // ~bomb();
    int x;
    int y;
    void toggle();
    void auto_destruct();
    SDL_Rect get_mover();

};
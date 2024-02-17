#include<SDL.h>
#pragma once
// Unit class is well implemented, no need to change it

class Unit{
    SDL_Renderer* gRenderer;
    SDL_Texture* assets;
public:
    int number=1;
    Unit(SDL_Renderer*, SDL_Texture*);
    void draw(SDL_Rect srcRect, SDL_Rect moverRect);
    virtual void animate();
    virtual void destroy();
    virtual void toggle();
};

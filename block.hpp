#include "Unit.hpp"
#include <iostream>
using namespace std;


class block: public Unit{
    SDL_Rect src,mover;
    public:
    int x; 
    int y;
    bool existence;
    block(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    void draw();
    void toggle();
};
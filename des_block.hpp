#include "Unit.hpp"
#include <iostream>
using namespace std;


class des_block:public Unit{
    SDL_Rect src,mover;
    bool existence;
    public:
    int x,y;
    bool get_existence();
    void toggle();
    // void destroy();
    des_block(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    void draw();
};
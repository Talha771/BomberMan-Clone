#include "bomb.hpp"    

bomb::bomb(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov) : Unit(rend, ast), mover(mov) {
    src = { 135 , 16, 14, 15 };
    i_ticks = SDL_GetTicks();
    existence = true;
    x = mover.x / 64;
    y = mover.y / 64;
}
void bomb::draw() {
    p_ticks = SDL_GetTicks();
    if (p_ticks < i_ticks + 3000) {
        Unit::draw(src, mover);
    }
    else {
        src = { 0 , 0, 16, 14 };
        Unit::draw(src, mover);
        existence = false;
    }
    // cout<<"Lmao";   
}
SDL_Rect bomb::get_mover() {
    return mover;
}
void bomb::toggle() {
    cout << "bomb toggle";
}



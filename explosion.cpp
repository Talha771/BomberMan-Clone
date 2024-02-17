#include "explosion.hpp"    

explosion::explosion(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov) : Unit(rend, ast), mover(mov) {
    src = { 0 , 0, 16, 14 };
    i_ticks = SDL_GetTicks();
    existence = true;
    x = mover.x / 64;
    y = mover.y / 64;
}
void explosion::draw() {
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
SDL_Rect explosion::get_mover() {
    return mover;
}


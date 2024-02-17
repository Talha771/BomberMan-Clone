#include "block.hpp"

block::block(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov) : Unit(rend, ast), mover(mov) {
    src = {17, 30, 16, 14};
    existence = true;
    int x = mover.x / 64;
    int y = mover.y / 64;
}
void block::toggle() {
    // existence=false;
    cout << "block_existence:" << existence;
}
void block::draw() {
    Unit::draw(src, mover);
    // cout<<"Lmao";
}

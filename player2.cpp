#include "player2.hpp"

player2::player2(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov) : Unit(rend, ast), mover(mov) {
    // ast = loadTexture("assets_big.png");
    src = { 185, 84, 15, 24 };
    x = mover.x / 64;
    y = mover.y / 64;
}

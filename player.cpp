#include "player.hpp"

// #include <windows.h>
player::player(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov) : Unit(rend, ast), mover(mov) {
    // ast = loadTexture("assets_big.png");
    src = { 64, 45, 75, 120 };
    x = mover.x / 64;
    y = mover.y / 64;
}
void player::draw() {
    // if ((dir_anim == 'd')) {000
    //     cout << "Player is moving down" << endl;
    //     switch (anim_state) {
    //     case 0:
    //         src = { 325, 225, 75, 120 };
    //         mover.y += 15; // replace with box size
    //         break;
    //     case 1:
    //         src = { 405, 225, 75, 120 };
    //         mover.y += 15;
    //         break;
    //     case 2:
    //         src = { 485, 225, 75, 120 };
    //         mover.y += 15;
    //     case 3:
    //         src = { 325, 225, 75, 120 };
    //         // mover.y += 15;
    //         step_complete = true;
    //         dir_anim = '0';
    //         break;
    //     default:
    //         break;
    //     }
    //     anim_state++;
    //     anim_state = anim_state % 3;
    // }

    // else if ((dir_anim == 'u')) {
    //     cout << "Player is moving up" << endl;
    //     switch (anim_state) {
    //     case 0:
    //         src = { 80, 235, 75, 110 };
    //         mover.y -= 15;
    //         break;
    //     case 1:
    //         src = { 160, 225, 75, 120 };
    //         mover.y -= 15;

    //         break;
    //     case 2:
    //         src = { 0, 230, 75, 120 };
    //         mover.y -= 15;
    //         break;
    //     case 3:
    //         src = { 80, 235, 75, 110 };
    //         // mover.y -= 15;f
    //         step_complete = true;
    //         dir_anim = '0';
    //         break;
    //     default:
    //         break;
    //     }
    //     anim_state++;
    //     anim_state = anim_state % 4;
    // }
    // else if ((dir_anim = 'r')) {
    //     cout << "Player is moving right" << endl;
    //     switch (anim_state) {
    //     case 0:
    //         src = { 255, 355, 80, 120 };
    //         mover.x += 15;
    //         break;
    //     case 1:
    //         src = { 340, 360, 80, 115 };
    //         mover.x += 15;

    //         break;
    //     case 2:
    //         src = { 425, 365, 80, 110 };
    //         mover.x += 15;
    //         break;
    //     case 3:
    //         src = { 255, 355, 80, 120 };
    //         step_complete = true;
    //         dir_anim = '0';
    //         break;
    //     default:
    //         break;
    //     }
    //     anim_state++;
    //     anim_state = anim_state % 4;
    // }
    // else if ((dir_anim == 'l')) {
    //     cout << "Player is moving left" << endl;
    //     switch (anim_state) {
    //     case 0:
    //         src = { 0, 350, 80, 120 };
    //         mover.x -= 15;
    //         break;
    //     case 1:
    //         src = { 85, 355, 75, 115 };
    //         mover.x -= 15;
    //         break;
    //     case 2:
    //         src = { 170, 365, 80, 110 };
    //         mover.x -= 15;
    //         break;
    //     case 3:
    //         src = { 0, 350, 80, 120 };
    //         step_complete = true;
    //         dir_anim = '0';
    //         break;
    //     default:
    //         break;
    //     }
    //     anim_state++;
    //     anim_state = anim_state % 4;
    // }
    // else if ((!alive) && !(step_complete)) {
    //     switch (anim_state) {
    //     case 0:
    //         src = { 0, 480, 75, 115 };
    //         break;
    //     case 1:
    //         src = { 95, 490, 75, 110 };
    //         break;
    //     case 2:
    //         src = { 180, 490, 75, 110 };
    //         break;
    //     case 3:
    //         src = { 265, 490, 75, 110 };
    //         break;
    //     case 4:
    //         src = { 350, 490, 75, 110 };
    //         break;
    //     case 5:
    //         src = { 440, 500, 75, 100 };
    //         step_complete = true;
    //         break;
    //     default:
    //         break;
    //     }
    //     anim_state++;
    //     anim_state = anim_state % 6;
    // }
    // else {
    //     // src = { 320, 225, 75, 120 };
    //     // movedown();
    // }
    // if (step_complete) {
    //     anim_state == 0;
    // }
    Unit::draw(src, mover);
}
void player::toggle() { }

void player::move(char dir) {
    x = mover.x / 64;
    y = mover.y / 64;
    if (dir == 'd') {
        dir_anim = 'd';
        x = mover.x / 64;
        y = (mover.y / 64) + 1;
    }
    if (dir == 'u') {
        dir_anim = 'u';
        x = mover.x / 64;
        y = (mover.y / 64) - 1;
    }
    if (dir == 'l') {
        dir_anim = 'l';
        x = (mover.x / 64) - 1;
        y = (mover.y / 64);
    }
    if (dir == 'r') {
        dir_anim = 'r';
        x = (mover.x / 64) + 1;
        y = (mover.y / 64);
    }
}
bomb player::generate_bomb(SDL_Renderer* renderer, SDL_Texture* assets) {
    bomb b1(renderer, assets, mover);
    return b1;
}

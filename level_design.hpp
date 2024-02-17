#include<SDL.h>
#include "bomb.hpp"
#include "game.hpp"
#include<iostream>
#include "player.hpp"
#include "block.hpp"
#include "des_block.hpp"
#include "explosion.hpp"
#include<list>
#include <iostream>
using namespace std;
class level_design :public Game {
    public:
    player p1;
    void presence_checker();
    list <bomb*> bombs;
    list <block*> block1;
    list <des_block*> des_block1;
    list <explosion*> explosions;


    void explode();
    SDL_Renderer* gRenderer;
    SDL_Texture* assets;
    level_design(SDL_Renderer*, SDL_Texture*);
    void drawObjects();
    sdl_grid grid[12][10];
    void generate_sdl_grid();
    void generate_boundary_wall();
    void generate_indes();
    void generate_design();
    void generate_explosions(int, int); // replaces explosions where bomb goes off.
    void testing_func();
};

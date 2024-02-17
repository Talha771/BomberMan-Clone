#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "sdl_grid.cpp"
#include "player.hpp";
#pragma once


class Game {
    //Screen dimension constants
    const int SCREEN_WIDTH = 760;
    const int SCREEN_HEIGHT = 640;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    SDL_Texture* menu = NULL;
    //global reference to png image sheets
    SDL_Texture* assets = NULL;
    //audio 
    Mix_Chunk* beatSFX = NULL;
    Mix_Music* bgMusic = NULL;

    public:
    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture(std::string path);
    void run();
    bool allow_movt(sdl_grid& loc, player* player);
};


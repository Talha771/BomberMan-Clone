#include "game.hpp"

#include <windows.h>

#include <vector>

#include "level_design.hpp"
bool Game::init() {
    //Initialization flag
    bool success = true;
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else {
     //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("Warning: Linear texture filtering not enabled!");
        }

        //Create window
        gWindow = SDL_CreateWindow("Bomberman Recreated", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else {
         //Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL) {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else {
             //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
                if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
                    printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

bool Game::loadMedia() {
    //Loading success flag
    bool success = true;

    beatSFX = Mix_LoadWAV("Bomberman_bomb.wav");
    bgMusic = Mix_LoadMUS("bomberman_theme.wav");
    assets = loadTexture("walls.png");
    // gTexture = loadTexture("frame.png");
    gTexture = loadTexture("main_menu.png");
    if (assets == NULL || gTexture == NULL) {
        printf("Unable to run due to error: %s\n", SDL_GetError());
        success = false;
    }
    if (beatSFX == NULL || bgMusic == NULL) {
        printf("Unable to load music: %s \n", Mix_GetError());
        success = false;
    }

    return success;
}

void Game::close() {
    //Free loaded images
    SDL_DestroyTexture(assets);
    assets = NULL;
    SDL_DestroyTexture(gTexture);
    //Free audio assets
    Mix_FreeChunk(beatSFX);
    beatSFX = NULL;
    Mix_FreeMusic(bgMusic);
    bgMusic = NULL;
    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;
    //Quit SDL subsystems
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture* Game::loadTexture(std::string path) {
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else {
     //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

bool Game::allow_movt(sdl_grid& loc, player* p1) {
    if (loc.occupied == false) {
        Unit* u1;
        u1 = p1;
        loc.change_state();
        loc.data = u1;
        return true;
    }
    else {
        cout << "It is occupied" << endl;
        return false;
    }
}
void Game::run() {
    bool quit = false, bomb_effect = false;
    bool game_start = false;
    SDL_Event e;
    level_design level_design(gRenderer, assets);
    // menu.open();

    while (!quit) {
        const auto state = SDL_GetKeyboardState(NULL);

        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            SDL_PumpEvents();

            if (state[SDL_SCANCODE_DOWN]) {
                level_design.p1.move('d');
                sdl_grid& s1 = level_design.grid[level_design.p1.x][level_design.p1.y];
                if (allow_movt(s1, &level_design.p1)) {
                    level_design.p1.mover = level_design.grid[level_design.p1.x][level_design.p1.y].x;
                    level_design.grid[level_design.p1.x][level_design.p1.y - 1].change_state();
                }
                else {
                    level_design.p1.move('u');
                }
            }
            if (state[SDL_SCANCODE_UP]) {
                level_design.p1.move('u');
                sdl_grid& s1 = level_design.grid[level_design.p1.x][level_design.p1.y];
                if (allow_movt(s1, &level_design.p1)) {
                    level_design.p1.mover = level_design.grid[level_design.p1.x][level_design.p1.y].x;
                    level_design.grid[level_design.p1.x][level_design.p1.y + 1].change_state();
                }
                else {
                    level_design.p1.move('d');
                }
            }
            if (state[SDL_SCANCODE_LEFT]) {
                level_design.p1.move('l');
                sdl_grid& s1 = level_design.grid[level_design.p1.x][level_design.p1.y];
                if (allow_movt(s1, &level_design.p1)) {
                    level_design.p1.mover = level_design.grid[level_design.p1.x][level_design.p1.y].x;
                    level_design.grid[level_design.p1.x + 1][level_design.p1.y].change_state();
                }
                else {
                    level_design.p1.move('r');
                }
                // Sleep(200);
            }
            if (state[SDL_SCANCODE_RIGHT]) {
                level_design.p1.move('r');
                sdl_grid& s1 = level_design.grid[level_design.p1.x][level_design.p1.y];
                if (allow_movt(s1, &level_design.p1)) {
                    level_design.p1.mover = level_design.grid[level_design.p1.x][level_design.p1.y].x;
                    level_design.grid[level_design.p1.x - 1][level_design.p1.y].change_state();
                }
                else {
                    level_design.p1.move('l');
                }
                // Sleep(200);
            }
            if (state[SDL_SCANCODE_SPACE]) {
                bomb* b1 = new bomb(level_design.p1.generate_bomb(gRenderer, assets));
                level_design.bombs.push_back(b1);
                level_design.grid[level_design.p1.x][level_design.p1.y].occupied = true;
                level_design.drawObjects();
                bomb_effect = true;
            }
            if (state[SDL_SCANCODE_RETURN]) {
                if (game_start == false) {
                    // menu.close();
                    game_start = true;
                    cout << "Opening game" << endl;
                    cout << "Starting game, grid should generate" << endl;
                    level_design.generate_sdl_grid();
                    level_design.generate_design();
                    gTexture = loadTexture("frame.png");
                }

            }
            if (state[SDL_SCANCODE_Q]) {
                quit = true;
            }
            if (state[SDL_SCANCODE_R]) {
                gTexture = loadTexture("rules.png");
            }
            if (state[SDL_SCANCODE_B]) {
                gTexture = loadTexture("main_menu.png");
            }
            if (/*Mix_PlayingMusic() == 0 &&*/ bomb_effect == true) {
                //Play the soundeffect once
                Mix_PlayChannel(-1, beatSFX, 0);
                bomb_effect = false;
            }
        }
        if (Mix_PlayingMusic() == 0) {
            //Play the bgMusic
            Mix_PlayMusic(bgMusic, 2);
        }

        SDL_RenderClear(gRenderer);                       //removes everything from renderer
        SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);  //Draws background to renderer
        //***********************draw the objects here********************
        if (/*menu.closed*/ game_start == true) {
            level_design.drawObjects();
        }
//****************************************************************
        SDL_RenderPresent(gRenderer);  //displays the updated renderer

        SDL_Delay(2);  //causes sdl engine to delay for specified miliseconds
    }
}

#include "level_design.hpp"

#include <iostream>
using namespace std;

void level_design::generate_boundary_wall() {
    // top wall
    for (int i = 0; i < 12; i++) {
        if (grid[i][0].occupied == false) {
            block* b1 = new block(gRenderer, assets, grid[i][0].x);
            grid[i][0].data = b1;
            grid[i][0].change_state();
            block1.push_back(b1);
        }
    }
    // left wall
    for (int i = 0; i < 10; i++) {
        if (grid[0][i].occupied == false) {
            block* b1 = new block(gRenderer, assets, grid[0][i].x);
            grid[0][i].data = b1;
            grid[0][i].change_state();
            block1.push_back(b1);
        }
    }
    for (int i = 0; i < 12; i++) {
        if (grid[i][9].occupied == false) {
            block* b1 = new block(gRenderer, assets, grid[i][9].x);
            grid[i][9].data = b1;
            grid[i][9].change_state();
            block1.push_back(b1);
        }
    }
    for (int i = 0; i < 10; i++) {
        if (grid[11][i].occupied == false) {
            block* b1 = new block(gRenderer, assets, grid[11][i].x);
            grid[11][1].data = b1;
            grid[11][i].change_state();
            block1.push_back(b1);
        }
    }
}
void level_design::generate_indes() {
    // player p1 (gRenderer,assets, grid[2][3].x);
    int randomX, randomY;
    for (int j = 1; j < 9; j += 1) {
        for (int i = 1; i < 12; i += 1) {
            randomX = 2 + rand() % 8;
            randomY = 2 + rand() % 11;
            if (grid[randomX][randomY].occupied == false) {
                des_block* db1 = new des_block(gRenderer, assets, grid[randomX][randomY].x);
                grid[randomX][randomY].data = db1;
                grid[randomX][randomY].change_state();
                des_block1.push_back(db1);
            }
        }
    }
}
void level_design::generate_explosions(int i, int j) {
    if (grid[i][j].occupied == false) {
        // des_block* db1 = new des_block(gRenderer, assets, grid[i][j].x);
        explosion* ex_x = new explosion(gRenderer, assets, grid[i][j].x);
        grid[i][j].data = ex_x;
        // grid[i][j].change_state();
        explosions.push_back(ex_x);
    }
}

void level_design::generate_sdl_grid() {
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 12; i++) {
            grid[i][j].x = { i * 64, j * 64, 64, 64 };
            grid[i][j].occupied = false;
            grid[i][j].data = NULL;
        }
    }
    cout << "grid has been created" << endl;
}

void level_design::drawObjects() {
    p1.draw();
    // call draw functions of all the objects here
    for (block* b : block1)
        if (b->existence == false) {
            grid[b->x][b->y].change_state();
            delete b;
            block1.remove(b);
        }
        else {
            b->draw();
        }
    for (des_block* db : des_block1)
        if (db->get_existence() == false) {
            grid[db->x][db->y].change_state();
            delete db;
            generate_explosions(db->x, db->y);
            // explosion.draw();

            des_block1.remove(db);
        }
        else {
            db->draw();
        }
    for (explosion* e : explosions)
        e->draw();

    for (bomb* bo : bombs)
        if (bo->existence == false) {
            if (grid[bo->x][bo->y + 1].occupied == false) {
                if (grid[bo->x][bo->y + 2].occupied == false) {
                    if (grid[bo->x][bo->y + 3].occupied == false) {
                        //room for powerups maybe?
                    }
                    else {
                        grid[bo->x][bo->y + 3].data->toggle();
                    }
                }
                else {
                    grid[bo->x][bo->y + 2].data->toggle();
                }
            }
            else {
                grid[bo->x][bo->y + 1].data->toggle();
            }

            if (grid[bo->x][bo->y - 1].occupied == false) {
                if (grid[bo->x][bo->y - 2].occupied == false) {
                    if (grid[bo->x][bo->y - 3].occupied == false) {
                        //room for powerups maybe?
                    }
                    else {
                        grid[bo->x][bo->y - 3].data->toggle();
                    }
                }
                else {
                    grid[bo->x][bo->y - 2].data->toggle();
                }
            }
            else {
                grid[bo->x][bo->y - 1].data->toggle();
            }

            if (grid[bo->x + 1][bo->y].occupied == false) {
                if (grid[bo->x + 2][bo->y].occupied == false) {
                    if (grid[bo->x + 3][bo->y].occupied == false) {
                        //room for powerups maybe?
                    }
                    else {
                        grid[bo->x + 3][bo->y].data->toggle();
                    }
                }
                else {
                    grid[bo->x + 2][bo->y].data->toggle();
                }
            }
            else {
                grid[bo->x + 1][bo->y].data->toggle();
            }

            if (grid[bo->x - 1][bo->y].occupied == false) {
                if (grid[bo->x - 2][bo->y].occupied == false) {
                    if (grid[bo->x - 3][bo->y].occupied == false) {
                        //room for powerups maybe?
                    }
                    else {
                        grid[bo->x - 3][bo->y].data->toggle();
                    }
                }
                else {
                    grid[bo->x - 2][bo->y].data->toggle();
                }
            }
            else {
                grid[bo->x - 1][bo->y].data->toggle();
            }

            // if (grid[bo->x][bo->y - 1].occupied == true) {
            //     grid[bo->x][bo->y - 1].data->toggle();
            // }
            // if (grid[bo->x + 1][bo->y].occupied == true) {
            //     grid[bo->x + 1][bo->y].data->toggle();
            // }
            // if (grid[bo->x - 1][bo->y].occupied == true) {
            //     grid[bo->x - 1][bo->y].data->toggle();
            // }
            grid[bo->x][bo->y].change_state();
            delete bo;
            bombs.remove(bo);

        }
        else {
            bo->draw();
        }
}
void level_design::generate_design() {
    // generate_sdl_grid();
    generate_boundary_wall();
    generate_indes();
    // testing_func();
}
void level_design::testing_func() {
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 12; i++) {
            if (grid[i][j].occupied == false) {
                des_block db(gRenderer, assets, grid[i][j].x);
                grid[i][j].data = &db;
                des_block1.push_back(&db);
            }
        }
    }
}
level_design::level_design(SDL_Renderer* renderer, SDL_Texture* asst) : gRenderer(renderer), assets(asst), p1(renderer, asst, { 64, 64, 64, 64 }) { }
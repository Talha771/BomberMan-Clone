#include "Unit.hpp"
class sdl_grid:public Unit{
    SDL_Rect grid [800/16][640/16];
    public:
    void generate_grid(){
        for (int i=0; i<(800/16);i++){
            for (int j=0; j<640/16;j++){
                grid [i][j]= {i*16,j*16,16,16};
            }
        
        }
    }
};

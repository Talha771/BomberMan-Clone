#include "des_block.hpp"  
    des_block::des_block(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
        src = {0  , 30, 16, 14};
        existence=true;
        x= mover.x/64;
        y=mover.y/64;
    }
    bool des_block::get_existence(){
        return existence;
    }
    void des_block::toggle(){
        existence=false;
        cout<<"des_block toggle";
    }

    void des_block::draw(){
    Unit::draw(src,mover);
    }
    

    
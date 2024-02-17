    #include "Unit.hpp"
#include <iostream>
using namespace std;


// Unit class is well implemented, no need to change it

Unit::Unit(SDL_Renderer* rend, SDL_Texture* ast): gRenderer(rend), assets(ast){

}

void Unit::draw(SDL_Rect srcRect, SDL_Rect moverRect){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}
void Unit::animate(){
    cout<<"running animate function";
    return ;
}
void Unit::destroy(){
    return;
}
void Unit::toggle(){
    cout<<"Unit toggle";
}
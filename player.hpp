#include "Unit.hpp"
#include "bomb.hpp"
#pragma once;
class player : public Unit {

  bool health;
  char dir_anim;
  bool step_complete = false;
  int anim_state = 0;
  bool alive = true;
  public:
  player(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
  SDL_Rect src, mover;
  void draw();
  void toggle();
  void move(char dir);
  int x, y;
  bomb generate_bomb(SDL_Renderer*, SDL_Texture*);
};
#ifndef FOOD_H
#define FOOD_H

#include "SDL.h"

class Food {
  public:
    enum class FoodType { kUp, kDown, kLeft, kRight };
    int getPointX();
    int getPointY();
    void setPointX(int& x);
    void setPointY(int& y);
    bool FoodCell(int& x, int& y) const;
  private:
    SDL_Point point;
};

#endif
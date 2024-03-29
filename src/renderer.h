#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "food.h"
#include "gridmodel.h"

class Renderer {
  public:
    Renderer(const std::size_t screen_width, const std::size_t screen_height,
             const std::size_t grid_width, const std::size_t grid_height);
    ~Renderer();
  
    void Render(Snake snake, Food &food, Food &magic_food);
    void Render(Snake snake, Food &food);
    void UpdateWindowTitle(int score, int fps);
 
  private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;
  
    const std::size_t screen_width;
    const std::size_t screen_height;
    const std::size_t grid_width; // "number of cells in the width of the grid."
    const std::size_t grid_height; // "number of cells in the height of the grid."
};

#endif
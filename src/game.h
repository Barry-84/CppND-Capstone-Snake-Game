#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "food.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
  public:
    enum class Mode { kManual, kAuto };

    Game(std::size_t grid_width, std::size_t grid_height, Mode mode);
    void Run(Controller &controller, Renderer &renderer,
             std::size_t target_frame_duration);
    int GetScore() const;
    int GetSize() const;

  private:
    Mode mode = Mode::kManual;
    Snake snake;
    Food food, magic_food;
    std::vector<GridModel::Node*> path;
  
    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;

    int score;
  
    void PlaceFood();
    void PlaceMagicFood();
    void Update();
};

#endif
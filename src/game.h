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
  Game(std::size_t grid_width, std::size_t grid_height);
  //void Run(Controller const &controller, Renderer &renderer,
  //         std::size_t target_frame_duration);
  void Run(Controller &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  //SDL_Point food, magic_food;
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
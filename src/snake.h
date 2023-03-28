#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake {
  public:
    enum class Direction { kUp, kDown, kLeft, kRight };
    enum class State { kNone, kGrowing, kShrinking };

    Snake(int grid_width, int grid_height)
        : grid_width(grid_width),
          grid_height(grid_height),
          head_x(grid_width / 2),
          head_y(grid_height / 2),
          size{1},
          alive{true},
          speed{0.1f} {}

    void Update();
  
    void SetState(Snake::State new_state);
    void SetSpeed(float deltaSpeed);
    void SetDirection(Direction newDirection);
  
    bool SnakeCell(int& x, int& y) const;
  
    int GetSize() const;
    bool GetAlive() const;
    float GetHeadX() const;
    float GetHeadY() const;
    Direction GetDirection() const;
    std::vector<SDL_Point> GetBody() const; // uses move semantics: vector will be moved on return

  private:
    void UpdateHead();
    void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);
  
    Direction direction = Direction::kUp;
    State state = State::kNone;
 
    std::vector<SDL_Point> body;
  
    int grid_width;
    int grid_height;
    int size;
    bool alive;
    float speed;
    float head_x;
    float head_y;
}; 

#endif
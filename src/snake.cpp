#include "snake.h"
#include <cmath>
#include <iostream>

void Snake::Update() {
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)};  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    UpdateBody(current_cell, prev_cell);
  }
}

void Snake::UpdateHead() {
  switch (direction) {
    case Direction::kUp:
      head_y -= speed;
      break;

    case Direction::kDown:
      head_y += speed;
      break;

    case Direction::kLeft:
      head_x -= speed;
      break;

    case Direction::kRight:
      head_x += speed;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  head_x = fmod(head_x + grid_width, grid_width);
  head_y = fmod(head_y + grid_height, grid_height);
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
  // Add previous head location to vector
  body.push_back(prev_head_cell);
  
  switch (state) {
    case State::kGrowing:
      SetState(State::kNone);
      size++;
      break;
    case State::kShrinking:
      // Remove the tail from the vector twice.
      body.erase(body.begin());
      body.erase(body.begin());
      SetState(State::kNone);
      size--;
      break;
    case State::kNone:
      // Remove the tail from the vector.
      body.erase(body.begin());
      break;
  }
  
  // Check if the snake has died.
  for (auto const &item : body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      alive = false;
    }
  }
}

void Snake::SetState(Snake::State new_state) { state = new_state; }
void Snake::SetSpeed(float deltaSpeed) { speed += deltaSpeed; };
void Snake::SetDirection(Snake::Direction newDirection) {direction = newDirection; };

int Snake::GetSize() const { return size; }
bool Snake::GetAlive() const { return alive; }
float Snake::GetHeadX() const { return head_x; }
float Snake::GetHeadY() const { return head_y; }
Snake::Direction Snake::GetDirection() const { return direction; };
std::vector<SDL_Point> Snake::GetBody() const { return body; };

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int& x, int& y) const {
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}
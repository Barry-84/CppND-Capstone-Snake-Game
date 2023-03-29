#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height, Mode mode)
    : score{0},
      snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      mode(mode) {
  PlaceFood();
  if (mode == Mode::kManual) {
    PlaceMagicFood();
  }
}

void Game::Run(Controller &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();
    
    if (mode == Mode::kAuto) {
      std::vector<GridModel::Node*> path = controller.PlanPath(snake, snake.GetHeadX(), snake.GetHeadY(), food.getPointX(), food.getPointY());
      controller.AutoGuideSnake(snake);
    } else {
      // Input, Update, Render - the main game loop.
      controller.HandleInput(running, snake);
    }

    Update();
    if (mode == Mode::kAuto) {
      renderer.Render(snake, food);
    } else {
      renderer.Render(snake, food, magic_food);
    }

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.setPointX(x);
      food.setPointY(y);
      return;
    }
  }
}

void Game::PlaceMagicFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake or food item before placing
    // magic food.
    if (!snake.SnakeCell(x, y) && !food.FoodCell(x,y)) {
      magic_food.setPointX(x);
      magic_food.setPointY(y);
      return;
    }
  }
}

  
void Game::Update() {
  if (!snake.GetAlive()) return;

  snake.Update();

  int new_x = static_cast<int>(snake.GetHeadX());
  int new_y = static_cast<int>(snake.GetHeadY());

  // Check if there's food over here
  if (food.getPointX() == new_x && food.getPointY() == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.SetState(Snake::State::kGrowing);
    snake.SetSpeed(0.02);
  } else if (mode == Mode::kManual && magic_food.getPointX() == new_x && magic_food.getPointY() == new_y) {
    PlaceMagicFood();
    if (snake.GetSize() > 1) {
      // Shrink snake and decrease speed.
      snake.SetState(Snake::State::kShrinking);
      snake.SetSpeed(-0.02);
    }
  }
    
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.GetSize(); }

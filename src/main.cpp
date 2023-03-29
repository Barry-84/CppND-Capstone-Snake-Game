#include <iostream>
#include <string>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller(kGridWidth, kGridHeight);

  std::cout << "Enter 1 to control the snake manually. Enter 2 to control the snake automatically." << std::endl;
  std::string input;
  getline(std::cin, input);

  Game::Mode mode = Game::Mode::kManual;
  //if (input.compare("2") == 0) {
    mode = Game::Mode::kAuto;
  //}


  Game game(kGridWidth, kGridHeight, mode);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}
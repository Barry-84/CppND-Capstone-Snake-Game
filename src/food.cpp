#include "food.h"

void Food::setPointX(int& x) {
 point.x = x;
}

void Food::setPointY(int& y) {
  point.y = y;
}

int Food::getPointX() {
  return point.x;
}

int Food::getPointY() {
  return point.y;
}

bool Food::FoodCell(int& x, int& y) const {
  if (x == point.x && y == point.y) {
    return true;
  }
  return false;
}


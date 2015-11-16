#include <cmath>

#include "circle2.hpp"

circle::circle(double x, double y, double r) {
  this->x = x;
  this->y = y;
  this->r = r;
}

double circle::getArea(void) {
  return M_PI*r*r;
}

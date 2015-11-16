#include <cmath>
#include <iostream>

class circle {
  double x, y, r;
 public:
  circle(double x, double y, double r) {
    this->x = x;
    this->y = y;
    this->r = r;
  }
  double getArea(void) {
    return M_PI*r*r;
  }
};

int main() {
  circle c(1.2, 3.4, 2.);
  std::cout << "c.getArea() = " << c.getArea() << std::endl;
  return 0;
}

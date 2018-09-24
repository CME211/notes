#include <cmath>

#include "circle3.hpp"

namespace geometry {

double circle::getPerimeter(void) {
  return 2.*M_PI*r;
}

}

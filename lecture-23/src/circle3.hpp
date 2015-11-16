#ifndef CIRCLE3_HPP
#define CIRCLE3_HPP

namespace geometry {

class circle {
  double x, y, r;
 public:
  circle(double x, double y, double r);
  double getArea(void);
  double getPerimeter(void); 
};

}

#endif /* CIRCLE3_HPP */

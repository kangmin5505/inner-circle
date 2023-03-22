#include <iostream>

#include "bsp.hpp"

int main(void) {
  std::cout.setf(std::ios::boolalpha);
  std::cout << bsp::bsp(Point(0.0f, 0.0f), Point(0.0f, 1.0f), Point(1.0f, 0.0f),
                        Point(2.0f, 2.0f))
            << std::endl; // false
  std::cout << bsp::bsp(Point(0.0f, 0.0f), Point(0.0f, 1.0f), Point(1.0f, 0.0f),
                        Point(0.0f, 0.0f))
            << std::endl; // false
  std::cout << bsp::bsp(Point(0.0f, 0.0f), Point(0.0f, 1.0f), Point(1.0f, 0.0f),
                        Point(0.4f, 0.4f))
            << std::endl; // true
  std::cout << bsp::bsp(Point(0.0f, 0.0f), Point(0.0f, 2.0f), Point(2.0f, 0.0f),
                        Point(0.5f, 0.5f))
            << std::endl; // true
  std::cout << bsp::bsp(Point(0.0f, 0.0f), Point(0.0f, 2.0f), Point(2.0f, 0.0f),
                        Point(1.0f, 1.0f))
            << std::endl; // false
  return 0;
}

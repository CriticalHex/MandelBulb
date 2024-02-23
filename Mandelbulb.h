#ifndef MANDEL_H
#define MANDEL_H

#include <SFML\Graphics.hpp>
#include <vector>

class Mandelbulb {
private:
  std::vector<double> points;

public:
  Mandelbulb();
  ~Mandelbulb();
};

#endif
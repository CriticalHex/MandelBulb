#ifndef MANDEL_H
#define MANDEL_H

#include "OGLFuncs.h"
#include "Pixel.h"
#include <GL/glu.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <cmath>
#include <thread>
#include <vector>
class Mandelbulb {
private:
  std::vector<GLdouble> vertices;
  std::vector<GLfloat> colors;
  std::vector<Pixel *> pixels;
  UINT numPoints = 0;

public:
  void draw();
  void initialize();
  void calculate();
  Mandelbulb();
  ~Mandelbulb();
};

#endif
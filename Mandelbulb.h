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
  std::vector<std::thread> threads;
  UINT numPoints = 0;
  UINT numThreads = 12;

public:
  void draw();
  void initialize();
  void calculate();
  void chunkIterate(UINT start, UINT end);
  Mandelbulb();
  ~Mandelbulb();
};

#endif
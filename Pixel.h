#ifndef PIXEL_H
#define PIXEL_H

#include "OGLFuncs.h"
#include <GL/glu.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <cmath>
#include <vector>

class Pixel {
private:
public:
  double n = 8;
  double x, y, z, r, theta, phi;
  double x0, y0, z0;
  bool escaped = false;
  std::vector<GLfloat> *colors;
  UINT index;
  void iterate();
  Pixel(double x, double y, double z, std::vector<GLfloat> *colors, UINT index);
  ~Pixel();
};

#endif
#include "Mandelbulb.h"
#include <iostream>

Mandelbulb::Mandelbulb() { initialize(); }

Mandelbulb::~Mandelbulb() {
  for (auto pixel : pixels) {
    delete pixel;
  }
  pixels.clear();
}

void Mandelbulb::initialize() {
  double resolution = 2.f / (128);
  double x, y, z;
  for (x = -1.0; x < 1.0; x += resolution) {
    for (y = -1.0; y < 1.0; y += resolution) {
      for (z = -1.0; z < 1.0; z += resolution) {
        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(z);
        colors.push_back(1);
        colors.push_back(1);
        colors.push_back(1);
        colors.push_back(1);
        pixels.push_back(new Pixel(x, y, z, &colors, numPoints));
        numPoints++;
      }
    }
  }
  std::cout << "Points: " << numPoints << std::endl;
}

void Mandelbulb::draw() {
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glVertexPointer(3, GL_DOUBLE, 0, vertices.data());
  glColorPointer(4, GL_FLOAT, 0, colors.data());

  glDrawArrays(GL_POINTS, 0, numPoints);

  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
}

void Mandelbulb::calculate() {
  for (auto pixel : pixels) {
    pixel->iterate();
  }
}
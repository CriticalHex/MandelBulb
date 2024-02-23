#ifndef OGLFUNCS_H
#define OGLFUNCS_H

#include <GL/glu.h>
#include <SFML/Graphics.hpp>

inline void glColorSF(sf::Color color) {
  glColor3f(color.r / 255.f, color.g / 255.f, color.b / 255.f);
}

#endif
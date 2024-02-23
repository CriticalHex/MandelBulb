#ifndef DEBUGRENDERER_H
#define DEBUGRENDERER_H

#include "OGLFuncs.h"
#include <GL/glu.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

class DebugRenderer {
private:
  GLfloat axisVertices[18] = {
      -100.f, 0.f,    0.f,    // X-axis start
      100.f,  0.f,    0.f,    // X-axis end
      0.f,    -100.f, 0.f,    // Y-axis start
      0.f,    100.f,  0.f,    // Y-axis end
      0.f,    0.f,    -100.f, // Z-axis start
      0.f,    0.f,    100.f   // Z-axis end
  };

  GLubyte axisIndices[6] = {
      0, 1, //
      2, 3, //
      4, 5  //
  };

  bool active = false;

public:
  void drawAxis();
  void toggle();
  DebugRenderer();
  ~DebugRenderer();
};

#endif
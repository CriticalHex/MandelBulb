#ifndef CUBE_H
#define CUBE_H

#include "OGLFuncs.h"
#include <GL/glu.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

class Cube {
private:
  GLfloat vertices[24] = {
      -50.f, -50.f, -50.f, // x,y,z point
      -50.f, 50.f,  -50.f, //
      50.f,  50.f,  -50.f, //
      50.f,  -50.f, -50.f, //
      -50.f, -50.f, 50.f,  //
      -50.f, 50.f,  50.f,  //
      50.f,  50.f,  50.f,  //
      50.f,  -50.f, 50.f,  //
  };

  // Define the indices for the cube's triangles
  GLubyte indices[24] = {
      0, 1, 2, 3, // indexes of vertices
      3, 2, 6, 7, //
      7, 6, 5, 4, //
      4, 5, 1, 0, //
      1, 5, 6, 2, //
      4, 0, 3, 7, //
  };

  // Define the indices for the cube's edges
  GLubyte edgeIndices[24] = {
      0, 1, 1, 2, 2, 3, 3, 0, // Front face
      4, 5, 5, 6, 6, 7, 7, 4, // Back face
      0, 4, 1, 5, 2, 6, 3, 7  // Connect front and back faces
  };

public:
  Cube();
  void draw();
  ~Cube();
};

// Define the vertices of the cube

#endif
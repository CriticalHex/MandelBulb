#include "Cube.h"

Cube::Cube() {}

Cube::~Cube() {}

void Cube::draw() {
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, vertices);

  // Draw the faces of the cube
  // glColor3f(1.0f, 0.5f, 0.0f);
  // glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, indices);

  // Draw the edges of the cube
  glColorSF(sf::Color::White);               // Set color
  glLineWidth(2.5f);                         // Set line width
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Draw only the edges
  glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, indices);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // Restore default polygon mode

  glDisableClientState(GL_VERTEX_ARRAY);
}
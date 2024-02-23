#include "DebugRenderer.h"

DebugRenderer::DebugRenderer() {}

DebugRenderer::~DebugRenderer() {}

void DebugRenderer::drawAxis() {
  if (active) {
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, axisVertices);

    glColorSF(sf::Color::Red);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, axisIndices); // X axis
    glColorSF(sf::Color::Blue);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, axisIndices + 2); // Y axis
    glColorSF(sf::Color::Green);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, axisIndices + 4); // Z axis

    glDisableClientState(GL_VERTEX_ARRAY);
  }
}

void DebugRenderer::toggle() { active = !active; }
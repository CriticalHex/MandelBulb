#include "Cube.h"
#include "DebugRenderer.h"
#include "Mandelbulb.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 800), "SFML 3D Cube");
  window.setFramerateLimit(60);

  // Enable Z-buffer read and write
  glEnable(GL_DEPTH);
  glDepthMask(GL_TRUE);
  glClearDepth(1.f);

  // Set up a basic perspective projection
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(90.f, 1.f, 1.f, 300.0f);

  // Set up the position of the camera
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(100, 100, 100, 0, 0, 0, 0, 1, 0);

  Cube cube;
  DebugRenderer dr;

  // Start the game loop
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::KeyPressed) {
        switch (int(event.key.code)) {
        case sf::Keyboard::Q: {
          window.close();
          break;
        }
        case sf::Keyboard::X: {
          dr.toggle();
          break;
        }
        case sf::Keyboard::W: {
          glRotatef(0.5f, 0.f, 1.f, 0.f);
          break;
        }
        case sf::Keyboard::A: {
          glRotatef(0.5f, 1.f, 0.f, 0.f);
          break;
        }
        case sf::Keyboard::S: {
          glRotatef(-0.5f, 0.f, 1.f, 0.f);
          break;
        }
        case sf::Keyboard::D: {
          glRotatef(-0.5f, 1.f, 0.f, 0.f);
          break;
        }
        }
      }
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    dr.drawAxis();
    cube.draw();

    window.display();
  }

  return 0;
}

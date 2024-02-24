#include "Cube.h"
#include "DebugRenderer.h"
#include "Mandelbulb.h"
#include <iostream>

int main() {
  sf::RenderWindow window(sf::VideoMode(1920 * 3, 1080), "Mandelbulb",
                          sf::Style::None);
  window.setVerticalSyncEnabled(true);

  // Enable Z-buffer read and write
  glEnable(GL_DEPTH);
  glDepthMask(GL_TRUE);
  glClearDepth(1.f);

  // Set up a basic perspective projection
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(90.f, 16 * .33f, 1.f, 300.0f);

  sf::Vector3f cameraPos(2.5, 2.5, 2.5);
  // Set up the position of the camera
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(cameraPos.x, cameraPos.y, cameraPos.z, 0, 0, 0, 0, 1, 0);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  Cube cube;
  DebugRenderer dr;
  Mandelbulb mand;

  for (int i = 0; i < 10; i++) {
    mand.calculate();
  }

  // Start the game loop
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed: {
        window.close();
        break;
      }
      case sf::Event::KeyPressed: {
        switch (int(event.key.code)) {
        case sf::Keyboard::LControl:
        case sf::Keyboard::Q: {
          window.close();
          break;
        }
        case sf::Keyboard::X: {
          dr.toggle();
          break;
        }
        }
        break;
      }
      case sf::Event::MouseWheelScrolled: {
        switch (event.mouseWheelScroll.delta > 0) {
        case true: { // up (in)
          if (cameraPos.x / 2 == 0) {
            break;
          }
          cameraPos =
              sf::Vector3f(cameraPos.x / 2, cameraPos.y / 2, cameraPos.z / 2);
          break;
        }
        case false: { // down (out)
          if (cameraPos.x * 2 > 100) {
            break;
          }
          cameraPos =
              sf::Vector3f(cameraPos.x * 2, cameraPos.y * 2, cameraPos.z * 2);
          break;
        }
        }
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(cameraPos.x, cameraPos.y, cameraPos.z, 0, 0, 0, 0, 1, 0);
      }
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
      glRotatef(0.5f, 0.f, 1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      glRotatef(0.5f, 1.f, 0.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      glRotatef(-0.5f, 0.f, 1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      glRotatef(-0.5f, 1.f, 0.f, 0.f);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    dr.drawAxis();
    // cube.draw();
    mand.draw();

    window.display();
  }

  return 0;
}

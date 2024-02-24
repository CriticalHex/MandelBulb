#include "Pixel.h"

Pixel::Pixel(double x, double y, double z, std::vector<GLfloat> *colors,
             UINT index) {
  this->x = x0 = x;
  this->y = y0 = y;
  this->z = z0 = z;
  this->colors = colors;
  this->index = index;
}

Pixel::~Pixel() {}

void Pixel::iterate() {
  if (!escaped) {
    r = sqrt(x * x + y * y + z * z);
    theta = acos(z / r);
    phi = atan(y / x);
    if (r >= 2) {
      escaped = true;
      (*colors)[index * 4 + 3] = 0;
      return;
    }
    x = pow(r, n) * sin(n * theta) * cos(n * phi) + x0;
    y = pow(r, n) * sin(n * theta) * sin(n * phi) + y0;
    z = pow(r, n) * cos(n * theta) + z0;
  }
}
#include "rgba_to_rgb.h"
void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  int counter = 0;
  for (int i = 0; i < rgba.size(); i++) {
      if ((i + 1) % 4 != 0) {
          rgb[counter] = rgba[i];
          counter++;
      }
  }
}

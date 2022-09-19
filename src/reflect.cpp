#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (int row = 0; row < height; row++) {
      for (int col = width - 1; col >= 0; col--) {
          if (num_channels == 1) { 
              reflected[row * width + (width - 1 - col)] = input[row * width + col];
          }
          else if (num_channels == 3) {
              reflected[row * width * 3 + 3 * (width - 1) - (3 * col)] = input[row * width * 3 + col * 3];
              reflected[row * width * 3 + 3 * (width - 1) - (3 * col) + 1] = input[row * width * 3 + col * 3 + 1];
              reflected[row * width * 3 + 3 * (width - 1) - (3 * col) + 2] = input[row * width * 3 + col * 3 + 2];
          }
      }
  }
}

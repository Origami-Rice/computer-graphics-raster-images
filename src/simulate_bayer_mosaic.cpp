#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  int grayCount = 0;
  for (int row = 0; row < height; row++) {
      for (int col = 0; col < width; col++) {
          int row_type = row % 2;
          if (row_type == 0) {
              if (col % 2 == 0) { 
                  bayer[grayCount] = rgb[row * width * 3 + col * 3 + 1];
              }
              else { 
                  bayer[grayCount] = rgb[row * width * 3 + col * 3 + 2];
              }

          }
          else {
              if (col % 2 == 0) { 
                  bayer[grayCount] = rgb[row * width * 3 + col * 3];
              }
              else { 
                  bayer[grayCount] = rgb[row * width * 3 + col * 3 + 1];
              }
          }
          grayCount++;
      }
  }
}

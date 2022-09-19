#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  double alpha1 = 0;
  double alpha2 = 0;

  for (int i = 0; i < A.size(); i++) {
      if (i % 4 == 0) {
          alpha1 = A[i + 3] / 255.0;
          alpha2 = B[i + 3] / 255.0;
          C[i + 3] = (unsigned char)((alpha1 + alpha2 * (1 - alpha1)) * 255); 
      }
      if (i + 1 % 4 != 0) { 
          C[i] = (unsigned char)((double)A[i] * alpha1 + (double)B[i] * alpha2 * (1 - alpha1));
      }
  }
}

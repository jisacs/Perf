#ifndef IMAGE__HH
#define IMAGE__HH

#include <stddef.h>

class Image{
public:
  Image(int nbpixel);
  ~Image();
  double sum();
  double unloop2Sum();
  double unloop4Sum();
  void infos();
  float *pe;
  int nbPixel;
};


#endif

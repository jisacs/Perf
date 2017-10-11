#ifndef IMAGE_LIST__HH
#define IMAGE_LIST__HH

#include <stddef.h>
#include <list>
#include <vector>


class ImageList{
public:
  ImageList(int nbpixel);
  ~ImageList();
  double listSum();
  double vectorSum();
  std::list<float> peList;
  std::vector<float> peVector;
};


#endif

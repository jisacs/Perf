#include "imageList.h"
#include <ctime>
#include <cstdlib>

ImageList::ImageList(int _nbPixel){
  srand(time(0));
  double i = 0, d = 0;
  for (size_t j(0); j < _nbPixel; ++j){
    i = rand() % 40 - 20; //Gives a number between -20 and +20;
    this->peList.push_back(i / 100); //Reduces this number to the range you want.
    this->peVector.push_back(i / 100);
  }
}

ImageList::~ImageList()
{

}

double ImageList::listSum(){
  double result=0.;
  for(std::list<float>::iterator it = peList.begin(); it != peList.end(); ++it) {
	  result+=*it;
  }
  return result;
}

double ImageList::vectorSum(){
  double result=0.;
  for(std::vector<float>::iterator it = peVector.begin(); it != peVector.end(); ++it) {
	  result+=*it;
  }
  return result;
}

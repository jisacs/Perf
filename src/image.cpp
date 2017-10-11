#include "image.h"
#include <ctime>
#include <cstdlib>
#include <iostream>


Image::Image(int _nbPixel){
 // pe = (float*)malloc(sizeof(float) * nbpixel);
  this->nbPixel=_nbPixel;
  pe = new float[nbPixel]();
  srand(time(0));
  double i = 0, d = 0;
  for (size_t j(0); j < this->nbPixel; ++j){
    i = rand() % 40 - 20; //Gives a number between -20 and +20;
    this->pe[j] = i / 100; //Reduces this number to the range you want.
  }
}

Image::~Image()
{
  delete[] pe;
}

double Image::sum(){
  double result=0.;
  for (size_t i(0); i < this->nbPixel; ++i){
	  result+=this->pe[i];
  }
  return result;
}

void Image::infos(){
    float * address = &(this->pe[0]);
    std::cout << "address: " << (void *)address  << std::endl;//" . %16:"<<  (void *)(address/16)
    //<< " . %32:" <<  (void *)(address/32) <<std::endl;
}

double Image::unloop2Sum(){
  double result=0.;
  double result1=0.;
  double result2=0.;

  for (size_t i(0); i < this->nbPixel; i=i+2){
	  result1+=this->pe[i];
    result2+=this->pe[i+2];
  }
  return result = result1 + result2;
}


double Image::unloop4Sum(){
  double result=0.;
  double result1=0.;
  double result2=0.;
  double result3=0.;
  double result4=0.;
  for (size_t i(0); i < this->nbPixel; i=i+4){
	  result1+=this->pe[i];
    result2+=this->pe[i+2];
    result2+=this->pe[i+3];
    result2+=this->pe[i+4];
  }
  return result = result1 + result2 + result3 + result4;
}

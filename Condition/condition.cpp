#include "condition.h"
//#include <cmath>
#include <iostream>


float Condition::compute_if(unsigned int nbloop){
  float result = 0;
  for (unsigned int i(0); i < nbloop; ++i){
    if (i < 100){
      result += i;
    }
  }
  return result;
}



float Condition::compute_math(unsigned int nbloop){

  float result = 0;
  float x=0;
  for (unsigned int i(0); i < nbloop; ++i){
    x =  float(i/100)+1;
    result += x;
  }
  return result;
}

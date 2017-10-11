#include "image.h"
#include "imageList.h"
#include <iostream>



using namespace std;
uint64_t rdtsc();

int main(int argc, char** argv){
int nbPixel = 10;
int nbLoop = 100000;
// Get user input
// 1 -> nbPixel

if (argc >= 2) {
	 nbPixel = atoi(argv[1]);
 	 cout << "nbPixel=" << nbPixel << endl;
}
// 2-> nbLoop
if (argc == 3) { nbLoop = atoi(argv[2]);}

//  create float array based image
Image image(nbPixel);
image.infos();
// Compute cpu_clycle
uint64_t start = rdtsc();
for (size_t i(0); i < nbLoop; ++i){
	image.sum();
}

cout << endl << endl <<endl <<endl <<endl <<endl <<endl;
// Print result
float nb_cycle = float(rdtsc()-start)/(nbLoop*image.nbPixel);
cout << "===============================================================================" << endl;
cout << "Float array RESULT cpu cycle:=" << nb_cycle<< " cycles/elem." << endl;
cout << "===============================================================================" << endl;
cout << endl;

start = rdtsc();
for (size_t i(0); i < nbLoop; ++i){
	image.unloop2Sum();
}
// Print result
nb_cycle = float(rdtsc()-start)/(nbLoop*image.nbPixel);
cout << "===============================================================================" << endl;
cout << "Float array unloop 2  RESULT cpu cycle:=" << nb_cycle<< " cycles/elem." << endl;
cout << "===============================================================================" << endl;

cout << endl;

start = rdtsc();
for (size_t i(0); i < nbLoop; ++i){
	image.unloop4Sum();
}
// Print result
nb_cycle = float(rdtsc()-start)/(nbLoop*image.nbPixel);
cout << "===============================================================================" << endl;
cout << "Float array unloop 4  RESULT cpu cycle:=" << nb_cycle<< " cycles/elem. " << endl;
cout << "===============================================================================" << endl;

cout << endl  << endl  << endl  << endl;





//  createstd::list based image
ImageList imageList(nbPixel);
// Compute cpu_clycle
start = rdtsc();
for (size_t i(0); i < nbLoop; ++i){
	imageList.listSum() ;
}
// Print result
nb_cycle = float(rdtsc()-start)/(nbLoop*imageList.peList.size());
cout << "===============================================================================" << endl;
cout << "std::list  RESULT cpu cycle:=" << nb_cycle<< " cycles/elem." << endl;
cout << "===============================================================================" << endl;

// Compute cpu_clycle
start = rdtsc();
for (size_t i(0); i < nbLoop; ++i){
	imageList.vectorSum() ;
}
// Print result
nb_cycle = float(rdtsc()-start)/(nbLoop*imageList.peVector.size());
cout << "===============================================================================" << endl;
cout << "std::vector  RESULT cpu cycle:=" << nb_cycle<< " cycles/elem." << endl;
cout << "===============================================================================" << endl;


image.infos();

return 0;
}

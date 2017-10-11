#include "condition.h"
#include <iostream>

using namespace std;
uint64_t rdtsc();

int main(int argc, char** argv){
	int nbloop = 10;
	// Get user input
	// 1 -> nbloop

	if (argc >= 2) {
		 nbloop = atoi(argv[1]);
	 	 cout << "nbloop=" << nbloop << endl;
	}

Condition cond;

uint64_t start = rdtsc();
cond.compute_if(nbloop);
float nb_cycle = float(rdtsc()-start)/(nbloop);
cout << "===============================================================================" << endl;
cout << "compute with if RESULT cpu cycle:=" << nb_cycle<< " cycles/elem." << endl;
cout << "===============================================================================" << endl;

start = rdtsc();
cond.compute_math(nbloop);
nb_cycle = float(rdtsc()-start)/(nbloop);
cout << "===============================================================================" << endl;
cout << "compute with math RESULT cpu cycle:=" << nb_cycle<< " cycles/elem." << endl;
cout << "===============================================================================" << endl;



return 0;
}

#include <vector>
#include <iostream>
#include <time.h>
using namespace std;

//implement of algorithm
void myalgorithm() 
{
	
}

int main()
{	
	//variables use to compute the time of algorithm spend
	struct timespec tpstart;
    struct timespec tpend;	
    ////
    
    //data and variables input to algorithm
    
    ////
    
    //run myalgorithm() and compute the time of that spend
    clock_gettime(CLOCK_REALTIME, &tpstart);
    
    myalgorithm(); //run myalgorithm() 
    
    clock_gettime(CLOCK_REALTIME, &tpend);
    ////
    
    //display the results
    double timedif = (tpend.tv_sec-tpstart.tv_sec)+(tpend.tv_nsec-tpstart.tv_nsec)/1000000000.0;
    printf("clock_gettime time: %.12f\n", timedif);
			
	////
}



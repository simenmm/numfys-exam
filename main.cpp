#include <iostream>
#include <random>
#include <time.h>
#include <vector>

using namespace std;
 
int main(){
  int maxSteps = 1000;
  int noWalks = 10;
  int noCombs = 20000;

  vector<int> comb;
  vector<double> distances(maxSteps,0);
  int xPos, yPos = 0;

  int length = maxSteps*2;
  int starting = length/2;

  srand(time(NULL));
  //Print line numbers to appease Gnuplot
  for (int i = 1; i < 1001; i++){
    cout << i << ' ';
  }

  //Cycle through gammas
  for (double gamma = 0.1; gamma < 5; gamma *= 1.03){
    double totWalked = 0;

    //Generating Comb
    for (int combNo = 0; combNo < noCombs; combNo++){
      comb.clear();
      for (int i = 0; i < length; i++){
	comb.push_back (pow((float)rand()/(float)RAND_MAX, -1/gamma) - 1);
      }

      for (int walkNo = 0; walkNo < noWalks; walkNo++){  
	//Initializing walk
	xPos = starting;
	yPos = 0;
	//Single steps
	for (int step = 0; step < maxSteps; step++){
	  if (yPos){
	    if (yPos == comb [xPos]){
	      yPos--;
	    }else{
	      yPos += (rand()%2 - 0.5) * 2;
	    }
	  }else{
	    if (comb [yPos]){
	      if (not (rand()%3)){
		yPos++;
	      }else{
		xPos += (rand()%2 - 0.5) * 2; 
	      }
	    }else{
	      xPos += (rand()%2 - 0.5) * 2; 
	    }
	  }
	  //Add up the square of distances moved for each step
	  distances[step] += pow(xPos - starting,2);             
	}
      }
    }
    //Print the RMS distances by step before next gamma
    for (int i = 0; i < 1000; i++){
      cout << pow(distances[i]/(noCombs*noWalks),0.5) << ' ';
      distances[i] = 0;
    }
    cout << endl;
  }
  return 0;
}


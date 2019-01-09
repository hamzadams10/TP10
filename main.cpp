#include <stdlib.h>     
#include "Chaleur.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

int main(int argc, char * argv[])
//int main()
{
   if (argc < 4)
   {
     cerr << "usage "  <<argv[0] << " Nx Ny  maxIt prec" << endl;
     return -1;
   }
 
 int Nx =  atoi(argv[1]);
 int Ny = atoi(argv[2]);
   double hx = 1. / Nx;
   double hy = 1. / Ny;
   double dt = min ( hx * hx / 4., hy * hy / 4.);
   int maxIt = atoi(argv[3]);
   double eps = atof(argv[4]);
   
  Chaleur poeleACharbon(hx, hy, Nx+2 , Ny + 2, dt);
 poeleACharbon.initialise(1.0);
 //poeleACharbon.resout(maxIt, eps);

    double * b;
    double * res;
 
    b = new double[(Nx +2) *(Ny+2) ];
    poeleACharbon.copiesolN( b); 
 
   res = new double[(Nx +2) *(Ny+2) ];
  
 poeleACharbon.mult_laplace(b,Nx+2,Ny+2,res );

  delete [] b;
  delete [] res;
   return 0;
}

#include <stdlib.h>     
#include "Chaleur.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

//constructeur
Chaleur::Chaleur(double deltaX, double deltaY, int dimX, int dimY, double dt):
     _deltaX(deltaX),
     _deltaY(deltaY),
     _dimX(dimX),
     _dimY(dimY),
     _dt(dt)
{
   _solN = new double[dimX * dimY];
   _solNp1 = new double[dimX * dimY];
   for (int i = 0; i < dimX * dimY ;++i)
   {
     _solN[i] = _solNp1[i] = 0.;
   }
}

void Chaleur::initialise(double valeurSurLeBord)
{
 
 for(int i = 0; i < _dimX; ++i)
  {
    _solN[i * _dimY + 0] = valeurSurLeBord;
    _solN[i * _dimY + _dimY -1 ] = valeurSurLeBord;
  }

 for(int j = 0; j < _dimY; ++j)
  {
    _solN[0 * _dimY + j] = valeurSurLeBord;
    _solN[(_dimX - 1) * _dimY + j] = valeurSurLeBord;
  }
}

// destructeur
Chaleur::~Chaleur()
{
  delete [] _solN;
  delete [] _solNp1;
}

void Chaleur::sauveSolution(string nomFichier)
{
  ofstream file;
  file.open(nomFichier, ios::out);

  file << "# vtk DataFile Version 3.0" << endl;
  file << "cell" << endl;
  file << "ASCII" << endl;
  file << "DATASET STRUCTURED_POINTS" << endl;
  file << "DIMENSIONS " << _dimX << " " << _dimY << " " << 1 << endl;
  file << "ORIGIN " << 0 << " " << 0 << " " << 0 << endl;
  file << "SPACING " << 1.0 << " " << 1.0 << " " << 1 << endl;;
  file << "POINT_DATA " << _dimX*_dimY << endl;
  file << "SCALARS cell float" << endl;
  file << "LOOKUP_TABLE default" << endl;

  for(int i=0; i < _dimX; i++) {
		for(int j=0; j < _dimY; j++) {
			file << _solN[i * _dimY + j] << " ";
		}
	}
	file << endl;
	file.close();
}

double Chaleur::itere()
{

    double w_x = _dt / (_deltaX * _deltaX);
    double w_y = _dt / (_deltaY * _deltaY);
    // facteur diagonal
    double d = 1. - 2. * w_x - 2. * w_y; 

    double err = 0.;
  
 for (int j = 1; j < _dimY - 1; ++j)

    {
    
  for (int i = 1; i < _dimX - 1; ++i)
        {
            _solNp1[i * _dimY + j] = d * _solN[ i * _dimY + j]  + w_x * (_solN[(i - 1) * _dimY + j] + _solN[(i + 1) * _dimY + j]) 
                + w_y * (_solN[i * _dimY + j - 1]   + _solN[i * _dimY + j + 1]); 
            err += sqrt (_solNp1[i * _dimY + j] - _solN[i * _dimY + j]);
        }
    }
    return sqrt(err);
}

int Chaleur::resout(int maxIt, double eps)
{
  int iter = 0;
  double err = 100;
  cout << "maxIt " << maxIt << endl;
  cout << "eps = " << eps  << endl;
  while ((iter < maxIt) && (err > eps))
    {
      err = itere();
   
      string nomFichier = "chaleur_" + to_string(iter) + ".vtk";
      if (iter % 10 ==0) sauveSolution(nomFichier);
      cout << " iter = " << iter << " err = " << err << endl;
      iter++;
   
      for(int i = 1; i < _dimX - 1; ++i) {
        for (int j = 1; j < _dimY - 1; ++j) {
	  _solN[i * _dimY + j] = _solNp1[ i * _dimY + j];
	}
      } 
    }
  return iter;
}

void Chaleur::copiesolN(double * b) {


  for(int i = 0; i < _dimX ; ++i) {
    for (int j = 0; j < _dimY ; ++j) {
      b[i * _dimY + j] = _solN[ i * _dimY + j];
    }
  }

};


void Chaleur::mult_laplace(double * vec, int dimX, int dimY, double * res )
 { 
   double dx = _deltaX;
   double dy = _deltaY;

   double w_x =  _dt / ( dx*dx);
   double w_y = _dt / (dy*dy);
   double d = 1. + 2. * w_x + 2. * w_y; 

   for(int i = 1; i < dimX - 1; ++i) {
     for (int j = 1; j < dimY - 1; ++j) {
       res[i * dimY + j] =  d *vec[ i * dimY + j]  - w_x * (vec[(i - 1) * dimY + j] + vec[(i + 1) * dimY + j]) 
   	 - w_y * (vec[i * dimY + j - 1]   + vec[i * dimY + j + 1]);
     }
   }
 
   for(int i = 0; i < dimX; ++i)
     {
       res[i * dimY + 0] = 1.;
       res[i * dimY + dimY -1 ] =  1.;
     }

   for(int j = 0; j < dimY; ++j)
     {
       res[0 * dimY + j] =  1.;
       res[(dimX - 1) * dimY + j] =  1.;
     }

 }

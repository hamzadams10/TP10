#include <string>
#include <iostream>
#include <stdlib.h> 

using namespace std;
class Chaleur {
public:
    Chaleur(double deltaX, double deltaY, int dimX, int dim, double dt);
    ~Chaleur();
    int resout(int maxIt, double eps);
    void initialise(double valSurLeBord);
  //sauve la solution dans un fichier paraview
    void sauveSolution(string nomFichier);
    
 // multiplie un vecteur 2D par la matrice du Laplacien en 2D
 void mult_laplace(double * vec,  int dimX, int dimY, double * res );

    // calcul X_{n+1} en fonction de X_n
    double itere();

  //  copie _solN dans un vecteur
  void copiesolN(double * b);
    

private:
    double _deltaX;
    double _deltaY;
    int _dimX;
    int _dimY;
 double _dt;

    // X_n
    double * _solN;
    // X_{n+1}
    double * _solNp1;

};

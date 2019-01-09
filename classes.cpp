#include "fonctions.h"



int main (){ 
  point A; 
  double vx=3.; 
  double vy=4.5;
 
  
  A.get_x() = 1.; 
  A.get_y() = 1.; 

  A.affiche();

  point* p; //pointeur p qui pointe vers l'adresse mémoire de A
  p=A.adresse();
  cout << "adresse instance " << p << endl;

  point Aprime=A.translation(vx,vy); //Aprime est le point A après translation
  Aprime.affiche();

  point Ater= addition(A,Aprime); //Aprime est le point A après translation
  Ater.affiche();

  return 0;

}

#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
using namespace std;
 
class point{ 

public: 
  double & get_x() {return x;}; //on passe par la référence pour pouvoir modifier les valeurs privées
  
  double & get_y() {return y;};
   
  void affiche(){cout<<x<<"  " <<y<<endl;};
  
  point translation (double vx, double vy);
  point* adresse(){return this;} //this renvoie un pointeur vers la place mémoire associée à x et y

  friend point addition (point A, point B);
private:
  double x;
  double y;
};


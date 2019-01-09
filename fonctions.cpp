#include "fonctions.h"

 

point point :: translation (double vx, double vy)
  {
  point B;
  B.x=x+vx; //on translate x de vx
  B.y=y+vy;
  return B;
  };


point  addition (point A,point B){
point C;
C.x = A.x+B.x;
 C.y = A.y+B.y;
  return C;
}; 

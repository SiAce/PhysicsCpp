#include "Lorentz_vector4D.h"

#include <iostream>
#include <cmath>

using namespace std;

int main () {
  using LV4D = Lorentz_vector4D;

  double len_v1_square,len_v2_square,distance_square;
  LV4D v1,v2;
  v1.x = 1,v1.y = 1,v1.z = 1,v1.t = 0,v2.x = 9,v2.y = 1,v2.z = 1,v2.t = 10;
  len_v1_square = v1.x*v1.x + v1.y*v1.y + v1.z*v1.z - v1.t*v1.t;
  len_v2_square = v2.x*v2.x + v2.y*v2.y + v2.z*v2.z - v2.t*v2.t;
  distance_square = (v1.x-v2.x)*(v1.x-v2.x) + (v1.y-v2.y)*(v1.y-v2.y) + (v1.z-v2.z)*(v1.z-v2.z) - (v1.t-v2.t)*(v1.t-v2.t);
  if (len_v1_square>=0)
    cout << "The length of v1 is " << sqrt(len_v1_square) << endl;
  else
    cout << "The length of v1 is " << sqrt(fabs(len_v1_square)) << "i" << endl;
  if (len_v2_square>=0)
    cout << "The length of v2 is " << sqrt(len_v2_square) << endl;
  else
    cout << "The length of v2 is " << sqrt(fabs(len_v2_square)) << "i" << endl;
  if (distance_square>=0)
    cout << "The distance between v1 and v2 is " << sqrt(distance_square) << endl;
  else
    cout << "The distance between v1 and v2 is " << sqrt(fabs(distance_square)) << "i" << endl;
  return 0;
}
  

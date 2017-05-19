#include "lorentz_vector.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  Vector3D vector_3d(5, 6 ,7);
  LorentzVector lv1(1, -2, -3, -4);
  LorentzVector lv2 = lv1.Boost(5, 6 ,7, 0.5);
  LorentzVector lv3 = lv1.Boost(vector_3d, 0.5);
  LorentzVector lv4 = lv3.Boost(vector_3d.Scale(-1), 0.5);
  
  cout << lv1.GetX0() << " " << lv1.GetX1()
       << " " << lv1.GetX2() << " " << lv1.GetX3() << endl;
  cout << lv2.GetX0() << " " << lv2.GetX1()
       << " " << lv2.GetX2() << " " << lv2.GetX3() << endl;
  cout << lv3.GetX0() << " " << lv3.GetX1()
       << " " << lv3.GetX2() << " " << lv3.GetX3() << endl;
  cout << lv4.GetX0() << " " << lv4.GetX1()
       << " " << lv4.GetX2() << " " << lv4.GetX3() << endl;
  
  return 0;
}

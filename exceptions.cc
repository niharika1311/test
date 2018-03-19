#include<iostream>

using namespace std;

void function(int a) {
  if(a < 0)
    throw -1;
  else
    cout << a << endl;
}

int main() {
//  try {
    function(-10);
//  }
 // catch(int x) {
  //  std::cerr << "caught an exception " << x << endl;
  //}
  return 0;
}

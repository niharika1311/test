#include<iostream>

using namespace std;

int main() {
  int x = 10;
  int &&ref_rv = 20;
  cout << ref_rv << endl;
  ref_rv = 10;
  cout << ref_rv << endl;
  return 0;
}

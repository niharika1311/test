#include<iostream>

using namespace std;

class A {
  public:
  void function1(void)  = delete;
  void function2(void) {
    cout << "function2" << endl;
    function1();
  }
};
void A::function1() 
  {
    cout << "function1" << endl;
  }
int main() {
  A obj;
  obj.function2();
  return 0;
}

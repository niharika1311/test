#include<iostream>

using namespace std;

class A {
  public:
  virtual void f1(float) = 0;
};

class B : public A {
  public:
  virtual void f1(float)  override;
};

void B::f1(float) {
  cout << "B::f1" << endl;
}

int main() {
  B obj;
  obj.f1(2);
}

#include<iostream>

using namespace std;

class A {
  public:
  virtual void getName() {
    cout << "Name is A" << endl;
  }

  virtual A* getThis() { return this; }
};

class B : public A {
  public:
  virtual void getName() override {
    cout << "Name is B" << endl;
  }
  virtual B* getThis() override { return this; }
};

int main() {
  A a_obj;
  B b_obj;
  A &ptr = b_obj;
  ptr.getName();
  ptr.getThis();
  return 0;
}

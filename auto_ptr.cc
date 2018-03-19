#include<iostream>

using namespace std;

template<class T>
class AutoPtr {
  T* m_ptr;
  public:
  AutoPtr(T *ptr = nullptr):m_ptr(ptr) {}
  ~AutoPtr() { delete m_ptr; }
  T& operator*() const { return *m_ptr; }
  T* operator->() const { return m_ptr; }
  AutoPtr(AutoPtr &ptr) {
    m_ptr = ptr.m_ptr;
    ptr.m_ptr = nullptr;
  }
  AutoPtr& operator=(AutoPtr& obj) {
    if(&obj == this)
      return *this;
  delete m_ptr;
  m_ptr = obj.m_ptr;
  obj.m_ptr = nullptr;
  return *this;
  }
};

class Test {
  public:
  Test() { cout << "Test constructor \n"; }
  ~Test() { cout << "Test destructor \n"; }
};

int main() {
  AutoPtr<Test> ptr(new Test);
  AutoPtr<Test> ptr2(ptr);
  return 0;
}

#include <iostream>
class Base
{
public:
    virtual ~Base() // note: not virtual
    {
        std::cout << "Calling ~Base()" << std::endl;
    }
};
 
class Derived: public Base
{
private:
    int m_array;
 
public:
    Derived(int length)
    {
        m_array = length;
    }
 
    virtual ~Derived() // note: not virtual
    {
        std::cout << "Calling ~Derived()" << std::endl;
//        delete[] m_array;
    }
};
 
int main()
{
    Derived *derived = new Derived(5);
    Base *base = derived ;
    delete base;
 
    return 0;
}

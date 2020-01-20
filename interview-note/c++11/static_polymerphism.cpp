#include <iostream>
using namespace std;

class Base
{
public:
    virtual void method() { std::cout << "Base"; }
    virtual ~Base() {}
};

class Derived : public Base
{
public:
    virtual void method() { std::cout << "Derived\n"; }
};
//---------------------------------------------------------------

template <class derived>
struct base
{
    void f1()
    {
         static_cast<derived*>(this)->f1Impl();
    }
};

struct derived1 : base<derived1>
{
     //friend class  base<derived1>;
     void f1Impl()
     {
         std::cout << "derived1\n";
     }
};

struct derived2: base<derived2>
{
     //friend class  base<derived1>;
     void f1Impl()
     {
         std::cout << "derived2\n";
     }
};


int main()
{
    Base *pBase = new Derived;
    pBase->method(); //outputs "Derived"
    delete pBase;
     base<derived2>* b1=new derived2();
     b1->f1();
    return 0;
}

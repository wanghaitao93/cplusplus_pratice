#include <iostream>
using namespace std;


class Base
{
public:
    virtual void foo() {printf("call Base::foo().\n");}
    void bar() {printf("call Base::bar().\n"); foo();}
};

class Dirive: public Base 
{
public:
    void foo() {printf("call Dirive::foo().\n");}
    void bar() {printf("call Dirive::bar().\n"); foo();}
};


int main()
{
    // 有virtual修饰的看对象，其余看指针。
    Base *ptr = new Dirive();
    ptr->bar();
   // call Base::bar().
   // call Dirive::foo().
    Dirive *ptr1 = (Dirive*)new Base();
    ptr1->bar();
   // call Dirive::bar().
   // call Base::foo().
    return 0;
}

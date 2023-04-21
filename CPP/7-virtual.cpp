#include <iostream>
using namespace std;

class Base{
public:
    Base(): data(10){}
    void foo() {cout << "Base::foo():data = " << data << endl;}
    virtual void bar0() {cout << "bar0" << endl;}               // 虚表，在Derived里被复写了
    virtual void bar1() {cout << "bar1" << endl;}
private:
    int data;
};

class Derived: public Base{
public:
    void bar0() override {cout << "Derived::bar0()" << endl;}
    void bar1() override {cout << "Derived::bar1()" << endl;}
};

int main()
{
    Base b2;
    void *vptr = *((void**)&b2);
    cout << "vptr: " << vptr << endl;

    Derived d;
    void *vptrd = *((void**)&d);
    cout << "vptrd: " << vptrd << endl;


    void* *vfuncs = (void* *)vptr;
    void* f0 = (void*)vfuncs[0];
    cout << "f0: " << f0 << endl;
    void* f1 = (void*)vfuncs[1];
    cout << "f1: " << f1 << endl;

    void* *vfuncsd = (void* *)vptrd;
    void *f0d = (void*)vfuncsd[0];
    cout << "f0d: " << f0d << endl;
    void *f1d = (void*)vfuncsd[1];
    cout << "f1d: " << f1d << endl;

    cout << "f0 == f0d: " << (f0 == f0d? "True": "False") << endl;
    cout << "f1 == f1d: " << (f1 == f1d? "True": "False") << endl;

}
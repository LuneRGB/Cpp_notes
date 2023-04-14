#include <ios>
#include <iostream>
using namespace std;

class Base{
public:
    Base(): data(10) {cout << "Base: Base()" << endl; }
    ~Base() {cout << "Base::~Base()" << endl; }
    void print() {cout << "Base::print():" << data << endl; }
protected:
    void setdata(int i) {data = i;}
private:
    int data;
};

class Derived: public Base{
public:
    void foo() {setdata(10); data *= 2; print(); }  // data是private，不能访问
private:
    int data;
};

struct A{
    int x, y, z;
};

struct B{
    A a;
};

struct C: public A{
};

int main()
{
    B b;
    b.a.x;      // 组合
    
    C c;
    c.x;        // 继承
}
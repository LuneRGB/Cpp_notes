#include <iostream>
using namespace std;

class Base{
public:
    Base(): data(10) {}
    virtual void bar(){
        cout << "Base::bar() : data = " << data << endl;
    }
protected:
    int data;
};

class Derived: public Base{
public:
    Derived(): datad(100) {}
    void bar() override {
        cout << "Base::bar() : data = " << datad << endl;
    }
private:
    int datad;
    int d;
};

int main()
{
    Base b;
    b.bar();

    Derived d;
    Base *p = &d;
    p->bar();

    b = d;      // data copy过去了, 虚函数指到了d的虚函数表，调用d的时候，由于b中没有这块内存，所以指向后面的内存，值是随机值
    void *pb = (void* *)&b;
    void *pd = (void* *)&d;
    *pb = *pd;

    b.bar();
    p = &b;


    b.bar();
    p = &b;
    p->bar();
}
#include <iostream>
using namespace std;

class Base{
public:
    Base(int i): data(i) {cout << "Base: Base()" << endl; }
    ~Base() {cout << "Base::~Base()" << endl; }
    void foo(Base *other){cout << "Base::foo(), other->data = " << other->data << endl;}
private:
    int data;
};

int main()
{
    Base b1(11), b2(33);
    b1.foo(&b2);            // 私有成员对象是针对整个类而言的
}
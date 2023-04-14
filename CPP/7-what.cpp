#include<iostream>
using namespace std;

class Base{
public:
    int data;
    Base() : data(10){}
};


class Derived: public Base{
private:
    int i;
public:
    Derived(): i(30){}
    void printi() {cout << "Derived::i = " << i;}
};

int main()
{
    Base b;
    Derived d;
    cout << b.data << ", " << sizeof(b) << endl;
    cout << d.data << ", " << sizeof(d) << endl;
    int *p = (int*)&b;
    cout << *p << ", " << p << endl;
    int *q = (int*)&d;
    cout << *q << ", " << q << endl;
    *p = 200;               // 修改了b.data
    cout << *p << ", " << p << endl;
    cout << b.data << ", " << sizeof(b) << endl;
    d.printi();
    q++;                    // p指向下一个
    cout << q << ", " << *q << endl;          // p这里直接访问了i
    *q = 50;
    d.printi();             // 能够改掉私有成员的值
}
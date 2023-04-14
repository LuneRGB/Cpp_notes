#include <iostream>
using namespace std;

class Base{
public:
    Base(int i): data(i) {cout << "Base: Base()" << endl; }
    ~Base() {cout << "Base::~Base()" << endl; }
    void print(int data) {cout << "Base::print():" << data << endl; }
protected:
    void setdata(int i) {data = i;}
private:
    int data;
};

// inheritance
class Derived: public Base{
public: 
    Derived(): name("zju"), address("hangzhou"), Base(10){
        cout << "Derived::Derived()" << endl;
    }
    ~Derived(){
        cout << "Derived::~Derived()" << endl;
    }
    void foo() {setdata(30); print(); }  // data是private，不能访问
    void print(){
        cout << "Derived::print(): ";    // 会先调用派生类的print再调用基类的print
        Base::print(1000);
    }
private:  // composition
    string name;
    string address;
};

int main()
{
    Derived d;
    // d.print(1000);                    // 还是会调用派生类的，name hiding，基类里的所有同名函数都不能直接访问
    d.Base::print(1000);                 // 这样写是对的
    d.foo();
}
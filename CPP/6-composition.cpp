#include <iostream>
using namespace std;

class Base{
public:
    Base(int i): data(i) {cout << "Base: Base()" << endl; }
    ~Base() {cout << "Base::~Base()" << endl; }
    void print() {cout << "Base::print():" << data << endl; }
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
private:  // composition
    string name;
    string address;
};

int main()
{
    Derived d;
    d.print();
    d.foo();
}
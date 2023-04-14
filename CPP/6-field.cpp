#include <iostream>
using namespace std;

struct A{
    int i;
    double d;
    void foo(){   // = foo(A *this)
        cout << "this = " << this << endl;
        cout << "&i = " << &this->i << endl;
        cout << "&d = " << &this->d << endl;
    }
};

int main(){
    A a1;
    A a2;
    cout << "&a1 = " << &a1 << endl;
    a1.foo();
    cout << "&a2 = " << &a2 << endl;
    a2.foo();
}
#include <iostream>
using namespace std;

class A{

    virtual void f() {};
    int i;
};


int main(){

    cout << sizeof(A) << endl;
    cout << sizeof(int) << endl;

    return 0;
}
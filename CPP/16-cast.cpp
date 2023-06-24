#include <iostream>
using namespace std;


struct A{
    virtual void f() {}
};

struct B: public A{};
struct C: public A{};

int main(){

    int a;
    double d = 7.1;
    a = d;
    // 草但是我这里没有warning, 这里会直接做截断，小数点后的东西就扔掉了
    cout << a << endl;
    a = (int)d;     // c style cast
    cout << a << endl;

    // 在关键词上const和reinterpret cast分开了

   p = reinterpret_cast<double*>(&a);


}
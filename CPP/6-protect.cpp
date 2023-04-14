#include <iostream>
using namespace std;

struct A{
    const int mi;
    A(): mi(0) {     // 常量的唯一赋值机会是这里
    }
    void foo(){
        cout << "foo()\n";
    }
};  

int main(){
    const A a;      // 用的是第2个
    
}
#include <iostream>
using namespace std;

struct Y{
    int i;
    Y(int ii){
        i = ii;
        cout << "Y: Y(int)" << endl;
    }   // 赋值
    Y() {
        i = 0;
        cout << "Y: Y()" << endl;
    }   // 默认构造
};

struct X{
    Y y;
    X() {
        y = 10;   // y = Y(10), 先做了一个Y，然后赋值，不是一个真正的初始化。等于X(): y()
        cout << "X: X()" << endl;
    }
};

int main(){
    X x;
}
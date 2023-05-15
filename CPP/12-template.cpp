#include <iostream>
using namespace std;
 
template <class T> 
void my_swap(T& x, T& y){
    T tmp = x;
    x = y;
    y = tmp;
}

template <class T>
void print(T a, T b){

    cout << a << ", " << b << endl;
}

void print(float a, float b){

    cout << "print float" << endl;
}

int main(){

    // int a = 2, b = 5;

    // cout << a << "," << b << endl;
    // my_swap(a, b);

    // float fa = 3.14f, fb = 5.29f;
    // cout << a << "," << b << endl;
    // my_swap(a, b);

    // string sa = "Hello", sb = "ZJU";
    // cout << a << "," << b << endl;
    // my_swap(a, b); 

    // 显式制定参数类型
    // 如果没有传参，一定要使用template制定type
    print<double>(2, 5.3);
    print<int>(2, 5.3);

    // 重载顺序：先找严格匹配的普通函数，再找可以隐式转换的函数
    print(2.3f, 3.4f);

    

}
#include <iostream>
using namespace std;

/* 返回值不同不能做重载 */

int foo(int i){}
int foo(double d){}
int main(){

    foo(2);
    foo(2.3);

    foo('a');   // 转成比较近的类型，应该会选int
    foo(3.2f);
    foo((double)2L);    // 不知道哪个更近

}
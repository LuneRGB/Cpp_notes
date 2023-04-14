#include <iostream>
void f(int *x)
{
    (*x)++;
}

void g(int &x)
{
    x++;  // same effect as in f
}

int x;

int &h()        // 函数内有局部变量，不能把它的地址返回
{
    int q;
    // ! return q
    return x;   // safe
}

int main()
{
    int a = 0;
    f(&a);
    g(a);
    h() = 16;

}
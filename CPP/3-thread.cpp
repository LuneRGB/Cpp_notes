#include<thread>
#include<iostream>
using namespace std;

void f()
{
    int *p = new int[1000];
    p[0] = 2023;
    p[1] = 2;
    p[2] = 24;
    // ...
    cout << "in f()" << p << endl; 
}

int main()
{
    while(true)
    {
        f();
        this_thread::sleep_for(1s);     // c++20
    }
}
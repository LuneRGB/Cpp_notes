#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
using namespace std;
int globalx = 1;

int main()
{
    static int staticx = 3;
    int localx = 3;
    int *px = (int*)malloc(sizeof(int));
    // 
    cout << &globalx << endl;
    cout << &staticx << endl;
    // 
    cout << &localx << endl;
    cout << &px << endl;
    // 
    cout << px << endl;

}
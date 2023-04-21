#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int k = 0;
    double x = 1.0;
    cout << "k = " << k << ", x = " << x << endl;


    while(fabs(x * x - 2) > 1e-12 && k++ < 1)
    {
        // x = x - f(x) / f'(x);
        x = x - (x*x - 2) / (2*x);
        cout << "k = " << k << ", x = " << x << endl;
    }
}
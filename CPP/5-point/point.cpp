#include <iostream>
#include "point.h"
using namespace std;

void Point::init(int ix, int iy)    // 访问限定，变成员函数
{
    x = ix;
    y = iy;
}
void Point::move(int dx, int dy)
{
    x += dx;
    y += dy;
}
void Point::print()
{
    cout << "Point at " << x << "," << y << "\n";
}


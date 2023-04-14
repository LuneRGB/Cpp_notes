#include <iostream>
using namespace std;

// int px, py;  // 可重用性差。需要抽取一些概念，使可以重用
struct Point{
private:        //一般数据成员都是private
    int x, y;
public:         // struct默认是公开的，C++可以兼容C
    // 放进来当成员函数
    void init(int ix, int iy)
    {
        x = ix;
        y = iy;
    }
    void move(int dx, int dy)
    {
        x += dx;
        y += dy;
    }
    void print()
    {
        cout << "Point at " << x << "," << y << "\n";
    }

};

int main(){
    // px = 2, py = 3;      // 初始化，否则创建新的点的时候会重用
    Point p;
    p.init(2, 3);           // 这里也需要传指针以实现修改
    p.print();              // 函数使用者不需要关心实现

    // px += 5, py += 5;
    p.move(5, 5);
    p.print();

    return 0;
}

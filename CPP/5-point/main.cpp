#include <iostream>
#include "point.h"
#include "LineSegment.h"    // redefinition of Point

using namespace std;

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
// 每个cpp文件是独立的编译单元，如果cpp文件没有动，之前的-o是可以重用的，只是链接的时候需要重新链接

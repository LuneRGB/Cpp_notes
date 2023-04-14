#include <iostream>
using namespace std;
struct Y{
    int i;
    float f;
    Y(int a){i = a;}
    Y(){}   // default constructor, 编译器会帮我加上Y()
    // Y() = default(); 新标准可以这么写
    // 如果没有写，且调用Y y1[1]，会自己加一个
};

int main()
{
    Y y1[3] = {Y(2), Y(3), Y()};    // 如果定义了3个只初始化两个，报错。Y()调用的是默认构造函数
                                    // 根本原因在缺少特殊的constructor：default constructor
    return 0;
}
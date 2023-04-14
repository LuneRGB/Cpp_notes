#pragma once

struct Point{
private:        //一般数据成员都是private
    int x, y;
public:         // struct默认是公开的，C++可以兼容C
    // 放进来当成员函数
    void init(int ix, int iy);
    void move(int dx, int dy);
    void print();
};

// 可以看到有哪些数据和哪些操作可以做
#include <iostream>
using namespace std;

class Resource{

};

class Widget{
private:
    int i{0};
    std::string s{};
    Resource *pr{};                             // 一个resource的裸指针
public:
    Widget(const Widget &w): i(w.i), s(w.s){
        if (w.pr) pr = new Resource(*w.pr);
    }
    Widget& operator = (const Widget &w){
        // if (this == &w) return *this;        // 如果自己给自己复制，移动语义也可以handle

        Widget tmp(w);
        *this = std::move(tmp); // temporary-move idiom

        i = w.i;
        s = w.s;
        delete pr;
        pr = nullptr;       // 不希望pr是一个悬空指针，如果new不成功的话至少pr还是一个nullptr

        if (w.pr) pr = new Resource(*w.pr);     // 这里出现了异常，会发生？

        return *this;
    }

    Widget& operator = (Widget &&w) noexcept = default;    // move语义

};

int main(){

    Widget a, b;
    a = b;          // 如果a被删掉，里面的东西不应该被删掉

    return 0;
}
#include <iostream>
using namespace std;

template <class T>
class A{
public:
    A() { cout << "template T" << endl; }
};

template<>
class A<int>{        // 全特化
public:
    A() { cout << "template int" << endl; }
};

template<class T>
class A<T*>{        // 部分特化，偏特化，但是没有确定指针指向的东西是什么
public:
    A() { cout << "template *" << endl; }
};


struct Node {};

template<> 
class A<Node*>{
public:
    A() { cout << "template Node*" << endl; }

};

int main(){
    A<double> d;
    A<int> i;
    A<int*> p;
    A<Node> n;
    A<Node*> np;
}
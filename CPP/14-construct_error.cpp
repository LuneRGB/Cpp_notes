#include <iostream>
using namespace std;

// C++的思想：用栈去管堆
// RAII: resource aquisition is initialization

class T{
public:
    T(){cout << "T::T()" << endl;}
    ~T(){cout << "T::T()" << endl;}

};


class Wrapper{
private:
    int *vdata;
public:
    Wrapper(int *vdata) : vdata(vdata) {
        cout << "W::W()" << endl;
    }
    ~Wrapper() {
        delete[] vdata;
        cout << "W::~W(), vdata released!" << endl;     // throw后就析构了
    }
};

class A{
private:
    // T t;
    // int *vdata;
    // Wrapper w;
    unique_ptr<int[]> up;       // 跟wrapper是一样的，相当于把动态内存管起来
public:
    A(): up(new int[10]()){      // 这里传了一个w的构造
        cout << "A::A()" << endl;
        if (true){  // anything indicating a failure
            // throw的时候发现前面分配了一些资源
            // delete[] vdata;     // 需要去处理已分配的资源
            throw 2;        // T对它来说是一个已经构造好的东西，它的析构会得到执行
        }
    }
    ~A() {
        // delete[] vdata;
        cout << "A::~A()" << endl;
    }
};

// void f(){
//     X x;        // 如果x的构造函数抛了异常，f函数将退栈，回到main，main没有接，程序崩溃
//                 // 不会有内存泄露：栈上的东西会自己清掉
//     Y* p = new Y();      // 如果有异常，如果new不成功，内存不会被分配出来，
// }

void foo(){
    T t;            // 栈上的对象，发生异常时，析构函数是会得到执行的
    throw 1;        // 在退栈的时候会保证栈上的析构函数得到执行
}

int main(){

    try{
        // foo();
        A a;
    } catch (...){
        cout << "catched..." << endl;
    }   // 没有成功构造，就不会触发析构
    return 0;
}
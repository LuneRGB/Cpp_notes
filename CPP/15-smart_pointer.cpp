#include <iostream>
#include <memory>
using namespace std;

class A{
public:
    A(){
        cout << "A is created. " << endl;
    }
    ~A(){
        cout << "A is destroyed. " << endl;
    }

    void foo(){
        cout << "A::foo() is called. " << endl;
    }
};

int main(){

    shared_ptr<A> pa2;
    {
        // A* p = new A();
        // // ... 
        // unique_ptr<A> pa(new A());      // 拿裸指针初始化

        // unique_ptr<A> pa = make_unique<A> ();// 也可以写成
        // auto pa = make_unique<A> ();            // c++14
        auto pa = make_shared<A> ();
        cout << "count: " << pa.use_count() << endl;
        pa->foo();
        // unique_ptr<A> pa2;

        // cout << "... before move ..." << endl;
        // cout << "pa = " << pa.get() << endl;

        // // 这行的语义是什么？希望copy一遍智能指针
        // // auto p2(pa);
        // // pa2 = std::move(pa);
        // pa2 = (unique_ptr<A>&&)(pa);    // 右值引用

        // cout << "... after move ..." << endl;
        // cout << "pa = " << pa.get() << endl;
        // cout << "pa2 = " << pa.get() << endl;

        auto pa2 = pa;      // share pointer, 为什么我不行
        cout << "count: " << pa2.use_count() << endl;
    }

    cout << "before end..." << endl;
    cout << "count: " << pa2.use_count() << endl;   // 诶我这里打出来是count：0 ？
    
}
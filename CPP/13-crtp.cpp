#include<iostream>
using namespace std;

template<class T>
struct Base{

    void interface()
    {
        // 把this指针转换成了T*
        static_cast<T*> (this) ->implemenatation();
    } 
    static void static_implementation(){
        T::static_implementation;
    }
};
// 静态的多态性：没有用到虚函数，没有用虚函数表，所以开销会小一些
struct Derived1: public Base<Derived1>{

    void implementation(){
        cout << "Derived1::implementation()" << endl;
    }
    static void static_implementation(){
        cout << "Derived1::static_implementation()" << endl;
    }
};

struct Derived2: public Base<Derived2>{
    void implementation(){
        cout << "Derived2::implementation()" << endl;
    }
    static void static_implementation(){
        cout << "Derived2::static_implementation()" << endl;
    }
};


template<class T>
struct Shape: AbstractShape{
    void area:
}

template<class T>
void foo(Base<T> &b){
    b.interface();
}
int main(){
    Derived1 d1;
    Derived2 d2;
    Circle c;
    foo(d1);
    foo(d2);

    vector<Shape*> v {s, };
}
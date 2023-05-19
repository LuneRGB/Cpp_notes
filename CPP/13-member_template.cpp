#include<iostream>
using namespace std;

template<typename T>
struct complex{

    T real, imag;
    complex(T real, T imag) : real(real), imag(imag) {}

    template<typename U>   // 换了另一个模板
    complex(const complex<U>& other):
    real(other.real), imag(other.imag) {}
};

template<typename T>
ostream& operator<<(ostream& out, const complex<T>& c){
    return out << "(" << c.real << ", " << c.imag << ")" << endl;
}

int main(){

    // complex<double> a(3.14, -1.57);
    complex<float> a(3.14f, -1.57f);
    cout << a << endl;
    complex<double> b = a;
    cout << b << endl;

    // 不是同一个类型
    complex<int> c = a;
    cout << c << endl;    
}
#include<iostream>
using namespace std;

template<class T, int N>
class Array{
public:
    int size() const { return N; }
    T& operator[](int i) { return m_arr[i]; }
private:
    T m_arr[N];
};

int main(){

    Array<int, 3> a;
    a[0] = 2, a[1] = 3, a[2] = 1;
    cout << a.size() << endl;

    // 浅层封装
    Array<int, 4> b{};  // {}用来初始化
    cout << b[0] << ", " << b[1] << ", " << b[2] << endl;
    // 因为3和4是不同的类型，是两个不同的类
    b = a;
}
#include <iostream>
using namespace std;

// 表示<>里的东西是模板参数列表，接受一个类型作为参数，名字是T
template <typename T>
class Container {
    T* data;
    unsigned size = 0, capa;

public:
    // 这里写了一个默认参数
    Container(unsigned capa = 512) : data(new T[capa]), capa(capa) {}
    ~Container() { delete [] data; }
    Container(const Container &) = delete;
    // 这是干嘛了
    Container & operator=(const Container &rhs){
        if (this == &rhs)
            return *this;
        if (capa != rhs.capa){
            delete[] data;
            data = new T[rhs.capa];
        }
        for (unsigned i = 0; i < rhs.size; i++)
            data[i] = rhs[i];
        capa = rhs.capa;
        size = rhs.size;
        return *this;
    }
    // 类里不能再重复定义模板

    // 为了适配对象是和不是const的两种情况
    T& operator[](unsigned index) { return data[index]; }
    const T& operator[] (unsigned index) const {return data[index]; }

    // const Container<T> &c 调用了getSize
    unsigned getSize() const { return size; }
    unsigned getCapa() const { return capa; }

    // &: 为了支持链式的add
    Container & add(T val){
        /* TODO: if full, expand storage */
        data[size++] = val;
        return *this;
    }

};


// 模板函数是这样的，这个与上面的类无关的
template <typename T> 
T abs(T x) { return x>0? x: -x; }

template <typename T>
ostream &operator<<(ostream& os, const Container<T> &c){    

    for (unsigned i = 0; i < c.getSize(); i++){
        os << c[i] << ' ';
    }
    return os;
}


int main(){

    Container<int> ci(10);
    Container<double> cd;

    ci.add(1).add(2).add(3).add(4);

    cout << ci;

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void transform(vector<int>& v, function<int(int)> f){  // 函数指针不能接lambda function
    for (int &x : v)
        x = f(x);
}

// functor
class mul_by{
public:
    mul_by(int a) : a(a){}
    int operator()(int x) {
        return x*a;
    }
private:
    int a;
};

class add_by{
public:
    add_by(int a) : a(a){}
    int operator()(int x) {
        return x+a;
    }
private:
    int a;
};

class nth_power{
public:
    nth_power(int a) : a(a){}
    int operator()(int x) const {
        return pow(x, a);
    }
private:
    int a;
};

class print{
public:
    print(char sep) : sep(sep) {};
private:
    char sep;
}


int main(){
    vector<int> v({1,3,5,7,9});

    int a = 5;
    // transform(v, [a](int x) {return x * a;});
    transform(v, mul_by(5));
    a = 3;
    transform(v, mul_by(3));
    transform(v, add_by(3));
    transform(v, nth_power(3));

    for (int & x : v)
        x *= 5;
    for (int & x:v)
        x +=3;
    for (int &x : v)
        x = x*x;
    for (int &x : v)
        cout << x << ' ';

    cout << endl;

    return 0;
}


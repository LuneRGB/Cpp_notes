#include <iostream>
#include <vector>
using namespace std;

class vec3
{
public:
    // 如果没有初始值，会初始化为(0,0,0)，但是下面有初始值，所以将xyz的值覆盖了
    vec3(int x = 0, int y = 0, int z = 0)
    {
        v[0] = x;
        v[1] = y;
        v[2] = z;
    }
    // 这里用const是向编译器保证不会修改v的值
    int operator[](int index) const
    {
        return v[index];
    }
    // 这里因为const，决定了它会把参数变成一个右值
    // 也决定了它只能接受右值或常量对象
    vec3 &operator+=(const vec3 &rhs)
    {
        for (int i = 0; i < 3; ++i)
            v[i] += rhs[i];
        // 在这里我们不希望=返回的是一个指针，而应该是一个引用，即至少应该与rhs类型相同
        // 否则连等运算会出问题
        return *this;
    }

private:
    int v[3];
};

vec3 operator+(const vec3 &v1, const vec3 &v2)
{
    // auto tmp = v1; tmp += v2; return tmp;
    return vec3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}

ostream& operator<<(ostream &out, const vec3 &v)
{
    out << '(' << v[0] << ' ' << v[1] << ' ' << v[2] << ')';
    return out;
}

int main()
{
    vec3 v1(1, 2, 3), v2(4, 5, 6);
    vec3 v = v1 + v2;
    v += v2;
    cout << v << endl;
}
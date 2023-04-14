#include<iostream>
using namespace std;

struct Student
{
    int id;
    char addr[1000];
};

void foo(const Student *ps)
{
    cout << ps->id << endl;
    // 用指针可以修改对象的值
    // 用const可以限制修改指针的值
}

void bar(const Student &s)
{
    cout << s.id << endl;
}

// int main()
// {
//     int *a = new int[10]();
//     delete[] a;

//     a = nullptr;
//     delete[] a;     // detelet nullptr is safe

//     if (a != 0)
//         delete[] a;   // 不一定安全

//     // 不再使用的指针置空就可以了
// }

int main(int argc, char **argv)
{
//     const char *s = "hello, world";     // 需要承诺一下不会改
//     const char *s1 = "hello, world";     // 需要承诺一下不会改
//     char s2[] = "Hello World";

//     s2[0] = 'C';
//     cout << (void*)s << endl;
//     cout << (void*)s1 << endl;      // 和s一样
//     cout << (void*)s2 << endl;
//     cout << (void*)main << endl;

    Student s;
    s.id = 2;
    foo(s);     // 做了一个大对象的copy

}
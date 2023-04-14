#include<iostream>
#include<cstdlib>
using namespace std;

struct Student
{
    int id;
    Student()       // 构造函数：作变量初始化，资源分配
    {
        id = 123;
        cout << "Student::Student()" << endl;
    }
    ~Student()      // 析构函数
    {
        cout << "~Student::Student(): id = " << id << endl;
    }
};

int main()
{
    // int *pa = new int(1024);
    // cout << *pa << endl;

    // int *parr = new int[1024];    // 头部值给pa 
    // for (int i = 0; i < 10; ++i)
    // {
    //     parr[i] = i;
    //     cout << parr[i] << endl;
    // }

    // delete pa;
    // delete[] parr;

    Student *ps1 = (Student *)malloc(sizeof(Student));
    cout <<  "ps1->id = " << ps1->id << endl;           // id 没有做初始化，malloc只管分配内存不管初始化
    Student *ps2 = new Student;
    cout << "ps2->id = " << ps2->id << endl;
    
    free(ps1);
    delete(ps2);                // 会调用析构函数

    Student *psarr = new Student[5];
    for (int i = 0; i < 5; ++i)
    {
        psarr[i].id = i;
    }
    //delete[] psarr;
    delete psarr;   // 析构函数没跑完，free时会找不到合适的信息
}
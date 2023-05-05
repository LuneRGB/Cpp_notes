#include <iostream>
using namespace std;
class A{
private:
    char *p;
public:
    A& operator=(const A& rhs){
        if (&rhs != this){      // 避免self assignment
            delete[] p;
            p = new char[strlen(rhs.p) + 1];
            strcpy(p, rhs.p);
        }
        return *this;
    }
};

A a, b;
a = b;
a = a;
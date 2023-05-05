#include <iostream>
#include <cmath>
using namespace std;

using fn = std::function<double(double)>;

void print_info(int k, double x, double fx)
{
    cout << "k = " << k << ", x = " << x << 
}

double newton_solve(fn f, fn df, double x0, double tolerance)
{
    k = 0;
    x = x0;
    print_info(k, x, f(x));

    while(!is_close(f(x), tolerance) && (k++ < max_iter)){
        x = x - f(x) / df(x);
        print_info(k, x, f(x));
    }
}

double sqrt_newton(double a, double x0=1.0){
    double f(double x) override{
        return x
    }
}

double whateversolver()


class NewtonSolver{
private:
    // states for iterative solving
    int k;
    double x;
    double a;               // 为什么这里的公式是算根号？
    double tolerance;
    double max_iter; 
public:
    NewtonSolver(double tolerance = 1e-12, double max_iter = 30)
    : tolerance(tolerance), max_iter(max_iter), a(a), n(n){}

    void print_info()
    {
        cout << "k = " << k << ", x = " << x << endl;
    }
private:
    virtual double f(double x) = 0;
    virtual double df(double x) = 0;

    bool is_close(double x)
    {
        return fabs(f(x) - a);
    }
public:
    void improve(double x)
    {
        while(!is_close(x) < tolerance && k++ < max_iter)
        {
            x = x - f(x) / df(x);
            print_info();
        }
    }
};

class NthRootSolver : public NewtonSolver{
private:
    int n;
    double a;
public:
    NthRootSolver(double a, int n) : a(a), n(n){}
private:
    double f(double x) override{
        return pow(x, n)-a;
    }
    double df(double x) override{
        return n * pow(x, n-1);
    }
};

class WhateverSolver : public NewtonSolver{
private:
    double f(double x) override{
        return cos(x) - pow(x, 3);
    }
    double df(double x) override{
        return -sin(x) - 3*x*x;
    }
};


//匿名函数


// 这是解根号2
int main()
{
    NthRootSolver solver(621.0, 2);
    solver.improve(1.0);

}
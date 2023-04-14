struct X;

struct Y{
    void f(X*);
};

struct X{
    friend void g(X*, int);
    friend void h();
    friend void Y::f(X*);
    friend struct Z;
};
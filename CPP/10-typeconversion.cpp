class One{
public:
    One(){};
};

class Two{
public:
    explicit Two(const One&);
};

int f(One){
    One one;
    f(one);         // error
    Two two(one);   // ok
}
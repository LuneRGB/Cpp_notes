class Sample
{
    public:
        int k;
        int geti(){return i;}
        int getj(){return j;}
        int getk(){return k;}
    
    private:
        int i;
    
    protected:
        int j;
};

int main()
{
    Sample a;
    a.i;        // 非法
    a.j:        // 非法
    a.k;        // 合法
}
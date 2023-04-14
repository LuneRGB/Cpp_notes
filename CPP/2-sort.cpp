#include<iostream>
#include<string>
#include <cmath>
#include <vector>
#include <list>
#include "algorithm.h"
const double PI = 3.14;

struct Student
{
    int id;
    std::string name;
    bool operator<(const Student& s)
    {
        return id < s.id; 
        /*
            a < b
            a.operator < (b)
        */
    }
};
bool operator<(const Student& s1, const Student& s2)
{
    // 按学号排序
    return s1.id < s2.id;
    // 如果需要排两种怎么办
}

class Shape
{   
    protected:
        double area, perimeter;
    public:
        virtual ~Shape() {};    // 当有虚函数时析构函数也要是虚函数
        double get_area() const {return area;}
        double get_perimeter() const {return perimeter;}   

        virtual void calc_area() = 0;       // 纯虚函数
        virtual void calc_perimeter() = 0;
        virtual std::string name() const = 0;   // 有潜在改对象风险，承诺不会改对象值
        friend std::ostream& operator<<(std::ostream& out, const Shape& s);
};

bool less_shape_area (Shape* s1, Shape* s2)
{
    return s1->get_area() < s2->get_area();
}
bool more_shape_area (Shape* s1, Shape* s2)
{
    return s1->get_area() > s2->get_area();
}

bool less_shape_perimeter (Shape* s1, Shape* s2)
{
    return s1->get_perimeter() < s2->get_perimeter();
}

class Rectangle: public Shape
{
    private:        // 不能用结构体初始化
        double w, h;

    public:
        Rectangle(double ww, double hh): w(ww), h(hh) {};
        void calc_area() override
        {
            area = w * h;
        }
        void calc_perimeter () override
        {
            perimeter = 2 * (w + h);
        }
        std::string name() const override
        {
            return "Rect";
        }
};

class Circle: public Shape
{
    private:
        double r;
    public:
        Circle(double r) : r(r) {}
        void calc_area() override
        {
            area = PI * r * r;
        }
        void calc_perimeter() override
        {
            perimeter = PI * r * 2;
        }
        std::string name() const override
        {
            return "Circle";
        }
};

class Triangle: public Shape
{
    private:
        double a, b, c;
    public:
        Triangle(double a, double b, double c) : a(a), b(b), c(c) {}
        void calc_area() override
        {   
            double s = (a + b + c) / 2;
            area = sqrt(s * (s-a) * (s-b) * (s-c));
        }
        void calc_perimeter() override
        {
            perimeter = a + b + c;
        }
        std::string name() const override
        {
            return "Circle";
        }
};

std::ostream& operator<<(std::ostream& out, const Shape& s)
{
    out << "(" << s.name() << ":" << s.area << "," << s.perimeter << ")";
    // 一定要返回输出流
    return out;
}

int main()
{
    // int a[] = {64, 25,12, 23,11};
    // double a[] = {64.1, 25.2, 12.3, 23.4, 11.5};
    // std::string a[] = {"hello", "world", "zju", "aaa", "aaaaaaaa"};

    // Student a[] = {{123, "abc"}, {456, "adv"}, {234, "mozi"}};
    
    // Rectangle a[] = {Rectangle(2, 3), Rectangle(5, 5)};
    // Circle a2[] = {Circle(3)};
    // Triangle a3[] = {Triangle(2, 5, 4)};

    Shape* a[] = {new Rectangle(2, 3), new Circle(3), new Triangle(2, 4, 5)};    // 类似malloc
    
    for (Shape* s : a)  // 访问到每一个
    {
        s->calc_area();
        s->calc_perimeter();
    }

    using algorithm::selection_sort;
    using algorithm::print_array;

    int n = sizeof(a)/sizeof(a[0]);
    selection_sort(a, n, less_shape_area);       // 需要传进去n
    print_array(a, n);
    selection_sort(a, n, more_shape_area);       // 需要传进去n
    print_array(a, n);
    selection_sort(a, n, less_shape_perimeter);       // 需要传进去n
    print_array(a, n);
    
    std::vector<double> v;  // 用sort接口来排序，使用的是迭代器
    std::list<int> l;

    // 防止内存泄露
    for (Shape* s: a)
        delete s;

    return 0;
}
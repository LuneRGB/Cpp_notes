#include <iostream>
#include <string>
using namespace std;

class Shape{
public:
    void move(){
        cout << "Shape::move()" << endl;
    }
    virtual void render(){                      // 加move后就是动态绑定，会根据实际的对象类型决定函数的版本
        cout << "Shape::render()" << endl;
    }
    virtual ~Shape(){}                          // 如果有派生类一定要使用virtual

};    

class Rectangle:public Shape{
public:
    void render() override{
        cout << "Ellipse::render()" << endl;
    }
};

class Square:public Shape{
public:
    void render() override{
        cout << "Ellipse::render()" << endl;
    }
};

class Ellipse:public Shape{
public:
    void render() override{                 // 这个关键字不必须，但是会更显眼一点
        cout << "Ellipse::render()" << endl;
    }        
};

class Circle: public Shape{
public:  
    ~Circle(){
        cout << "Circle::circle()" << endl;
    }
    void render() override{
        cout << "Circle::render()" << endl;
    }
};

void foo(Shape *s){
    s->move();
    s->render();
}

#include <vector>
void move_and_redraw_all(const std::vector<Shape *> &shapes)
{
    for (auto p: shapes)
        foo(p);
}

int main(){
    Ellipse e;
    Circle c;
    Rectangle r;
    Square s;


std::vector<Shape*> all_shapes {&e, &c, &r, &s};
    std::unique_ptr<Circle> pc(new Circle);         // 智能指针
    std::unique_ptr<Square> ps(new Square);
    all_shapes.push_back(new Circle());
    all_shapes.push_back(new Square());
    move_and_redraw_all(all_shapes);

    delete all_shapes[4];                           // 没有办法call到Circle的析构，除非必须把基类的析构标成virtual
    delete all_shapes[5];
}
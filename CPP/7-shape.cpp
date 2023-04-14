#include <iostream>
#include <string>
using namespace std;

class Shape{
public:
    void move(){
        cout << "Shape move" << endl;
    }
    virtual void render(){                  // 加move后就是动态绑定，会根据实际的对象类型决定函数的版本
        cout << "Shape render" << endl;
    }

};    

class Ellipse:public Shape{
public:
    void render() override{                 // 这个关键字不必须，但是会更显眼一点
        cout << "Ellipse render" << endl;
    }        
};

class Circle: public Shape{
public:  
    void render() override{
        cout << "Circle: render()" << endl;
    }
};

void foo(Shape *s){
    s->move();
    s->render();
}

#include <vector>

int main(){
    Ellipse e;
    Circle c;
    foo(&e);
    foo(&c);
    std::vector<Shape *> all_shapes
}
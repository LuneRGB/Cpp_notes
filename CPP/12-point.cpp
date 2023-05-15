#include <iostream>
#include <iomanip>
using namespace std;

class Point{
public:
    Point(){}
    Point(int px, int py): x(px), y(py) {}
    friend ostream& operator<<(ostream& out, const Point& p);
    friend istream& operator>>(istream& in, Point& p);
private:
    int x, y;

};

class LineSegment{
public:
    LineSegment(const Point& p1, const Point& p2): start(p1), end(p2);

private:
    Point p1, p2;
};

ostream& operator<<(ostream& out, const Point& p){

    out << "(" << p.x << "," << p.y << ")";
    return out;
}

istream& operator>>(istream& in, Point& p){

    in >> p.x >> p.y;
    return in;
}

int main(){

    Point a(3,5);
    cout << a << endl;

    Point b;
    cin >> b;
    cout << b << endl;
}
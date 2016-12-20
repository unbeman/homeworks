#include <iostream>
#include "computer.h"
#include "figures.h"

using namespace std;

int main() {

    float n[2] = {2, 3};
    Rectangle * pt = new Rectangle(n);
    cout << Figure::get_count() << " " << pt->area() << " " << pt->perimeter()  << " " << pt->diagonal()  << endl;

    delete pt;
    pt = nullptr;

    float m[3] = {2, 3, 4};
    Triangle * ptr = new Triangle(m);
    cout << Figure::get_count() << " " << ptr->area() << " " << ptr->perimeter() << endl;

    float  s[3] = {3, 3, 5};
    IsoscelesTriangle * p = new IsoscelesTriangle(s);
    cout << Figure::get_count() << " " << p->area() << " " << p->perimeter() << " " << p->height() << endl;

    return 0;
}
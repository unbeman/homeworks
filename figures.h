//
// Created by a.kukuev on 06.12.16.
//

#ifndef HOMEWORKS_FIGURES_H
#define HOMEWORKS_FIGURES_H

#include <cstdio>

class Figure{
public:
    Figure(int edges, float * edges_len);
    virtual ~Figure();
    virtual float area() = 0;
    virtual float perimeter() = 0;
    static size_t get_count();
protected:
    int edges;
    float * edges_len;
    static size_t count;
};

class Triangle:public Figure{
public:
    Triangle(float * edges_len):Figure(3, edges_len){}
    ~Triangle(){}
    float area();
    float perimeter();
};

class Rectangle:public Figure{
public:
    Rectangle(float * edges_len):Figure(2, edges_len){}
    ~Rectangle(){}
    float area();
    float perimeter();
    float diagonal();
};

class IsoscelesTriangle:public Triangle{
public:
    IsoscelesTriangle(float * edges_len): Triangle(edges_len){}
    ~IsoscelesTriangle(){}
    float height();
};


#endif //HOMEWORKS_FIGURES_H

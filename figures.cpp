//
// Created by a.kukuev on 06.12.16.
//
#include <math.h>
#include "figures.h"

size_t Figure::count = 0;

Figure::Figure(int edges, float * edges_len):edges(edges){
    this->edges_len = new float [this->edges];
    for (size_t i = 0; i < edges; i++){
        this->edges_len[i] = edges_len[i];
    }
    this->count++;
}

Figure::~Figure(){
    delete [] edges_len;
    edges_len = nullptr;
    this->count--;
}

size_t Figure::get_count(){ return count; }

float Triangle::perimeter(){
    float res = 0;
    for (size_t i = 0; i < edges; ++i) {
        res += edges_len[i];
    }
    return res;
}

float Triangle::area(){
    float p = perimeter()/2;
    return sqrtf(p * (p - edges_len[0]) * (p - edges_len[1]) * (p - edges_len[2]));
}

float Rectangle::perimeter(){
    float res = 0;
    for (size_t i = 0; i < edges; ++i){
        res += edges_len[i];
    }
    return res;
}

float Rectangle::area(){
    return edges_len[0] * edges_len[1];
}

float Rectangle::diagonal(){
    return sqrtf(edges_len[0] * edges_len[0] + edges_len[1] * edges_len[1]);
}

float IsoscelesTriangle::height(){
    return Triangle::area()*2/edges_len[1];
}
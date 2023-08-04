#pragma once
#include "Points.h"
class LaGrange :
    public Points
{
public:
    LaGrange(int count) :Points(count){}
    double getValueInLaGrangePolynome(double x);
    friend std::istream& operator>>(std::istream& is, LaGrange& obj);
    void printPolynome();
};


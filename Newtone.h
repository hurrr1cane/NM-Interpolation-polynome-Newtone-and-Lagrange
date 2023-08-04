#pragma once
#include "Points.h"
class Newtone :
    public Points
{
private:
    double** matrixOfSeparatedDifferences;
    void calculateSeparatedDifferences();
public:
    Newtone(int points);
    double getValueInNewtonePolynome(double x);
    friend std::istream& operator>>(std::istream& is, Newtone& obj);
    void printTheTable();
};


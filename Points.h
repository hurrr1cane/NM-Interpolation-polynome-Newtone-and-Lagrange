#pragma once

#include <iostream>
class Points
{
protected:
	int countOfPoints;
	double** points;
	bool isFilled = false;
public:
	Points(int count);
	friend std::istream& operator>> (std::istream& is, Points obj);
};
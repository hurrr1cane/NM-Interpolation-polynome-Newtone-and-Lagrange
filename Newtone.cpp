#include "Newtone.h"
#include <iomanip>

std::istream& operator>>(std::istream& is, Newtone& obj)
{
    for (int i = 0; i < 2; i++) {
        std::cout << "Enter " << i + 1 << " row: ";
        for (int j = 0; j < obj.countOfPoints; j++) {
            is >> obj.points[j][i];
        }
    }
    obj.isFilled = true;
    return is;
}

void Newtone::calculateSeparatedDifferences()
{
    if (!isFilled) {
        throw std::exception("The data is not filled!");
    }

    //Making the first column
    for (int i = 0; i < countOfPoints - 1; i++) {      
        matrixOfSeparatedDifferences[0][i] = (points[i + 1][1] - points[i][1]) / (points[i + 1][0] - points[i][0]);
    }

    //Making the rest of the columns
    for (int i = 1; i < countOfPoints - 1; i++) { //i is a column index, column is first
        for (int j = 0; j < countOfPoints - i - 1; j++) { //j is a row index, row is second
            matrixOfSeparatedDifferences[i][j] = (matrixOfSeparatedDifferences[i - 1][j + 1] - matrixOfSeparatedDifferences[i - 1][j]) / (points[j + i + 1][0] - points[j][0]);
        }
    }
}

Newtone::Newtone(int points):Points(points)
{
    matrixOfSeparatedDifferences = new double* [points - 1];
    for (int i = 0; i < points; i++) {
        matrixOfSeparatedDifferences[i] = new double[points - 1];
    }
}

double Newtone::getValueInNewtonePolynome(double x)
{
    calculateSeparatedDifferences();
    double sum = points[0][1];

    for (int i = 0; i < countOfPoints - 1; i++) {
        double term = matrixOfSeparatedDifferences[i][0];
        for (int j = 0; j < i + 1; j++) {
            term *= (x - points[j][0]);
        }
        sum += term;
    }

    return sum;
}

void Newtone::printTheTable()
{
    calculateSeparatedDifferences();
    std::cout << "x      y ";
    for (int i = 0; i < countOfPoints - 1; i++) {
        std::cout << std::setw(10) << "Delta " << i + 1;
    }
    std::cout << '\n';
    for (int i = 0; i < countOfPoints; i++) {
        std::cout << std::left << std::setw(6) << points[i][0] << ' ' << points[i][1] << ' ';
        for (int j = 0; j < countOfPoints - 1 - i; j++) {
            std::cout << std::setw(10) << std::setprecision(4) << matrixOfSeparatedDifferences[j][i] << ' ';
        }
        std::cout << '\n';
    }
    std::cout.unsetf(std::ios::left); std::cout << std::setprecision(-1) << std::setw(0);
}



#include "LaGrange.h"

#include "CSystemOfLinearEquations.h"

double LaGrange::getValueInLaGrangePolynome(double x)
{
    if (!isFilled) {
        throw std::exception("The data is not filled");
    }
    double y = 0;
    for (int i = 0; i < countOfPoints; i++) {  //Here I add each term
        //y+= (sumOfUpper/sumOfLower) * points[i][1]
        double numerator = 1, denumerator = 1;
        for (int j = 0; j < countOfPoints; j++) { //Here I get each term
            if (j == i) {
                continue;
            }
            else {
                numerator *= (x - points[j][0]);
                denumerator *= (points[i][0] - points[j][0]);
            }
        }
        y += (numerator / denumerator) * points[i][1];
    }
    return y;
}

void LaGrange::printPolynome()
{
    double** array = new double*[countOfPoints];
    for (int i = 0; i < countOfPoints; i++) {
        array[i] = new double[countOfPoints + 1];
    }

    for (int i = 0; i < countOfPoints; i++) {
        for (int j = 0; j < countOfPoints; j++) {
            array[i][j] = pow(points[i][0], countOfPoints - 1 - j);
        }
        //fill Y
        array[i][countOfPoints] = points[i][1];
    }

    CSystemOfLinearEquations mySystem(countOfPoints);
    mySystem.enterCoefficients(array);
    double* solutions = mySystem.solveUsingGaussWithChoosingMainElement();

    std::cout << "y = ";
    for (int i = 0; i < countOfPoints; i++) {
        std::cout << " + " << solutions[i] << "*x^" << countOfPoints - i - 1;
    }
}

std::istream& operator>>(std::istream& is, LaGrange& obj)
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

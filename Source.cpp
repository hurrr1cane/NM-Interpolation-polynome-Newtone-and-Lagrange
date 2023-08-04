#include <iostream>
#include "LaGrange.h"
#include "Newtone.h"

int main(void) {
	LaGrange myPolynome(3);
	std::cin >> myPolynome;
	std::cout << "The value in LaGrange polynome: ";
	std::cout << myPolynome.getValueInLaGrangePolynome(0.1821/*1.362*/) << "\n\n";
	myPolynome.printPolynome();
	std::cout << "\n\n";

	Newtone mySecondPolynome(3);
	std::cin >> mySecondPolynome;
	std::cout << '\n';
	mySecondPolynome.printTheTable();
	std::cout << "The value in Newtone polynome: ";
	std::cout << mySecondPolynome.getValueInNewtonePolynome(0.1821/*1.362*/) << '\n';
}
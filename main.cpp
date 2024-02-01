#include <iostream> 
#include "quadraticEq.h"

int main() {
	quadraticEq eq1(1, -3, 2);
	quadraticEq eq2(1, 6, -5);

	std::cout << "Equation 1: " << eq1 << std::endl;
	eq1.calculateRoots();

	std::cout << "Equation 2: " << eq2 << std::endl;
	eq2.calculateRoots();

	quadraticEq sum = eq1 + eq2;
	std::cout << "Equations sum: " << sum << std::endl;

	quadraticEq difference = eq1 - eq2;
	std::cout << "Equations difference: " << difference << std::endl;

	if (eq1 == eq2) {
		std::cout << "The equations are equal" << std::endl;
	}
	else {
		std::cout << "The equations are not equal" << std::endl;
	}

	return 0;
}
#pragma once
#include <iostream>
#include <cmath>
#include <complex>

class quadraticEq {
public:
	quadraticEq(double a = 1, double b = 0, double c = 0) : a(a), b(b), c(c) { }

	friend std::ostream& operator<<(std::ostream& os, const quadraticEq& q) {
		os << q.a << "x^2 ";
		if (q.b >= 0) os << "+ " << q.b << "x ";
		else os << "- " << -q.b << "x ";
		if (q.c >= 0) os << "+ " << q.c;
		else os << "- " << -q.c;
		return os;
	}

	friend std::istream& operator>>(std::istream& is, quadraticEq& q) {
		is >> q.a >> q.b >> q.c;
		return is;
	}
	quadraticEq operator+(const quadraticEq& rhs) const {
		return quadraticEq(a + rhs.a, b + rhs.b, c + rhs.c);
	}

	quadraticEq operator-(const quadraticEq& rhs) const {
		return quadraticEq(a - rhs.a, b - rhs.b, c - rhs.c);
	}

	bool operator==(const quadraticEq& rhs) const {
		return a == rhs.a && b == rhs.b && c == rhs.c;
	}

	bool operator!=(const quadraticEq& rhs) const {
		return !(*this == rhs);
	}

	void calculateRoots() const {
		double discriminant = b * b - 4 * a * c;
		std::cout << "The equation " << *this << " has ";
		if (discriminant > 0) {
			std::cout << "two real roots: ";
			double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
			double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
			std::cout << root1 << " and " << root2;
		}
		else if (discriminant == 0) {
			std::cout << "one real root: ";
			double root = -b / (2 * a);
			std::cout << root;
		}
		else {
			std::cout << "two complex roots: ";
			std::complex<double> root1 = (-b + std::sqrt(std::complex<double>(discriminant))) / (2 * a);
			std::complex<double> root2 = (-b - std::sqrt(std::complex<double>(discriminant))) / (2 * a);
			std::cout << root1 << " and " << root2;
		}
		std::cout << std::endl;
	}
private:
	double a, b, c;
};
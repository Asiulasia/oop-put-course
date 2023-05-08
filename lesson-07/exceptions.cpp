#include <iostream>
#include <cmath>
#include <exception>

using namespace std;

class LogarithmException : public exception {
public:
	virtual const char* what() const throw() {
		return "Logarithm exception occurred.";
	}
};

class InvalidBaseException : public LogarithmException {
public:
	virtual const char* what() const throw() {
		return "Invalid base exception occurred.";
	}
};

class InvalidArgumentException : public LogarithmException {
public:
	virtual const char* what() const throw() {
		return "Invalid argument exception occurred.";
	}
};

class Logarithm {
public:
	Logarithm(double base, double number) : base_(base), number_(number) {
		if (base_ <= 0 || base_ == 1) {
			throw InvalidBaseException();
		}
		if (number_ <= 0) {
			throw InvalidArgumentException();
		}
	}

	double Calculate() const {
		try {
			return log(number_) / log(base_);
		}
		catch (const exception & e) {
			throw LogarithmException();
		}
	}

private:
	double base_;
	double number_;
};


int main() {
	double base;
	double number;

	cout << "Base: ";
	cin >> base;
	cout << "Argument: ";
	cin >> number;

	try {
		Logarithm log(base, number);
		double result = log.Calculate();
		cout << "log_" << base << "(" << number << ") = " << result << endl;
	}
	catch (const InvalidBaseException & e) {
		cerr << "Invalid base: " << e.what() << endl;
	}
	catch (const InvalidArgumentException & e) {
		cerr << "Invalid argument: " << e.what() << endl;
	}
	catch (const LogarithmException & e) {
		cerr << "Error: " << e.what() << endl;
	}

	return 0;
}

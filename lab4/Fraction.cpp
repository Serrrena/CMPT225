#include <iostream>
#include "Fraction.h"

using namespace std;
// invariant: denominator is always positive.
//            fraction always in lowest terms (simplified).


// Default constructor
Fraction::Fraction(void)
{
	numerator = 0;
	denominator = 1;
}

// Constructor
Fraction::Fraction(int n, int d)
{
	if (d == 0) {
		throw new DivideByZeroException();
	} else {
		numerator = n;
		denominator = d;
		simplify();
	}
}

Fraction::~Fraction(void)
{
}

// Returns the (positive) greatest common divisor of two integers
int Fraction::gcd(int a, int b) const {
	if (a < 0) a = -a;
	if (b < 0) b = -b;

	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

// Simplifies the receiver
void Fraction::simplify(){
	int factor = gcd(numerator, denominator);
	numerator = numerator / factor;
	denominator = denominator / factor;
}

// Overloaded Operators
/* (try to figure out the expressions
 *  for the result numerator and denominator yourself.
 *  Only use this to check your work.)
 *
 * In each case: (num1/den1) op (num2/den2)
 *
 * PLUS OPERATOR
 * result = (num1 * den2 + num2 * den1) / (den1 * den2)
 *
 * MINUS OPERATOR
 * result = (num1 * den2 - num2 * den1) / (den1 * den2)
 *
 * MULIPLICATION OPERATOR
 * result = (num1 * num2) / (den1 * den2)
 *
 * DIVISION OPERATOR
 * result = (num1 * den2) / (den1 * num2)
 */
Fraction Fraction::operator+(const Fraction &F) const{
	Fraction NewF;
	int den1 = denominator;
	int den2 = F.denominator;
	int num1 = numerator;
	int num2 = F.numerator;
	NewF.numerator = (num1 * den2 + num2 * den1) ;
	NewF.denominator = den1 * den2;
	NewF.simplify();
	return NewF;
}
Fraction Fraction::operator-(const Fraction &F) const{
	Fraction NewF;
	int den1 = denominator;
	int den2 = F.denominator;
	int num1 = numerator;
	int num2 = F.numerator;
	NewF.numerator = (num1 * den2 - num2 * den1) ;
	NewF.denominator = den1*den2;
	NewF.simplify();
	return NewF;

}
Fraction Fraction::operator*(const Fraction &F) const{
	Fraction NewF;
	int den1 = denominator;
	int den2 = F.denominator;
	int num1 = numerator;
	int num2 = F.numerator;
	NewF.numerator = num1 * num2 ;
	NewF.denominator = den1 * den2;
	NewF.simplify();
	return NewF;

}
Fraction Fraction::operator/(const Fraction &F) const{
	Fraction NewF;
	int den1 = denominator;
	int den2 = F.denominator;
	int num1 = numerator;
	int num2 = F.numerator;
	NewF.numerator = num1 * den2 ;
	NewF.denominator = den1 * num2;
	NewF.simplify();
	return NewF;

}

void operator<<(ostream & os, const Fraction &F){
	os << F.numerator << "/" << F.denominator << endl;
}
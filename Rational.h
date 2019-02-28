/*
 * Rational.h
 *
 *  Created on: Feb 11, 2017
 *      Author: Julio Rasarop
 *
 *  Purpose: What this class is supposed to do is Add,subtract,multiply,
 *           divide and compare rational fractions by using overloaded operators.
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_
#include <iostream>
using namespace std;

class Rational
{
	friend ostream& operator<<(ostream& out, Rational);  //output Fraction
	friend istream& operator>>(istream& in, Rational&);   //input  Fraction

	private:
		int numerator;
		int denominator;
		int length;

	public:
		Rational(int numerator = 0, int demoninator = 1);   //Default Constructor

		Rational operator+(Rational);				//Add Fractions
		Rational operator-(Rational);				//Subtract Fraction
		Rational operator*(Rational);				//Multiply Fraction
		Rational operator/(Rational);				//Divide Fraction

		//Compare the fractions.
		bool operator>(Rational);
		bool operator>=(Rational);
		bool operator<(Rational);
		bool operator<=(Rational);
		bool operator==(Rational);
		bool operator!=(Rational);


		int findGCF(int,int);						//Use Recursion to find GCF
		void simplifyRational();                  //Use GCF to simplify rational.

		//Validate input.
		bool validateInput();
};
#endif /* RATIONAL_H_ */

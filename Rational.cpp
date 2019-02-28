#include "Rational.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

ostream& operator<<(ostream& out, Rational fraction)
{
	fraction.simplifyRational();
	if(fraction.denominator<0)
	{
		fraction.denominator *= -1; fraction.numerator *=-1;}

	  return out << fraction.numerator<< "/" << fraction.denominator;
}

istream& operator>>(istream& in, Rational& fraction)
{
   char slash;
   in >> fraction.numerator >> slash >> fraction.denominator;

   if(!fraction.validateInput())
	   exit(0);

   fraction.simplifyRational();
   return in;
}

Rational::Rational(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;

	if(!validateInput())
		exit(0);

   simplifyRational();
}

Rational Rational::operator+(Rational fraction)
{
	Rational result;

	result.numerator = (numerator*fraction.denominator) +
					   (denominator*fraction.numerator);
	result.denominator = denominator*fraction.denominator;

	return result;
}

Rational Rational::operator-(Rational fraction)
{
	Rational result;

	result.numerator = (numerator*fraction.denominator) -
		               (denominator*fraction.numerator);
	result.denominator = denominator*fraction.denominator;

	return result;
}

Rational Rational::operator*(Rational fraction)
{
	Rational result;

	result.numerator = numerator*fraction.numerator;
	result.denominator = denominator*fraction.denominator;

	return result;
}

Rational Rational::operator/(Rational fraction)
{
	Rational result;

	result.numerator = numerator*fraction.denominator;
	result.denominator = denominator*fraction.numerator;

	//Make sure it return positive if both are negative
	if(result.numerator<0 && result.denominator<0)
	 {
		result.numerator *= -1; result.denominator *= -1;}

	return result;
}

bool Rational::operator>(Rational fraction)
{
	return (numerator * fraction.denominator) >
		  (denominator *fraction.numerator);
}

bool Rational::operator>=(Rational fraction)
{
	return (numerator * fraction.denominator) >=
		   (denominator *fraction.numerator);
}

bool Rational::operator<(Rational fraction)
{
	return (numerator * fraction.denominator) <
		  (denominator *fraction.numerator);
}

bool Rational::operator<=(Rational fraction)
{
	return (numerator * fraction.denominator) <=
		  (denominator *fraction.numerator);
}

bool Rational::operator==(Rational fraction)
{
	return (numerator * fraction.denominator) ==
		  (denominator *fraction.numerator);
}

bool Rational::operator!=(Rational fraction)
{
	return (numerator * fraction.denominator) !=
		  (denominator *fraction.numerator);
}

int Rational :: findGCF(int numerator,int denominator)
{
	if(denominator == 0 ) return numerator;
	else  return findGCF(denominator,numerator%denominator);
}

void Rational:: simplifyRational()
{
	int GCF = findGCF(numerator,denominator);

	if(GCF<0)
		GCF*=-1;

	numerator /=GCF;
	denominator /=GCF;
}

bool Rational:: validateInput()
{
	if(denominator == 0)
		return false;
	else
		return true;
}

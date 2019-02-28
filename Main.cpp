/*
 * Main.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: Julio Rasarop
 *
 *  Purpose: To test the Rational class, by prompting user for two Rational
 *           and use the +-/*  operator for calculation including <, <= ==
 *           >, >=,!=
 * */
#include <iostream>
#include <string>
#include "Rational.h"
#include <cstdlib>
using namespace std;

void showMenu();										//Show menu
void promptUserForFraction(int);						//Prompt user for fraction.
Rational getCalculationFor(int,Rational,Rational);      //Calculate choice,and the two fractions.
void displayResult(Rational,string);                    //Display Result of calculation.
void compareAndDisplayResult(Rational,Rational);      	 // compare  and Display result.

int main()
{
	Rational fraction1,
	         fraction2;

	int choice;	//User choice.

	showMenu();
	cin >> choice;

	promptUserForFraction(1);
	cin >> fraction1;
	promptUserForFraction(2);
	cin >> fraction2;
	cout << "\n";

	string operationType[4] = {"addition","subtraction",
							   "multiplication","division"};

	//calculation for operand +-*/
	if(choice == 5)
	{
		Rational results[4];		//Create an array of Rational if user choose option #5.

		//Get calculation for each Rational and display result
		for(int i = 0; i<choice-1; i++)
		{
			results[i] = getCalculationFor((i+1),fraction1,fraction2) ;
			displayResult(results[i],operationType[i]);
		}
	}
	else if(choice == 6)  //Exit program.
	{
		exit(0);
	}
	else //Display result for other than 5 or 6.
	{
		Rational result = getCalculationFor(choice,fraction1,fraction2);
		displayResult(result, operationType[choice]);
	}

	compareAndDisplayResult(fraction1,fraction2);
	return 0;
}


void showMenu()
{
	cout << "******************************\n"
		 << "|Rational Fraction Calculator|\n"
		 << "*****************************\n\n";

	cout << "\nSelect one of the following options\n" <<
			"-----------------------------------\n";
	cout << "1.Add Fractions.\n"
		 << "2.Subtract Fractions.\n"
		 << "3.Multiply Fractions.\n"
		 << "4.Divide Fractions.\n"
		 << "5.All of the above.\n"
		 << "6.Quit the program.\n"
		 << "Enter your choice: ";
}

void promptUserForFraction(int num)
{
	//Get input from user for two fractions.
	cout << "\nEnter fraction#" << num <<  " in the form a/b where b is not 0:  ";

}

Rational getCalculationFor(int choice, Rational fraction1, Rational fraction2)
{
	Rational result;

	switch(choice)
	{
		case 1:
			result = fraction1+fraction2;
			break;
		case 2:
			result = fraction1-fraction2;
			break;
		case 3:
			result = fraction1*fraction2;
			break;
		case 4:
			result = fraction1/fraction2;
			break;
		default:
			cout<<"\nInvalid Choice!";
	}
	return result;
}

void compareAndDisplayResult(Rational fraction1,Rational fraction2)
{

	cout << "\nThe following are result of comparison:\n";

	//Use if, instead of if else  if to test program throughly.
    if(fraction1>=fraction2)
    {
	    cout << fraction1 << " is >= " << fraction2 << "\n";
    }
    if(fraction1 == fraction2)
    {
		cout << fraction1 << " is = " << fraction2 << "\n";
    }
    if(fraction1>fraction2 && fraction1 !=fraction2)
    {
		 cout << fraction1 << " is >  and != " << fraction2 << "\n";
    }
    if(fraction1<=fraction2)
	{
		 cout << fraction1 << " is <= " << fraction2 << "\n";
	}
    if(fraction1<fraction2 && fraction1 != fraction2)
	{
		 cout << fraction1 <<  " is < and != " << fraction2 << "\n";
	}
}

void displayResult(Rational fraction,string operand)
{
	cout<<"The " << operand << ": " << fraction << "\n";
}

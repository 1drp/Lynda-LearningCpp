/*
 * CashRegister.cpp
 *
 *  Created on: Aug 26, 2017
 *      Author: Daniel Peterson
 *
 *  Section 3 challenge for Lynda.com course, Learning C++
 */

#include <iostream>
#include <cmath>
using namespace std;

float entries(float taxRate)
{
	float total = 0, entry = 0, tax = 0;

	cout << "Enter the first item's price (0 to cancel): ";
	cin >> entry;
	total = entry;

	while(entry != 0)
	{
		cout << "Enter the next item's price (0 to finish): ";
		cin >> entry;
		total += entry;
	};

	// outputs
	cout << "Subtotal = $" << total << endl;
	tax = round((total * taxRate)*100)/100;		//round tax to even cents
	cout << "Tax = $" << tax << endl;
	total = total + tax;
	cout << "Total = $" << total << endl;

	return total;
}

void change(float total, float payment)
{
	int change = 0, dollars = 0, quarters = 0, dimes = 0, nickels = 0, pennies = 0;

	change = (payment - total)*100;
	dollars = change / 100;
	quarters = change % 100 / 25;
	dimes = change % 25 / 10;
	nickels = change % 25 % 10 / 5;
	pennies = change % 5;

	cout  << "The correct change is: "  << dollars << " dollars, "
			<< quarters << " quarters, " << dimes << " dimes, "
			<< nickels << " nickels, and " << pennies << " pennies."
			<< endl;
}

int main()
{
	char another = 'y';
	float taxRate = 0, total = 0, payment = 0;

	cout << "Welcome to the cash register." << endl
			<< "Please enter the local tax rate: ";
	cin >> taxRate; //tax rate not required by the challenge, but is more realistic

	//tax rate sanity check
	while(taxRate > 1 || taxRate < 0)
	{
		cout << "Invalid entry.  Please enter a number between 0 and 1: ";
		cin  >> taxRate;
	};

	while(another == 'y' || another == 'Y')
	{
		total = entries(taxRate);

		cout << "Enter customer's payment amount: ";
		cin >> payment;

		change(total,payment);

		cout << "Would you like to do another transaction? (y/n): ";
		cin >> another;
	};
	return 0;
}


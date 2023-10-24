/* Program Name: TakeHomePay.cpp
 * Student Name: Aaron Marshall
 * Net ID: amarsh32
 * Student ID: 000614990
 * Program Description: The intention of this program is to take the user's input (annual job salary) and 
 * output proper information reguarding taxes, post-tax salary, and monthly take-home pay. 
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

/* The proper double variables are set below for each tax statement */
	
	double yrSalary;
	double ssTax;
	double mTax;
	double iTax;
	double thSalary;
	double mthPay;

/* These statments are necessary for calculating the tax for Social Security and Medicare */

	ssTax = (6.2 / 100);
	mTax = (1.45 / 100);

	cout << "Enter a salary: $";
	cin >> yrSalary;

/* In addition to the statments above, they are multipled by the Yearly Salary to get the proper tax amount */

	ssTax = ssTax * yrSalary;
	mTax = mTax * yrSalary; 

/* The if / else statements below are intended to properly calculate the income tax based on the number the user inputs. With this the number will be filtered based on the preference and then calculated based on it's bracket with the precentages */

	if (yrSalary < 15080) {

		cout << "This is less than minimum wage for a yearly salary.";

	} else {
		
		if (yrSalary <= 41775) {

		iTax = (yrSalary - 10275) * (12.0 / 100.0)  + 10275 * (10.0 / 100.0);

	} else if (yrSalary > 41775 && yrSalary <= 89075) {

		iTax = (yrSalary - 41775) * (22.0 / 100.0) + (41775 - 10275) * (12.0 / 100.0) + 10275 * (10.0 / 100.0);

	} else if (yrSalary > 89075 && yrSalary <= 170050) {

		iTax = (yrSalary - 89075) * (24.0 / 100.0) + (89705 - 41775) * (22.0 / 100.0) + (41775 - 10275) * (12.0 / 100.0) + 10275 * (10.0 / 100.0);

	} else if (yrSalary > 170050 && yrSalary <= 215950) {

		iTax = (yrSalary - 170050) * (32.0 / 100.0) + (170050 - 89075) * (24.0 / 100.0) + (89075 - 41775) * (22.0 / 100.0) + (41775 - 10275) * (12.0 / 100.0) + 10275 * (10.0 / 100.0);

	} else if (yrSalary > 215950 && yrSalary <= 539900) {

		iTax = (yrSalary - 215950) * (35.0 / 100.0) + (215950 - 170050) * (32.0 / 100.0) + (170050 - 89075) * (24.0 / 100.0) + (89075 - 41775) * (22.0 / 100.0) + (41775 - 10275) * (12.0 / 100.0) + 10275 * (10.0 / 100.0);

	} else {

		iTax = (yrSalary - 539900) * (37.0 / 100.0) + (539900 - 215950) * (35.0 / 100.0) + (215950 - 170050) * (32.0 / 100.0) + (170050 - 89075) * (24.0 / 100.0) + (89075 - 41775) * (22.0 / 100.0) + (41775 - 10275) * (12.0 / 100.0) + 10275 * (10.0 / 100.0); 

	}

/* These statements below  are used to calculate and output the Take Home Salary and Monthly Take Home Pay */
		
	thSalary = yrSalary - iTax - ssTax - mTax;
	mthPay = (thSalary / 12.0);

/* These statements below create the proper output page by using width and precision setters to be able to produce proper gap placements for the outputs and be precise to two decimals */

	cout << "-----------------------------------" << endl;

	cout << left << setw(25) << "Yearly Salary:" << "$" << right << setw(9) << fixed << setprecision(2) << yrSalary << endl;
	cout << left << setw(25) << "Social Security Tax:" << "$" << right << setw(9) << fixed << setprecision(2) << ssTax << endl;
	cout << left << setw(25) << "Medicare Tax:" << "$" << right << setw(9) << fixed << setprecision(2) << mTax << endl;
	cout << left << setw(25) << "Income Tax:" << "$" << right << setw(9) << fixed << setprecision(2) << iTax << endl;

	cout << "-----------------------------------" << endl;

	cout << left << setw(25) << "Take Home Salary:" << "$" << right << setw(9) << fixed << setprecision(2) << thSalary << endl;
	cout << left << setw(25) << "Monthly Take Home Pay:" << "$" << right << setw(9) << fixed << setprecision(2) << mthPay << endl;
		
	}

	return 0;

}

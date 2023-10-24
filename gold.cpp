/*
Name: Aaron Marshall
NetID: amarsh32
Program Description: The purpose of this program is to recognize the amount of gold (in ounces) based on the different string values given by the user 
 *
 * */


#include <iostream>

using namespace std;


int main () {

	int val;
	char c;
	int total = 0;

//Variables val and c are used to correlate the number values with the character strings in the input.

//Total is initialized as a integer value to keep a running total of the amount of gold


	while (cin >> c) {

		val = c;

		if (c != '-' &&  c != '.') {

			total += (val - 64);

		}

	}

//The while loop above is used to check and see given characters. If a hyphen and period is not stated, then the value is given based on it total added by substracting the value by 64 (ASCII). Otherwise it will automatically equal zero.

	cout << total << endl;
	return 0;

}

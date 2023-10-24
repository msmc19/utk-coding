/* Error Checking
	Read in doubles, and if the user types in something other than
	a double, refuse that entry.
	REMEMBER: 3, 4, 10, etc ARE doubles. Whole numbers are stored as 3.0,4.0 ...
	Errors will look like: blah, hello, garbage, dog, agal; */

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

void ignoreLine()
{

	cin.ignore(numeric_limits<steamsize>::max(), '\n');

}


int main() {

	while (true) // Loop util user enters a valid input
	{

		cout << "Enter a double value: ";
		double x;
		cin >> x;

		if (!cin) // has a previous extraction failed?
		{

			// yep, so let's handle the failure
			cin.clear(); // put us back in 'normal' operation mode
			ignoreLine(); // and remove the bad input
			cout << "fail" << endl;

		}
		else
		{

			ignoreLine();
			cout << x << endl;


/* Time Zone Conversion Calculator */
/* Converting from Pacific to Eastern */

#include <iostream>
#include <iomanip>

int main() {
	// 3 hour difference
	// time (int hours, int minutes)
	// convert the time to Eastern (+3) - mod % 
	// Print out the time as HH:MM
	// "The time converted to Eastern time is HH:MM" <-- setfill, setwidth
	

	int min, aHr, bHr;

	cout << "Enter the Pacific time - Hours: ";
	cin >> aHr;
	cout << "Minutes: ";
	cin >> min;

	bHr = (aHr + 3) % 12;
	if (bHr == 0 ) bHr = 12;

	cout << "The time converted to Eastern Time is ";
	cout << setfill('0') << setw(2) << bHr << ":" << setw(2) <<  min;
	cout << "." << endl;


}

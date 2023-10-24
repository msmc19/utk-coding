/* Marathon Pace Calculator 

	user enter hours and minutes of a goal marathon
	Proram will return the pace
	03:30 marathon is 8:01 pace prints (M)M:SS 10:15
	Marathon is 26.2 miles

*/


#include <iostream>
#include <iomanip>

int main () {

	int mHr, mMin, pMin, pSec;

	cout << "Enter the marathon time- hours: ";
	cin >> mHr;
	cout << "Minutes: ";
	cin >> mMin;

	// Convert mHr and mMin to all seconds
	totalSeconds = (mMin * 60) + (MHr * 60 * 60);

	double paceInSeconds = (int) (totalSeconds / marathonDist);
	
	cout << paceInSeconds;

	pMin = (int) (paceInSeconds / 60);
	pSec = ((int) paceInSeconds % 60);

	cout << pHr << ":" <<  pMin;
}

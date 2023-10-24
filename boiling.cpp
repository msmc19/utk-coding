/* Program Name: Boiling Point Caulculator (boiling.cpp)
 * Student Name: Aaron Marshall
 * NET ID: amarsh32
 * Student ID: 000614990
 * Program Description: The purpose of this program is to take an input file with a list of locations with specific altitudes allowing the user to pick one of the locations from the list and calculate the boiling point of water at the altitude given by the chosen location by the user.
 */


#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;


int main (int argc, char** argv) {

//File stream is started and the respective integer and double varibles are declared to store and calculate thetemperature. In addition, the i variables helps to output the proper city values when opening the csv files (in the while loop).

	ifstream fin;
	string line, altitude, state, city, inputFile; 
	
	int fileAltitude, cityNumber, inputAltitude;
	int i = 1;
	double pressure, boilingTemp;

//The input file specified will be set to argv[1] and if the user inputs any more than 2 arguments then an error ouput will be given.

	inputFile = argv[1];
	fin.open (inputFile);
	if (argc !=2) {

		cerr << "usage: ./boiling filename";
		return 1;

	}


	if (!fin.is_open()) {

		cerr << "File failed to open.\n";
		return 1;

	}

//Empty vectors will be created for the different elevations and cityNames to help store and caculate the boiling point efficiently when the user inputs a number.

	vector <string> cityNames;
	vector <int> elevations;
	istringstream ss;
	getline (fin, line);

	cout << "Boiling Point at Altitude Calculator\n";

//The while loop will look through the file inputted and store each string/number in its respective variables i.e city,state, and altitude. This is also done by the comma seperatation in the file itself.

	while (getline (fin, line)) {

		ss.str(line);
		getline(ss, city, ',');
		getline(ss, state, ',');
		getline(ss, altitude, ',');

//The altitude values in the file are converted to integers to allow for future calculations based on the user input. In addition, the cities and altitudes are stored in the respective vectors to help with calculations.

		fileAltitude = stoi(altitude);
		cityNames.push_back(city);
		elevations.push_back(fileAltitude);

		cout << i << ". " << city << endl;
			i++;
			ss.clear();

	}


//The user is prompted for a city number based on the list provided with the previous loop used.

	cout << "Enter city number: ";
	cin >> cityNumber;

// With the way that vectors work, to get the correct value inputted by the user, you need to subtract the number by one to get the right elements in the list. This is crucial when finding the right city input and putting that city with the right elevation. In addition, the proper equations and values are used to calculate the boiling temperature.

	inputAltitude = elevations[cityNumber - 1];
	pressure = (29.921 * pow(1 - (0.0000068753 * inputAltitude), 5.2559));
	boilingTemp = (49.161 * log(pressure) + 44.932);


	string inputCity;
	inputCity = cityNames[cityNumber - 1];

//The correct input city is displayed and its boiling temperature found at the third decimal place.

	cout << "The boiling point at " << inputCity << " is " << setprecision(3) << fixed << boilingTemp << " degrees Farenheit." << endl;

//The file stream is closed and returned to the start.

	fin.close();
	return 0;

}

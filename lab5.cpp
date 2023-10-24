/* Program Name: Lab 5 (Speeding Ticket Calculator)
 * Student Name: Aaron Marshall
 * NET ID: amarsh32	
 * Student ID: 000614990
 * Program Description: The purpose of this program is to take the input from the user (ticket file) created by a police database then outputting it to the console. This output will be filtered to the starting and ending dates of the given input. NOTE: A ticket fee will be applied to the users input based on the type of road the database correlates it with. 
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char** argv) {


//Intended string variables to take from the input file.

	string inputFile;
	string citationNumber;
	string months [12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

//The ifstream function is used to take the input file made and used in the program.

	ifstream fin;

//Varibles used to store the multiplier values and fine amount.

	char multi; 
	double residentMulti = 17.1544;
	double highwayMulti = 9.4826;
	double interstateMulti = 5.2341;
	double miscMulti = 12.8334;
	double fineAmount;

//Integers necessary for storing the user's input vaulues and creating a proper output based on the input file and multipliers.

	int year, month, day, userMonth, clockedSpeed, speedLimit;
	int year1, year2, month1, month2, day1, day2;


	cout << "Enter a ticket file: ";
	cin >> inputFile;

//Error checking used if the input file doesn't fall under the right criteria, a message will be given to the user.

	fin.open(inputFile);
	if (!fin.is_open()) {

		cout << "Could not open " << inputFile << ".\n";
		return 1;

	}


//Takes the user's month values for the report and stores them as integers.

	cout << "Enter report start date (mm dd yyyy): ";
	cin >> month1 >> day1 >> year1;
	cout << "Enter report end date (mm dd yyyy): ";
	cin >> month2 >> day2 >> year2;


//While loop is used to check the user's input and input file information looping around to see what citation number, date, and fine will be given.

	while (fin >> citationNumber >> month >> day >> year >> clockedSpeed >> speedLimit >> multi) {

		userMonth = month - 1;

		if ((year > 0) && (year < 100)) {
		
			year += 2000;

		}

//Switch statement is intended to correlate the user's input and calculate the fine ammount with the input file and stored data (multipliers).

		switch (multi) {

			case 'r': case 'R':
				fineAmount = (clockedSpeed - speedLimit) * residentMulti;
				break;

			case 'h': case 'H':
				fineAmount = (clockedSpeed - speedLimit) * highwayMulti;
				break;

			case 'i': case 'I':
				fineAmount = (clockedSpeed - speedLimit) * interstateMulti;
				break;

			default:
				fineAmount = (clockedSpeed - speedLimit) * miscMulti;
				break;

		}


//The string of if/else statements below are intended to use the user's month, day, and year and loop around to see which citation fits the range of values given. Calculation will be made for the fine amount and the proper formatted output will give the citation number, specific date (m,d,y), and fine amount.

		if ((year > year1) && (year > year2)) {

			cout << left << setw(10) << setfill(' ') << citationNumber << right << setw(2) << setfill('0') << day << "-" << months[userMonth] << "-" << year << " " << left << setw(1) << setfill(' ') << "$" << right << setw(9) << fixed << setprecision(2) << fineAmount << endl;

		} else if (year == year1) {
				if ((month > month1)) {

				cout << left << setw(10) << setfill(' ') << citationNumber << right << setw(2) << setfill('0') << day << "-" << months[userMonth] << "-" << year << " " << left << setw(1) << setfill(' ') << "$" << right << setw(9) << fixed << setprecision(2) << fineAmount << endl;

			} else if (month == month1) {
				if (day > day1) {

					cout << left << setw(10) << setfill(' ') << citationNumber << right << setw(2) << setfill('0') << day << "-" << months[userMonth] << "-" << year << " " << left << setw(1) << setfill(' ') << "$" << right << setw(9) << fixed << setprecision(2) << fineAmount << endl;

				}
				
			} else if (month == month2) {
					if (day < day2) {

						cout << left << setw(10) << setfill(' ') << citationNumber << right << setw(2) << setfill('0') << day << "-" << year << " " << left << setw(1) << setfill(' ') << "$" << right << setw(9) << fixed << setprecision(2) << fineAmount << endl;
					
					}
					
				}

			} else if (year == year2) {
					if ((month < month1)) {

			cout << left << setw(10) << setfill(' ')<< citationNumber << right << setw(2) << setfill('0') << day << "-" << months[userMonth] << "-" << year << " " << left << setw(1) << setfill(' ') << "$" << right << setw(9) << fixed << setprecision(2) << fineAmount << endl;

		} else if (month == month1) {
			if (day > day1) {

				cout << left << setw(10) << setfill(' ') << citationNumber << right << setw(2) << setfill('0') << day << "-" << months[userMonth] << "-" << year << " " << left << setw(1) << setfill(' ') << "$" << right << setw(9) << fixed << setprecision(2) << fineAmount << endl;
			
				}

			} else if (month == month2) {
				if (day < day2) {

					cout << left << setw(10) << setfill(' ') << citationNumber << right << setw(2) << setfill('0') << day << "-" << months[userMonth] << "-" << year << " " << left << setw(1) << setfill(' ') << "$" << right << setw(9) << fixed << setprecision(2) << fineAmount << endl;

					}
				}
			}
		}
//Closes the fin function and returns to start.

	fin.close();
	return 0;

}



// Aaron Marshall, amarsh32, 000614990

// The objective for this program is to ask a sequences of specific questions that are stored as either
// strings or integers. These questions will be used to create the user's "Penname," new age, and address.
// Many of these new variables will use math like modulus, division, or multilicationk and other re-arrangement
// options to create descrete outputs for the user.



#include <iostream>


using namespace std;

int main () {
	
	//Stores the first two strings inputted as "firstName" and "middleName" variables

	string firstName;
	string middleName;

	cout << "Enter your first and middle names:";
	cin >> firstName >> middleName;

	//Stores the inputted integer as the "age" variable

	int age;

	cout << "Enter your age:";
	cin >> age;

	//Stores the input integer as the "streetNumber" and the last two string inputs as the "streetName"
	//and "streetType" variables

	int streetNumber;
	string streetName;
	string streetType;
	
	cout << "Enter your street number, name, and type:";
	cin >> streetNumber >> streetName >> streetType;

	//Stores the string input as the "cityName" variable

	string cityName;
	
	cout << "Enter your city of birth:";
	cin >> cityName;

	//The user's new age is calculated by finding the remainder of the streetNumber divided by 
	//the age and multiplying that by 3 in which it is stored in an integer variable named "newAge"

	int newAge = streetNumber % age;
	newAge = newAge * 3;

	//The user's new address is calculated by multiplying the age by 425 by which you divide by the 
	//streetNumber. This is all stored in a new integer variables named "newStreetNumber"
	
	int newStreetNumber = age * 425;
	newStreetNumber = newStreetNumber / streetNumber;
	
	//This variable helps to give spacing between variabled outputs

	string space = " ";
	
	//Once the user inputted all inquiries, the outputs are calculated and put in their designated spots.

	cout << space << endl;
	cout << "Your penname name is " << cityName << space << streetName << "." <<  endl;
	cout << "You will write as a " << newAge << " year old." << endl;
	cout << "Your address is " << newStreetNumber << space << middleName << space << streetType << "." << endl;

	return 0;

}



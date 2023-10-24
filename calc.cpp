/* Program Name: calc.cpp
 * Student Name: Aaron Marshall
 * Net ID: amarsh32
 * Student ID: 000614990
 * Program Description: The program is designed to be a virtual calculator allowing the user to input two operands and an operation giving the user the correct output. */

#include <iostream>
#include <iomanip>
#include <ios>
#include <limits>
using namespace std;


int main() {

// two integers are declared for the left and right operand. a character is declared for the operator

	int opL, opR;
	char op;

// The cin.clear() and cin.ignore() statements are intended to help clear error flags interpreting the input
// by removing contents that could have caused the read failure. This is done with an if statement stating if either the left/right operand or operation is not equal to the set parameters, then it will default with an error code statment. 

	cout << "Enter left operand: ";
	if (!(cin >> opL)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << " Invalid left operand. " << endl;
		return 1;
	}

	cout << "Enter operation: ";
	if (!(cin >> op)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << " Unkown operation. " << endl;
		return 1;
	}

// The first if statement seen below is intended to target the absolute value case. This means that if the input value is not equal to any of the provided absolute value characters, then proceed per usual, otherwise loop through the switch statement following the absolute value parameters.

	if (!(op == 'b' || op == 'B' || op == '|')) {
	cout << "Enter right operand: ";
	if (!(cin >> opR)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << " Invalid right operand. " << endl;
		return 1;
		}
	}

// The switch statement below is intended to interpret the inteded operator input and loop through to find the correct character correlating with the right math operation. Once found, the statment will calculate it and give the proper output. If no proper operation is found with the input, it will default to an error statement.

	switch(op) {
	
		case 'a': case 'A': case '+':
			cout << " Result = " <<  opL + opR << endl;
			break;

		case 's': case 'S': case '-':
			cout << " Result = " <<  opL - opR << endl;
			break;

		case 'm': case 'M': case 'x': case '*':
			cout << " Result = " << opL * opR << endl;
			break;

		case 'd': case 'D': case '/':
			cout << " Result = " << opL / opR << endl;
			break;

// The use of the if/else statement below is the correct way to calculate the absolute value of an input without using a specific math function. If the left operand input is less than zero, the input is multiplied by negative one inadvertently making it a positive value, otherwise it will just be multiplied by one also leaving it positive.

		case 'b': case 'B': case '|':
			if (opL < 0) {
				opL = (-1) * opL;
			} else {
				opL  = (1) * opL;
			}
			cout << " Result = " << opL << endl;
			break;

		case 'c': case 'C': case '%':
			cout << " Result = " << opL % opR << endl;
			break;

		default:
			cout << " Unknown operation. " << endl;
			break;

	}
	
	return 0;
}

/*
Name: Aaron Marshall
NetID: amarsh32
Program Description: The purpose of this program is to read five integers from a standard input given by the user and output a "checkerboard" based on the parameters specified.
 *
 * */


#include <iostream>
#include <string> 

using namespace std;

int main () {

/* 
 Variables below are declared to parse from the parameters including row, column, character, set size, etc.

 Set character is set as a character since it is a letter
 * */

	int R, C, CS, W;
	char SC;

	cin >> R >> C >> SC >> CS >> W;

//First loop goes through each row

	for (int r = 0; r < R; ++r) {

//Second loop printing the width of each character

		for (int i = 0; i < W; ++i) {

//Third loop goes through each column

			for (int c = 0; c < C; ++c) { 
			
//Fourth loop is printing the width of each character once more				

				for (int j = 0; j < W; ++j) {

//In correlation, the loops and cout statement are used to help get the proper position 
//The character is calulated by adding the starting character (SC) and the result of (r + c) % CS.

					cout << char(SC + (r + c) % CS);

				}

			}
			

			cout << endl;
		}

	}

	return 0;

}

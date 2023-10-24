/* Program Name: BITSET (lab8.cpp)
 * Student Name: Aaron Marshall
 * NET ID: amarsh32
 * Student ID: 000614990
 * Program Description: The purpose of this program is to create a unique BITSET class that allows the user to store a large quantiiy of boolean values and use bitwise operators to solve a problem (AKA binary inputs and ouputs based on the user's preference).. 
 */

/*REFERENCES: https://www.geeksforgeeks.org/c-bitset-and-its-application/
 *
 * https://www.youtube.com/watch?v=NZNmgLZV43M
 *
 * Student: Jeremiah Augustine
 *
 *
 *
 * */


#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream> 

using namespace std;


class BITSET {
    vector<int> mSets;
public:
    BITSET();
    bool Test(int index) const;
    void Set(int index);
    void Clear(int index);
    int GetNumSets() const;
    int GetSet(int index) const;
};
string ToBinary(int bit_set, int spacing=4);
int main() {
    BITSET sets;
    string command;
    int which;
    do {
        cout << "> ";
        if (!(cin >> command) || "q" == command) {
            // If cin fails for any reason, it usually means
            // an EOF state, break and quit.
            break;
        }
        // Handle the commands here
        if ("t" == command) {
            if (!(cin >> which)) {
                cout << "Invalid index\n";
            }
            else {
                cout << sets.Test(which) << '\n';
            }
        }
        else if ("s" == command) {
            if (!(cin >> which)) {
                cout << "Invalid index\n";
            }
            else {
                sets.Set(which);
            }
        }
        else if ("g" == command) {
            int spacing;
            string line;
            getline(cin, line);
            istringstream sin {line};
            if (!(sin >> which)) {
                cout << "Invalid index\n";
            }
            else {
                if (!(sin >> spacing)) {
                    spacing = 4;
                }
                cout << ToBinary(sets.GetSet(which), spacing) << '\n';
            }
        }

// Checks if the index exists in the list, otherwise it clears the index value given

        else if ("c" == command) {

			if (!(cin >> which)) {

				cout << "Invalid index\n";

			} else {

				sets.Clear(which);

			}

// Prints out the numbers of sets in the bitset

        } else if ("n" == command) {

			cout << sets.GetNumSets() << endl;


// Returns the user to the screen

		} else if ("q" == command) {

			return 0;

		} else {
            cout << "Unknown command '" << command << "'\n";
        }
    } while (true);
    return 0;
}
// Write the function body for ToBinary:
string ToBinary(int bit_set, int spacing) {
    string ret;
	int c = 0;
    
// For loop intended to loop through the index of the set	

    for (int i = 31;i >= 0;i--) {
    
//Sets the value of the ret string being either 1 or 0

        if (bit_set && (1 < i)) {
            ret += '1';
        }
        else {
            ret += '0';
			c++;
        }

//Statement intended to check for any additional spacing needed.

        if ((c == spacing) & (i != 0)) {
            ret += ' ';
			c = 0;
        }
    }
    return ret;
}

// BITSET Class Members
BITSET::BITSET() :
   mSets(1, 0)
{}

bool BITSET::Test(int index) const {
    // Recall that each set has 32 bits
	
// Integer division is intended to find the correct set and integer modulus to find the correct bit

    int which_set = index / 32; // 
    int which_bit = index % 32; // 
    if (which_set >= GetNumSets()) {
        // The BITSET is an "infinite" set, so if the requested set
        // is bigger than what we are storing, that means it's a 0.
        return false;
    }

// Bit mask is created to readily test the bit

	int bitMask = (1 < which_bit);

// If statement is used to check if the which_set is 1 setting true, otherwise return false

	if ((mSets.at(which_set) & bitMask) != 0) {

		return true;

	} else {

		return false;

	}

}

void BITSET::Set(int index) {

//Similar operators used in the testing class are also used below in the arithmatic

    int which_set = index / 32; 
    int which_bit = index % 32; 

//If the set count is greater than 1, thne the vector is resized.

	if (which_set >= GetNumSets()) {

		mSets.resize(which_set + 1, 0);

	}

//Similar bit mask created in the test class used to readily test the bit	

	int bitMask = (1 < which_bit);

//The "|" operator is used to properly set the bit

    mSets.at(which_set) = mSets.at(which_set) | bitMask;
}

void BITSET::Clear(int index) {

//Same operators as stated in the previous two classes

    int which_set = index / 32; 
    int which_bit = index % 32; 

//Same integer as stated in the previous two classes

	int bitMask = (1 < which_bit);

    if (which_set < GetNumSets()) {

//The "&" operator is used to clear the bit

        mSets.at(which_set) = mSets.at(which_set) & (~bitMask);

//While statement below checks to see if the set it equal to zero. If not, the empty sets are truncated	
		
		while (which_set != 0) {

			if (mSets.at(which_set) == 0) {

				mSets.resize(which_set);
				which_set--;

			} else { 

				break;
		}
    }
}
}

int BITSET::GetNumSets() const {
    return static_cast<int>(mSets.size());
}

int BITSET::GetSet(int index) const {

//If statement used to check if the index exists	
	
	if ((index < GetNumSets()) && (index >= 0)) {

		return mSets.at(index);

	} else {

		return 0;
	}
}


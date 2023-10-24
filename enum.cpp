/*
 * Name: Aaron Marshall
 * USERID: amarsh32
 * Program Description: This C++ program generates all possible binary strings of a given length and number of ones. The program takes two command line arguments: the first is the length of the string and the second is the number of ones to be included in the string. It then recursively generates all possible binary strings that satisfy these conditions and outputs them to the console.
 */

#include <iostream>
#include <string>

using namespace std;

void do_enumeration_helper(string &s, size_t index, int ones_remaining, int zeros_remaining) {
    // Base case: if all characters have been filled, output the string and return
    if (index == s.size()) {
        cout << s << endl;
        return;
    }

    // Recursive case 1: try filling the current position with a zero
    if (zeros_remaining > 0) {
        s[index] = '0';
        do_enumeration_helper(s, index + 1, ones_remaining, zeros_remaining - 1);
    }

    // Recursive case 2: try filling the current position with a one
    if (ones_remaining > 0) {
        s[index] = '1';
        do_enumeration_helper(s, index + 1, ones_remaining - 1, zeros_remaining);
    }
}

void do_enumeration(string &s, int index, int n_ones) {
    int n_zeros = s.size() - n_ones;
    do_enumeration_helper(s, index, n_ones, n_zeros);
}

int main(int argc, char *argv[]) {
    // Check that the correct number of command line arguments have been provided
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " length ones" << endl;
        return 1;
    }

    // Parse command line arguments
    int length = stoi(argv[1]);
    int ones = stoi(argv[2]);

    // Check that the input is valid
    if (length < 0 || ones < 0 || ones > length) {
        cerr << "Invalid input. Please make sure the 'length' is non-negative and 'ones' is between 0 and 'length'." << endl;
        return 1;
    }

    // Generate all possible binary strings and output them to the console
    string s(length, '-');
    do_enumeration(s, 0, ones);

    return 0;
}


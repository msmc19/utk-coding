/*
Name: Aaron Marshall
NetID: amarsh32
Program Description: The purpose of this program is to read from a standard input  with different given strings and integers. Parameters are given and used to parse through to give a name, and the students score (including the average if need).

REFERENCES: Jeremiah Augustine


 */


#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int main() {

//Each initilized varible is used to store 'name', 'score', 'temp numbers', and 'line'

  string name;
  double score = 0.0;
  double temp;
  string line;

//Read each line of the input using 'getline'

  while (getline(cin, line)) {

//Stringstream help to parse and initilizing a string 'word' to store each word in the line

    stringstream ss(line);
    string word;

//Read each word in the line 

    while (ss >> word) {

//Check if the first character of the word is an alphabetical character 

      if (isalpha(word[0])) {

//If the word is "NAME", set 'name to the next word in the line

        if (word == "NAME") {
          ss >> name;
        }

//If the word is "AVERAGE", add all the remaining numbers into the line to 'score'

      } else if (word == "AVERAGE") {

        while (ss >> temp) {
          score += temp;
        }

//If the word is a number, add it to 'score'

      } else if (!ss.fail()) {
		 score += stod(word);

      }
    }
  }

//If 'name' is empty then output 'score', otherwise output 'name' and 'score'

  if (name.empty()) {
    cout << score << endl;

  } else {
    cout << name << " " << score << endl;

  }

  return 0;
}


/* Program Name: Multi-User Dungeons (mud.cpp)
 * Student Name: Aaron Marshall
 * NET ID: amarsh32
 * Student ID: 000614990
 * Program Description: The purpose of this program is to act as a "multi-user dungeon" text-based game that reads from a single file containing variables needed for each room. The user will be prompted with different commands used to navigate through the different rooms specified in the file given by the user. In addition, the file will dynamically allocate memory to allow for the file to have flexibility based on its specifications.
 */

/* REFERENCES:

https://www.guru99.com/cpp-pointers.html

Pointers help ^^^

https://en.cppreference.com/w/cpp/types/numeric_limits

Limits help ^^^

https://github.com/nickgammon/tinymudserver
https://www.youtube.com/watch?v=Eb1Q98PmyLQ

General understand for starting the program ^^^^



*/


#include <iostream>
#include <sstream>
#include <limits>
#include <string>
#include <fstream>
using namespace std;

/*struct crated to store the room data */

struct allRooms {

	int north = -1;
	int south = -1;
	int east = -1;
	int west = -1;
	string description;
	string name;
	string exitRoom;

};

/*This dungeon class is used to properly execute different methods of input reads  */

class startDungeon {

	public:

/*Pointer used for allocation */

		allRooms *r;

/*Function created to find the number of rooms there are in any file and return it */

		int getRoomNumber (ifstream& in) {
			
			string line;
			int roomNumber;
			int count;

			while (getline(in, line)) {
			
				if (line[0] == '~') {

					count++;
					continue;

				}
		
			}

			roomNumber = (count/3);
			return roomNumber;

		};

/*boolean function intended to read the data by using stringstream */

		bool read_input (ifstream& in, int& numberRoom) {

/*The pointer is initialized to be used for file read */
			
			r = new allRooms[numberRoom];
			stringstream ss;
			string line;

/*For loop to run through the descriptions and names */

			for (int i = 0; i < numberRoom; i++) {

				getline(in, line);
				r[i].name = line;
				getline(in, line);
				
				while (getline(in, line)) {

					if (line == "~") {

						break;
					}

					r[i].description += line;
					r[i].description += "\n";

				}

/*While loop checks and looks for the numerical value that corresponds with the exit cardinal and stores it
 * as that value by checking for the first character of each line*/				
						
				while (getline(in, line)) {

					if (line == "~") {

						break;

					}

					ss.clear();
					ss << line;

					if (line[0] == 'n') {
					
						ss >> r[i].exitRoom >> r[i].north;

					}

					if (line[0] == 's') {

                        ss >> r[i].exitRoom >> r[i].south;

                    }

					if (line[0] == 'e') {

                        ss >> r[i].exitRoom >> r[i].east;

                    }

					if (line[0] == 'w') {

                        ss >> r[i].exitRoom >> r[i].west;

                    }


				}


			}

			return true;

		}

};


int main (int argc, char** argv) {

/*Varibles needed for file stream, room number, and user input */

	ifstream fin;
	ofstream fout;

	if (argc > 1) {

		std::string arg1(argv[1]);

	}

	startDungeon mainDungeon;

	char userString;
	int roomNumber;
	int currentRoom = 0;

/*Error checking */

	fin.open(argv[1]);
	if (!(fin.is_open())) {

		cout << "Cannot open file. \n";
		return 1;

	}

	roomNumber = mainDungeon.getRoomNumber(fin);
	fin.close();

	fin.open(argv[1]);
	mainDungeon.read_input(fin, roomNumber);
	fin.close();

/*While loop is intended to check for user input */

	while (true) {

		cout << "> ";
		cin >> userString;

/* The "q" character is intended to exit the user and delete the pointers with it */

		if (userString == 'q') {

			delete[] mainDungeon.r;
			return 0;

		}

/*The "l" character intends to print all the (availiable) rooms, name, and description depiected in the file */

		if (userString == 'l') {

			cout << mainDungeon.r[currentRoom].name << endl;
			cout << mainDungeon.r[currentRoom].description << endl << "Exits:";

			if (mainDungeon.r[currentRoom].north != -1) {
				
				cout << " n";

			}

			if (mainDungeon.r[currentRoom].south != -1) {

                cout << " s";

			}

			if (mainDungeon.r[currentRoom].east != -1) {

                cout << " e";

			}

			if (mainDungeon.r[currentRoom].west != -1) {

                cout << " w";

			}
			
			cout << endl;

		}

/*The list of if/else statements error checks the user's input based on the pointer given with the file reads
 * If the user moves a specific direction, the pointer will update and the statement will output a statement/update
 * based on the given character*/

		if (userString == 'n') {
			
			if (mainDungeon.r[currentRoom].north == -1) {

				cout << "You can't go NORTH!\n";

			} else {

				currentRoom = mainDungeon.r[currentRoom].north;
				cout << "You moved NORTH\n";

			}

		}

		if (userString == 's') {

            if (mainDungeon.r[currentRoom].south == -1) {

                cout << "You can't go SOUTH!\n";

            } else {

				currentRoom = mainDungeon.r[currentRoom].north;
				cout << "You moved SOUTH\n";

            }

        }

		if (userString == 'e') {

            if (mainDungeon.r[currentRoom].east == -1) {

                cout << "You can't go EAST!\n";

            } else {

                currentRoom = mainDungeon.r[currentRoom].east;
                cout << "You moved EAST\n";

            }

        }

		if (userString == 'w') {

            if (mainDungeon.r[currentRoom].west == -1) {

                cout << "You can't go WEST!\n";

            } else {

                currentRoom = mainDungeon.r[currentRoom].west;
                cout << "You moved WEST\n";

            }

        }

/*Input cleared and character limit ignore to void parse failure */

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}

	return 0;

}

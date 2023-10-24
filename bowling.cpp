/* Program Name: Bowling Score Calculator (bowling.cpp)
 * Student Name: Aaron Marshall
 * NET ID: amarsh32
 * Student ID: 000614990
 * Program Description: The purpose of this program is to tally up the scores of two seperate players and calculate their totals based on their rolls and bowling rules (strike's, spare's, etc.). In addition, you will be outputing the worst and best player to find out who won and lost. 
 */



/*
 *References:

https://stackoverflow.com/questions/1430757/convert-a-vectorint-to-a-string (Intended for converting the vector string to string variables and looping it to output the user's scores).
			
		    	
https://cplusplus.com/forum/beginner/198279/ (Jumpstarted how to create the if/else and loops for the bowling and how to set it up) (Lines 103 - 138 were made with the help of this forum).

https://stackoverflow.com/questions/12811715/bowling-score-calculator-in-c (Additional reference for how I was able to set up my if/else and for loops for strikes and spares).


https://www.myactivesg.com/sports/bowling/how-to-play/bowling-rules/how-are-points-determined-in-bowling#:~:text=The%20more%20pins%20you%20knock,strikes%E2%80%9D%20or%20%E2%80%9Cspares%E2%80%9D. (More scoring information)
 

https://bowl.com/welcome/keeping-score-7c992ab8f438aa57fac9f9aef753ae44 (More scoring information)


 * */




#include <iostream>
#include <iomanip>
#include <vector>
#include <string>


using namespace std;


int main() {

/*Necessary vectors used to stores the player names, frame scores (calculated), and the player scores (after calculation).*/

	vector <string> pNames;
	vector <int> fScores;
	vector <int> pScores;

	string inputName;

/* Important integers for the totals rolls, real time roll value/frame, frame scores, input scores etc. */
	
	int tRolls[22];
	int roll;
	int frame;
	int fScore;
	int p, t, k;
	int i = 0;
	int total;
	int inputScore;
	int betterP, worstP;


/* The while loop checks for the given name by the user. If the user inputs "done" then they will be prompted with no players being entered */

	while (true) {


		cout << "Enter player's name (done for no more players): ";

		cin >> inputName;
		
		
        if (inputName == "done") {

            if (pNames.empty()) {

                cout << "No players were entered.";

                return 1;

            }

            break;

        }

/* Any names given are put into the pNames vector to be stored */

		pNames.push_back(inputName);
		

/* The for loop below is used to check for the user's input score and loop around to give a new and updated frame based on the user's given value. */


		roll = 1;

		frame = 1;


		for (int i = 1; i < 21; i++) {

			tRolls[21] = {0};

			cout << "Enter score for frame " << frame << ", roll " << roll << ": ";
			
			cin >> inputScore;
			
			tRolls[i] = inputScore;
			
/* This if statement below is used to output what the user will see if they make a "strike" between frames 1-10. The roll value is automatically set back to 1 as a "strike" gives you 1 roll from frames 1-10 */

		if (inputScore == 10) {

			if (frame < 10) {

				if (i % 2 == 1) {

					i++;

			}

				++frame;

				roll = 1;

			} else { 

				roll = 2;

				}

			} else {
				
				if (i % 2 == 1) {

				roll = 2;

			} else {

				++frame;

				roll = 1;
			}

		}

	}


/* Based on the rules given by bowling, reguardless of the score at frame time, you will be given 3 possible rolls in the end. This if statements allows to display roll 1-3 while tallying the score. */

		if (tRolls[19] + tRolls[20] >= 10) {

			roll = 3;

			frame = 10;

			cout << "Enter score for frame " << frame << ", roll " << roll << ": ";

			cin >> inputScore;

			tRolls[21] = inputScore;

		}

/*  This is the first part of the calculation based on the input of the user. This is done by taking the tota rolls value, which has the input value by the user, and properly tally up the frame score based on if the user got a "strike" */




		for (int i = 1;i < 19;i += 2) {

			 fScore = 0;

			if (tRolls[i] == 10) {

				fScore += 10;;

// This if statement blow is the "strike" aspect if the user inputs a 10, then add 10 to the frame value and go on to the next frame.

				if (tRolls[i + 2] == 10) {

					fScore += 10;

// This if statement checks if the roll is before the 10th frame, if it as the 10th frame, you can still roll 3 total times and add them all up. If it isn't a 10, then the values given will still be added up.

					if (i < 17) {

						fScore += tRolls[i + 2 + 2];


					} else {

						fScore += tRolls[20];

					}

				} else {

					fScore += tRolls[i + 3] + tRolls[i + 2];

				}

/* This is the else/if statement used to calculate the frame value if the user scores a "spare" being the two roll values adding up to 10. This is allows the user to go through the frame, roll twice, score 10 and it be added up. */

			} else if (tRolls[i] + tRolls[i + 1] == 10) {
								
				fScore += 10;

				fScore += tRolls[i + 2];

			} else {

				fScore = tRolls[i] + tRolls[i + 1];

			}
// Frame score integer calculated is then thrown into the frame scores vector.

			fScores.push_back(fScore);

		}

// This if statement is the scoring or the last the frames if the user ends up rolling a 10 in those frames.

		if (tRolls[19] == 10) {

			fScores.push_back(10 + tRolls[20] + tRolls[21]);

		} else if (tRolls[19] + tRolls[20] == 10) {
	
			fScores.push_back(tRolls[21] + 10);
			
		} else {

			fScores.push_back(tRolls[19] + tRolls[20]);

		}

// The total score from the frame vector is set to integer t and then put into the scores vector.

		total = 0;

		for (int t: fScores) {

			total += t;
			
		}

		pScores.push_back(total);

/* The frame scores vector is cleared and looped around to allow for a new player name and frame scores to be calculated and storee */

		fScores.clear();
	

	}


			worstP = 0;

			betterP = 0;

			p = 0;	

/* A string variables allPlayers is set to the pNames vector to allow for the scores and names be displayed */			

			for (string allPlayers: pNames) {

				cout << allPlayers << " scored " << pScores.at(p) << endl;

				++p;		
			}
				


				betterP = 0;

				worstP = 0;

/* To be able to find the min and max values, and if/else statement loops around to find the index for the minimum and maximum in the scores vector */

			for (int i = 0; i < pScores.size(); i++) {

				if (pScores[i] < worstP) {

					worstP = pScores[i];


				} else if (pScores[i] > betterP) {

					betterP = pScores[i];

				}
				
			}

				cout << pNames[betterP] << " did the worst by scoring " << worstP << endl;
				cout << pNames[worstP] << " won the game by scoring " << betterP << endl;

}


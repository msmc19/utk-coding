/* Mini Golf Program 
   Will take in scores from 2 players in mini golf
   THIS IS WHERE WE FINISHED CLASS on 9/1
   */

#include <iostream>
#include <vector>
using namespace std;

int main() {
   string name1, name2;
   int numOfHoles = 3;
   int data;
   int p1holes = 0;
   int p2holes = 0;
   
   /* Read in player names from the user */
   cout << "Please enter Player 1's name: ";
   cin >> name1;
   cout << "You entered: " << name1 << endl;

   cout << "Please enter Player 2's name: ";
   cin >> name2;
   cout << "You entered: " << name2 << endl;
   
   /* Store and sum up the scores from each hole */
   for (int i = 0; i < numOfHoles; i++) {
      cout << "Please enter " << name1 << "'s score for hole " << i + 1 << ": ";
      cin >> data;
      p1holes += data; 

      cout << "Please enter " << name2 << "'s score for hole " << i + 1 << ": ";
      cin >> data;
      p2holes += data;
   }

   /* Print final scores for each player */
   cout << "Player 1 (" << name1 << ") scored a " << p1holes << "." << endl;
   cout << "Player 2 (" << name2 << ") scored a " << p2holes << "." << endl;

   /* Reveal the winner of the game */
   if (p1holes < p2holes) { 
      cout << "Congrats " << name1 << " - you won the game!" << endl; 
   }
   else if (p1holes == p2holes) {
      cout << "Tied game!" << endl;
   }
   else {
      cout << "Congrats " << name2 << " - you won the game!" << endl;
      printf("Final score %d - you won the game", p2holes); // c function
   }

}

//262095
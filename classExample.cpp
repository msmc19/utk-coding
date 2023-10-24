#include <iostream>
using namespace std;

class Marathon {
    private:
        string totalTime; //unused - come back to this when we learn string streams

    public:
       int hours;
       int minutes;
       Marathon(int h, int m);
       void printTotalTime(); 
};

Marathon::Marathon(int h, int m) {
    hours = h;
    minutes = m;
}

void Marathon::printTotalTime() {
    cout << hours << ":" << minutes << endl;
}

struct Location { 
    // A struct in C can hold just attributes, but in C++ it's basically the same as a class but it's public by default
    string city;
    string state;
};

int main() {
    Marathon boston(3, 30);        // boston is an instance of the class Marathon
    Location raceLocation;

    //boston.hours = 3;       // I am able to use the dot operator to access hours
    //boston.minutes = 30;    // and minutes because those attributes are public
    raceLocation.city = "Boston";
    raceLocation.state = "MA";

    boston.printTotalTime();
    cout << raceLocation.city << ", " << raceLocation.state << endl;
}





//666446

//1. In C++, a class is 
   // a. public
   // b. private <-
   // by default.

//2. In C++, you can wrap cin inside an if statement or a while loop (as the boolean it tests)
   // a. true
   // b. false

//3. cin.clear()
   // a. clears the input stream
   // b. clears the cin error flag <-

//4. attendance
/* Error checking with integers
.good(), .fail() are good to use
.eof() is tricky

1. Wrapping cin inside an while loop or an if statement - we want a true/false on if cin worked
2. If it failed, we 
   2a. clear the state of cin
   2b. ignore the input
3. (Optional) We ask again. We can ask again repeatedly if we ask inside a while loop made in #1.
*/
#include <iostream>
#include <limits> // This is important!
using namespace std;

int main() {
    cout << "Enter two integers: " << endl;
    int input1, input2;
    cin >> input1;
    cin >> input2;

    while (!cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        //ask again
        cout << "FAILED" << endl;
        cout << "Enter two integers: " << endl;
        cin >> input1;
        cin >> input2;
    }

    cout << "You entered " << input1 << " " << input2 << endl;
}
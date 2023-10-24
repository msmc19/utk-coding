/* Error checking 
   Read in doubles, and if the user types in something other than
   a double, refuse that entry. 
   REMEMBER: 3, 4, 10, etc ARE doubles. Whole numbers are stored as 3.0, 4.0 ...
   Errors will look like: blah, hello, garbage, dog, adgag */

#include <iostream>
#include <limits>
using namespace std;

void ignoreLine()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //(number of characters to ignore (X), exactraction operator)
    //we ignore X number of characters or until we see the exactraction operator
}


int main() {

    while (true) // Loop until user enters a valid input
    {
        cout << "Enter a double value: ";
        double x, y;
        cin >> x;

        if (!cin) // has a previous extraction failed?
        {
            // yep, so let's handle the failure
            cin.clear(); // put us back in 'normal' operation mode
            ignoreLine(); // and remove the bad input
            cout << "Fail" << endl;
        }
        else // else our extraction succeeded
        {
            ignoreLine();
            cout << x << endl; // so return the value we extracted
            break;
        }
    }
}
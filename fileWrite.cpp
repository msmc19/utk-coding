/* Basic File Output - Example is Printing to a File
Reading in Files / Writing to Files - Using File Streams
1. Include <fstream> header file
2. Declare a file variable (ifstream for reading - stands for input file stream) (ofstream for writing - output file stream)
   and name it (typically fin, fout)
3. 3a. Open the file connecting the variable to the actual file and 3b. check for failure to open (input reading).
4. Do the work on the intended file (either read from the file or write to the file) using <<, >>
5. Close the file.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ofstream fout;
    fout.open("myOutput.txt"); // creates OR overwrites myOutput.txt

    string s1 = "Beat Florida\n";
    string s2 = "Rocky Top, TN\n";
    double a = 10.555555;

    fout << s1;
    fout << s2;
    fout << left << fixed << setprecision(2) << setw(5) << a;

    fout.close();
}
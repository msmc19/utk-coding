/* Basic File Reading - Example is Reading from a File
Reading in Files / Writing to Files - Using File Streams
1. Include <fstream> header file
2. Declare a file variable (ifstream for reading - stands for input file stream) (ofstream for writing - output file stream)
   and name it (typically fin, fout)
3. 3a. Open the file connecting the variable to the actual file and 3b. check for failure to open.
4. Do the work on the intended file (either read from the file or write to the file) using <<, >>
5. Close the file.
*/
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin;
    int a, b, c;
    string filename = "FR1.txt";
    fin.open(filename); // This creates the stream of information between our program and the file. Only time we need the file/path info
    if (!fin.is_open()) { // fin.fail() could also error check. Failure reasons: doesn't exist, OR we don't have permission
        cout << "Could not open FR1.txt" << endl;
        return 1;
    }
    //fin >> a >> b >> c;

    //getline(STREAM, STRING); other streams cin, string stream ( will learn later); here we are using a file stream
    string line, line2;
    getline(fin, line); // this will place 3 10 15 in a string (that string is line)
    cout << line << endl;

    getline(fin, line2);
    cout << line2 << endl;

    fin.close();  // .open is the link b/t my program and the file, .close de-links

    //cout << "Verifying the integers read in: " << endl;
    //cout << a << " " << b << " " << c;


}
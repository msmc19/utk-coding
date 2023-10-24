/* String Streams Notes

   The string stream class is used for insertion and extraction of
   data to/from strings. It acts as a stream for the string object.

   Similar to cin/cout, fin/fout.
   The stream is just from a different source.
   Source for cin/cout - console
   Source for fin/fout - file
   Source for sin/sout - string

   Program will take 3 arguments on the command line:
   1. Program name (the executable)
   2. Input file (racetimeHMS.txt)
   3. Output file (a new file, but we give it a name here)

    
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;


/* Returns the marathon time as a string in HH:MM:SS format */
string formatTime(int h, int m, int s) {
  ostringstream sout;
  sout << setfill('0') << h << ":" << setw(2) << m << ":" << setw(2) << s;
  return sout.str();

}

/* Returns a pace in MM:SS format. Using calculate pace formula from a few weeks ago. */
string calcPace(int h, int m, int s) {
   ostringstream sout;
   
   double marathonDist = 26.2;
   int totalSeconds = (m * 60) + (h * 60 * 60) + s;

   double paceInSeconds = (totalSeconds / marathonDist);
   int pMin = (int) (paceInSeconds / 60);
   int pSec = ( ((int) (paceInSeconds + 0.5)) % 60);

   sout << setfill('0') << setw(2) << pMin << ":" << setw(2) << pSec;
   return sout.str();
}

int main(int argc, char **argv) {
   ifstream fin;
   ofstream fout;
   string fname, lname, time, pace, inputFile, outputFile;
   int hrs, mins, secs;

   if (argc != 3) {
     cerr << "usage: ./rt3 inputFilename.txt outputFilename.txt\n";
     return 1;
   }

   inputFile = argv[1];
   outputFile = argv[2];
   
   /* Connecting the file input stream with the file
      and making sure it opens correctly */   
  
   fin.open(inputFile);
   if (!fin.is_open()) {
      cerr << "Could not open file. Check permissions or filename.\n";
      return 1;
   } 

   fout.open(outputFile);
   /* Create a output file to place the newly formatted data */
   while (fin >> fname >> lname >> hrs >> mins >> secs) {
      fout << fname << " " << lname << endl;
      
      time = formatTime(hrs, mins, secs);
      fout << "  Marathon Time: " << time << endl;
      fout << "  Average Pace: " << calcPace(hrs, mins, secs) << endl;
   }
   fin.close();
   fout.close();
   return 0;
}














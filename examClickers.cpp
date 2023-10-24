/* EXAM CLICKERS */


1. Write the command to open a new file called lab1.cpp in vim 
	- vim (or vi) lab1.cpp


2. What is the VIM command to edit a file when you are currently in normal mode? 
(i.e. what key must I press?)
	- i

3. I want to remotely login to the Hydra 22 machine. My netID is bcox5. What is the command I type in a terminal window to remotely login?
	- ssh bcox5@hydra22.eecs.utk.edu

4. What is the command to copy a file from the hydra/tesla machines to your own computer?
(just the three letter unix command)
	- scp

5. What library must I #include to use setw()?
	- iomanip

6. OStringstream variable called out
   Inside a function:

    sout << a << " " << b < "," << c;

    How do you return the string created by the stream?

   	- return sout.str();

7. Inside a function called formatTime min=3 and seconds=2 03:02
MM:SS - left, right, scientific, fixed, endl, setfill(), showpoint, setw(), setprecision(), hex, dec
sout << ____ << ____ << min << ":" << ____ << seconds

	- setfill('0'), setw(2), setw(2)

8. What header must you include to use filestream? #include <____>

	- fstream

9. T/F The following code snippet will compile.
int a = 0;
double b = 20.22;
char c - 'a';

printf("%5a %10.1b %10c", i, f, c); -----> Correct way: printf("%5d, %10.1f %10c", a, b, c);

	- F

10. How do you append an element called "data" to the end of a vector called "numbers"? vector <int> numbers; int data = 5;
numbers.____;
	
	- push_back(data)


11. Replace XXX with a way to check that the input file myfile.txt was opened correctly ifstream fin;
    ifstream fin;
    // code to open file
    if (XXX) {

	cout << "Could not open file myfile.txt\n";

    }

	- !fin.is_open()

12. Replace //code to open file
to read "myfile.txt" using file streams

	- fin.open("myfile.txt");

13. terminal: ./myprogram 1 2 3 4 5 

int main (int argc, char **argv[]) {

	cout << argc;
	return 0;

}
What is printed to the screen after the program executes?

	- 6


14. ./myProgram 15 data 20 data 1
Where is the argument '20' stored in the main function?

	- argv[3] 

15. What is the data type of the argument '20' store by the main function?
a. int
b. c-stye string <-----
c. array of c-style strings  
d. c++-style string



















int add (int a, int b);
int substract (int a, int b);

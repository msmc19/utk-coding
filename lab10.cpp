
/* Program Name: Vectors from Scratch (lab10.cpp)
 * Student Name: Aaron Marshall
 * NET ID: amarsh32
 * Student ID: 000614990
 * Program Description: The purpose of this program is to create a "vector" manually by creating a class with pointers and dynamic memory. 
 */

/* REFERENCES:

https://learn.microsoft.com/en-us/cpp/cpp/scope-resolution-operator?view=msvc-170

https://www.geeksforgeeks.org/scope-resolution-operator-in-c/

Scope operator use ^^^

https://www.quora.com/How-do-you-initialize-a-vector-to-null-in-C

https://www.freecodecamp.org/news/cpp-vector-how-to-initialize-a-vector-in-a-constructor/

https://www.geeksforgeeks.org/destructors-c/

https://cplusplus.com/reference/vector/vector/resize/

Additional links used to help make correct member fucntions ^^

*/



#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;

class doublevector {
     static constexpr double DOUBLE_DEFAULT_VALUE = -5.55;
     double *mValues;
     int mNumValues;
public:
     doublevector();
     ~doublevector();
     void resize(int new_size, double initial_value=DOUBLE_DEFAULT_VALUE);
     void push_back(double value);
     double &at(int index);
     const double &at(int index) const;
     unsigned long size() const;
};
void print_all(const doublevector &v)
{
     if (v.size() == 0) {
           cout << "Vector is empty.\n";
     }
     else {
          unsigned long i;
          for (i = 0;i < v.size();i++) {
                cout << "[" << setfill('0') << right << setw(3) << i
                     << "] = " << fixed << setprecision(4) << v.at(i)
                     << '\n';
          }
     }
}
int main()
{
      doublevector v;
      do {
           string command;
           cout << "Enter a command ('quit' to quit): ";
           if (!(cin >> command) || command == "quit") {
                break;
           }
           else if (command == "push_back") {
                double value;
                cin >> value;
                v.push_back(value);
		cout << "Pushed back "
		     << fixed << setprecision(4)
		     << value << '\n';
           }
           else if (command == "resize") {
                string line;
                int new_size;
                double initial;
                cin >> new_size;
                getline(cin, line);
                istringstream sin(line);

                if (sin >> initial)
                     v.resize(new_size, initial);
                else
                     v.resize(new_size);
           }
           else if (command == "size") {
                cout << v.size() << '\n';
           }
           else if (command == "print") {
                print_all(v);
           }
           else if (command == "get") {
                int index;
                cin >> index;
                try {
                     cout << "Value at " << index << " = "
		          << setprecision(4) << fixed
                          << v.at(index) << '\n';;
                }
                catch(out_of_range &err) {
                     cout << err.what() << '\n';
                }
           }
           else if (command == "set") {
		   double d;
		   int index;
                   cin >> index >> d;
                   try {
			v.at(index) = d;
                        cout << "SET: " << index << " = "
			     << setprecision(4) << fixed
                             << v.at(index) << '\n';;
                   }
                   catch(out_of_range &err) {
                        cout << err.what() << '\n';
                   }
           }
           else if (command == "clear") {
                v.resize(0);
           }
           else {
                cout << "Invalid command '" << command << "'\n";
           }
      } while(true);
      cout << endl;
      return 0;
}

//Write your class members below here.

/* The constructor below is created to initialize an empty vector "mValue" to nullptr and "mNumValues" to 0 */

doublevector::doublevector() : mNumValues(0) {

	mValues = nullptr;

}

/* The destructor below is used to release such allocated memory  */

doublevector::~doublevector() {

	if (mValues != nullptr) {

		delete[] mValues;
		mValues = nullptr;

	}

}


/* Member function intended to rezie the vector to "new_size" */

void doublevector::resize (int new_size, double initial_value) {

	if (new_size >= 0) {
		
		if (new_size == 0) {

/* If statement used to delete the exiting memory if an array is allocated */

			if (mValues != nullptr) {


				delete[] mValues;
				mValues = nullptr;

			}

			mNumValues = 0;

		} else if (new_size > mNumValues) {

/* A temporary pointer is allocated to an arrya of size "new_size" */

			double *tptr = new double[new_size];

/* For loop used to copy the mNumValues to the temporary pointer */

			for (int i = 0; i < mNumValues; i++) {

				tptr[i] = mValues[i];

			}

/* Another for loop is used to allocate the rest of the temporary pointer values to the initial_value  */

			for (int i = mNumValues; i < new_size; i++) {


				tptr[i] = initial_value;
			}

/* If statement used to check for mValued that are allocated using the delete function to release the memory */

			if (mValues != nullptr) {

				delete[] mValues;

			}
			
			mValues = tptr;
			mNumValues = new_size;

/* Similar functions used below to create and set values if the new_size if less than mNumValues  */

		} else if (new_size < mNumValues) {

			double *tptr = new double[new_size];

			for (int i = 0; i < new_size; i++) {


				tptr[i] = mValues[i];
			}

			if (mValues != nullptr) {


				delete[] mValues;
			}

			mValues = tptr;
			mNumValues = new_size;

		}

	}

}

/* Void function used to push_back the given value at the end of the vector */

void doublevector::push_back (double value) {

	resize (mNumValues + 1, value);

}

/* Double function used to return the value at the given index */

double& doublevector::at(int index) {

	if (index >= 0 && index <  mNumValues) {

		return mValues[index];

	} else {

		ostringstream sout;
		sout << "Invalid index #" << index;
		throw out_of_range(sout.str());
	
	}

}

/* Similiarly as the function above */

const double& doublevector::at(int index) const {

	if (index >= 0 && index < mNumValues) {

		return mValues[index];

	} else {

		ostringstream sout;
		sout << "Invalid index #" << index;
		throw out_of_range(sout.str());
	}	
}

/* Function used to return the number of elements in the vector */

unsigned long doublevector::size() const {

	return mNumValues;

}


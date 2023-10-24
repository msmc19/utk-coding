
/* Program Name: Vectors from Scratch (lab10.cpp)
 * Student Name: Aaron Marshall
 * NET ID: amarsh32
 * Student ID: 000614990
 * Program Description: The purpose of this program is to read in a picture file that is "text-based", manipulate it, then write such file to an output file.
 */

/* REFERENCES:

https://www.mygreatlearning.com/blog/file-handling-in-cpp/


*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Struct to hold the values for a single pixel

struct Pixel {

    int red;
    int green;
    int blue;
};

// Class to hold the picture

class Picture {

private:

// Private members to hold the picture data

    vector<Pixel> pixels;

    int width;
    int height;
    int max_intensity;

public:
    
// Constructor to initialize the data members to 0
    
	Picture() {

        width = 0;
        height = 0;
        max_intensity = 0;
    }

// Accessor to get a pixel at a given row and column
    
	Pixel get_pixel(int row, int column) const {

// Calculate the index of the pixel in the vector
        
		int index = row * width + column;
        
// Return the pixel at the given index

        return pixels[index];
    }

// Mutator to set the value of a pixel at a given row and column

void set_pixel(int row, int column, const Pixel& pixel) {

// Calculate the index of the pixel in the vector

        int index = row * width + column;

// Set the pixel at the given index to the given pixel

        pixels[index] = pixel;
    }

// Public members to access and set the picture data
	
 int get_width() const { return width; }
 int get_height() const { return height; }
 int get_max_intensity() const { return max_intensity; }

 void set_width(int w) { width = w; }
 void set_height(int h) { height = h; }
 void set_max_intensity(int m) { max_intensity = m; }

// Function to read the picture data from a PPM file
	
void read_picture(const string& file_name) {

// Open the input file stream

	   ifstream input_file(file_name);

// Check if the file was successfully opened

       if (!input_file.is_open()) {

// Print an error message and exit the function if the file could not be opened
            
			cout << "Error: could not open file " << file_name << endl;
            return;
        }

 // Read the first line of the file and check if it is "P3"
	
        string first_line;
        getline(input_file, first_line);

        if (first_line != "P3") {

 // Print an error message and exit the function if the first line is not "P3"
            
			cout << "Error: file is not a PPM file" << endl;
            return;
        }

// Read the second line of the file and extract the width and height
	
        string second_line;
        getline(input_file, second_line);
        sscanf(second_line.c_str(), "%d %d", &width, &height);

		int red;
		int green;
		int blue;
		
//Read the third line of the file and extrac the maximum intensity

		string third_line;
		getline(input_file, third_line);
		sscanf(third_line.c_str(), "%d", &max_intensity);

//Read the remaining lines of the file, which contain the pixel data

		for (int row = 0; row < height; row++) {

			for (int column = 0; columb < width; column++) {

				intput_file >> red >> green >> blue;

//Set the pixel at the given row and column

				set_pixel(row, column, Pixel(red, green,blue));

			}

		}

};


//Output of the width, height, and max intensity with given specifications and manipulations above

int main() {

	Picture picture;
	picture.read_picture("picture.ppm");

	cout << "Width: " << picture.get_width() << endl;
	cout<< "Height: " << picture.get_height() << endl;
	cout << "Max intensity: " << picture.get_max_intensity() << endl;
	

	return 0;
}
			

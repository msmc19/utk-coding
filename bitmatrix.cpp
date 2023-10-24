/*
 * Name: Aaron Marshall
 * USERID: amarsh32
 * Program Description: The purpose of this program is to create bit-matrices (values zero, one, and arithmetic modulo 2) These matricies are created and allowed to be used with different mathematical operation including the sum, product, sub_matrix, and inverse with the product given. 
 *
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "bitmatrix.hpp"
using namespace std;

// Bitmatrix constructor with dimensions
Bitmatrix::Bitmatrix(int rows, int cols) {
    // Validate dimensions
    if (rows <= 0 || cols <= 0) {
        throw string("Invalid matrix dimensions");
    }

    this->rows = rows;
    this->cols = cols;
    data.resize(rows, vector<bool>(cols, false));
}

// Bitmatrix constructor with file input
Bitmatrix::Bitmatrix(const string& filename) {
    // Open file for reading
    ifstream inFile(filename);

    // Validate file opened successfully
    if (!inFile.is_open()) {
        throw string("Unable to open file");
    }

    // Read rows and columns from file
    inFile >> rows >> cols;

    // Validate dimensions
    if (rows <= 0 || cols <= 0) {
        throw string("Invalid matrix dimensions");
    }

    // Resize data vector and initialize with false
    data.resize(rows, vector<bool>(cols, false));

    // Read data from file
    char ch;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            inFile >> ch;
            data[i][j] = ch - '0';
        }
    }

    // Close input file
    inFile.close();
}

// Bitmatrix destructor
Bitmatrix::~Bitmatrix() {}

// Getter functions
int Bitmatrix::Rows() const {
    return rows;
}

int Bitmatrix::Cols() const {
    return cols;
}

bool Bitmatrix::Val(int row, int col) const {
    // Validate index
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw string("Index out of bounds");
    }

    return data[row][col];
}

bool Bitmatrix::Set(int row, int col, char val) {
    // Validate index
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        return false;
    }

    // Set the value
    data[row][col] = (val == '1');
    return true;
}

bool Bitmatrix::Swap_Rows(int r1, int r2) {
    // Validate index
    if (r1 < 0 || r1 >= rows || r2 < 0 || r2 >= rows) {
        return false;
    }

    // Swap rows
    swap(data[r1], data[r2]);
    return true;
}

bool Bitmatrix::R1_Plus_Equals_R2(int r1, int r2) {
    // Validate index
    if (r1 < 0 || r1 >= rows || r2 < 0 || r2 >= rows) {
        return false;
    }

    // Perform row addition
    for (int j = 0; j < cols; ++j) {
        data[r1][j] ^= data[r2][j];
    }

    return true;
}

void Bitmatrix::Print(int w) const {
    // Print the matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << (data[i][j] ? '1' : '0');
            if (j + 1 < cols && (j + 1) % w == 0) {
                cout << ' ';
            }
        }
        cout << endl;
    }
}

bool Bitmatrix::Write(const string& filename) const {
    // Open file for writing
    ofstream outFile(filename);

    // Validate file opened successfully
    if (!outFile.is_open()) {
        return false;
    }

    // Write rows and columns to the file
    outFile << rows << " " << cols << endl;

    // Write data to the file
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            outFile << (data[i][j] ? '1' : '0');
        }
        outFile << '\n';
    }

    // Close output file
    outFile.close();
    return true;
}

bool Bitmatrix::PGM(const std::string &filename, int pixels, int border) {
    // Open file for writing
    std::ofstream outFile(filename.c_str(), std::ios::binary);
    if (!outFile) return false;

    // Calculate image dimensions
    int imgWidth = border * 2 + cols * (pixels + border);
    int imgHeight = border * 2 + rows * (pixels + border);

    // Write PGM header
    outFile << "P5\n" << imgWidth << " " << imgHeight << "\n255\n";

    // Write image data
    for (int r = 0; r < rows; ++r) {
        for (int p = 0; p < pixels + border; ++p) {
            for (int c = 0; c < cols; ++c) {
                for (int b = 0; b < border; ++b) {
                    outFile << char(255);
                }
                for (int b = 0; b < pixels; ++b) {
                    outFile << char(data[r][c] ? 0 : 255);
                }
            }
            for (int b = 0; b < border; ++b) {
                outFile << char(255);
            }
        }
    }

    // Write bottom border
    for (int b = 0; b < border; ++b) {
        for (int i = 0; i < imgWidth; ++i) {
            outFile << char(255);
        }
    }

    // Close output file
    outFile.close();
    return true;
}


// Function to compute the sum of two bitmatrices
Bitmatrix *Sum(Bitmatrix *bm1, Bitmatrix *bm2) {
    // Return NULL if the matrices have different dimensions
    if (bm1->Rows() != bm2->Rows() || bm1->Cols() != bm2->Cols()) {
        return NULL;
    }

    // Create a new bitmatrix to store the sum
    Bitmatrix *sum = new Bitmatrix(bm1->Rows(), bm1->Cols());

    // Compute the sum by XOR-ing the corresponding elements
    for (int r = 0; r < bm1->Rows(); ++r) {
        for (int c = 0; c < bm1->Cols(); ++c) {
            sum->Set(r, c, bm1->Val(r, c) != bm2->Val(r, c));
        }
    }

    return sum;
}

// Function to compute the product of two bitmatrices
Bitmatrix *Product(Bitmatrix *bm1, Bitmatrix *bm2) {
    // Return NULL if the matrices cannot be multiplied
    if (bm1->Cols() != bm2->Rows()) {
        return NULL;
    }

    // Create a new bitmatrix to store the product
    Bitmatrix *product = new Bitmatrix(bm1->Rows(), bm2->Cols());

    // Compute the product using the standard matrix multiplication algorithm
    for (int r = 0; r < bm1->Rows(); ++r) {
        for (int c = 0; c < bm2->Cols(); ++c) {
            bool val = false;
            for (int k = 0; k < bm1->Cols(); ++k) {
                val ^= (bm1->Val(r, k) && bm2->Val(k, c));
            }
            product->Set(r, c, val);
        }
    }

    return product;
}

// Function to create a submatrix from the given bitmatrix using specified indices
Bitmatrix *Sub_Matrix(Bitmatrix *bm, const std::vector<int> &indices) {
    // Create a new bitmatrix to store the submatrix
    Bitmatrix *sub = new Bitmatrix(indices.size(), bm->Cols());

    // Copy the selected rows to the submatrix
    for (size_t r = 0; r < indices.size(); ++r) {
        for (int c = 0; c < bm->Cols(); ++c) {
            sub->Set(r, c, bm->Val(indices[r], c));
        }
    }

    return sub;
}

// Function to compute the rank of a bitmatrix
bool Rank(Bitmatrix *bm) {
    int rank = 0;
    int maxRow = bm->Rows();
    int maxCol = bm->Cols();

    // Perform Gaussian elimination to compute the rank
    for (int r = 0; r < maxRow; ++r) {
        int pivotRow = r;

        // Find the pivot row for the current column
        while (pivotRow < maxRow && !bm->Val(pivotRow, r)) {
            ++pivotRow;
        }

        // If no pivot row is found, continue to the next column
        if (pivotRow == maxRow) {
            continue;
        }

        // Swap the current row with the pivot row, if necessary
        if (pivotRow != r) {
            for (int c = 0; c < maxCol; ++c) {
                bool temp = bm->Val(r, c);
                bm->Set(r, c, bm->Val(pivotRow, c));
                bm->Set(pivotRow, c, temp);
            }
        }

        // Increment the rank
        ++rank;

        // Perform row reduction on the rows below the current row
        for (int i = r + 1; i < maxRow; ++i) {
            if (bm->Val(i, r)) {
                for (int c = 0; c < maxCol; ++c) {
                    bm->Set(i, c, bm->Val(i, c) != bm->Val(r, c));
                }
            }
        }
    }

    return rank;
}
 


/*
Name: Aaron Marshall
NetID: amarsh32
Program Description: The purpose of this program is to use different methods including write(), read(), create(), etc. to modify and change an input based on a set of inputs.
 *
 * * */


#include "pgm.hpp"
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

bool Pgm::Read(const std::string &file)
{
  // Open the input file stream.
  ifstream fin;
  fin.open(file.c_str());

  // Check if the stream has opened successfully.
  if (fin.fail()) return false;

  // Read the file header.
  std::string s;
  size_t i, j, r, c, v;
  if (!(fin >> s)) return false;
  if (s != "P2") return false;
  if (!(fin >> c) || c <= 0) return false;
  if (!(fin >> r) || r <= 0) return false;
  if (!(fin >> i) || i != 255) return false;

  // Read the image data.
  Pixels.resize(r);
  for (i = 0; i < r; i++) {
    Pixels[i].clear();
    for (j = 0; j < c; j++) {
      if (!(fin >> v) || v > 255) return false;
      Pixels[i].push_back(v);
    }
  }

  // Check if there is any extraneous data at the end of the file.
  if (fin >> s) return false;

  // Close the input file stream.
  fin.close();
  return true;
}

// Write image data from memory to file.
bool Pgm::Write(const std::string &file) const
{
  // Open the output file stream.
  ofstream fout(file.c_str());
  if (fout.fail()) return false;

  // Write the file header.
  fout << "P2\n";
  fout << Pixels[0].size() << " " << Pixels.size() << "\n";
  fout << "255\n";

  // Write the image data, breaking lines at every 20 pixels.
  for (size_t i = 0; i < Pixels.size(); i++) {
    for (size_t j = 0; j < Pixels[i].size(); j++) {
      fout << Pixels[i][j] << " ";
      if ((j + 1) % 20 == 0) fout << "\n";
    }
    if (Pixels[i].size() % 20 != 0) fout << "\n";
  }

  // Close the output file stream.
  fout.close();
  return true;
}


// Create a new image with the specified dimensions and initial pixel value
bool Pgm::Create(size_t r, size_t c, size_t pv)
{
  // Resize the vector of rows to the specified number of rows
  Pixels.resize(r);
  // For each row, resize the vector of pixels to the specified number of columns and fill it with the initial pixel value
  for (size_t i = 0; i < r; i++) {
    Pixels[i].resize(c, pv);
  }
  return true;
}

// Rotate the image 90 degrees clockwise
bool Pgm::Clockwise()
{
  // Create a new vector to store the rotated image, with the rows and columns swapped
  vector<vector<int> > temp(Pixels[0].size(), vector<int>(Pixels.size()));
  // For each pixel in the original image, assign it to the corresponding position in the new rotated image
  for (size_t i = 0; i < Pixels.size(); i++) {
    for (size_t j = 0; j < Pixels[i].size(); j++) {
      temp[j][Pixels.size() - 1 - i] = Pixels[i][j];
    }
  }
  // Replace the original image with the rotated image
  Pixels = temp;
  return true;
}

// Rotate the image 90 degrees counterclockwise
bool Pgm::Cclockwise()
{
  // Create a new vector to store the rotated image, with the rows and columns swapped
  vector<vector<int> > temp(Pixels[0].size(), vector<int>(Pixels.size()));
  // For each pixel in the original image, assign it to the corresponding position in the new rotated image
  for (size_t i = 0; i < Pixels.size(); i++) {
    for (size_t j = 0; j < Pixels[i].size(); j++) {
      temp[Pixels[i].size() - 1 - j][i] = Pixels[i][j];
    }
  }
  // Replace the original image with the rotated image
  Pixels = temp;
  return true;
}

// Add padding around the image
bool Pgm::Pad(size_t w, size_t pv)
{
  // If the padding width is 0, return true (no padding needed)
  if (w == 0) {
    return true;
  }
  // If the image is empty, return false (cannot pad an empty image)
  if (Pixels.empty() || Pixels[0].empty()) {
    return false;
  }
  // Get the current number of rows and columns in the image
  const size_t r = Pixels.size();
  const size_t c = Pixels[0].size();
  // For each row in the image, insert padding pixels at the beginning and end
  for (size_t i = 0; i < r; i++) {
    for (size_t j = 0; j < w; j++) {
      Pixels[i].insert(Pixels[i].begin(), pv);
      Pixels[i].push_back(pv);
    }
  }
  // Create a new row of padding pixels with the same width as the padded image
  vector<int> border(c + 2 * w, pv);
  // Insert the new row of padding pixels at the beginning and end of the image
  for (size_t i = 0; i < w; i++) {
    Pixels.insert(Pixels.begin(), border);
    Pixels.push_back(border);
  }
  return true;
}

bool Pgm::Panel(size_t r, size_t c)
{
  // Check if the image is empty
  if (Pixels.empty() || Pixels[0].empty()) {
    return false;
  }
  // Get the number of rows in the original image
  const size_t old_r = Pixels.size();
  // Resize the image to the new number of rows
  Pixels.resize(r * old_r);
  // Iterate over the old rows
  for (size_t i = 0; i < old_r; i++) {
    // Get a copy of the current row
    vector<int> row(Pixels[i]);
    // Iterate over the desired number of columns
    for (size_t j = 1; j < c; j++) {
      // Insert a copy of the current row after the current row
      Pixels.insert(Pixels.begin() + (i + 1) * j, row);
    }
  }
  // Return success
  return true;
}

bool Pgm::Crop(size_t r, size_t c, size_t rows, size_t cols)
{
  // Check if the image is empty
  if (Pixels.empty() || Pixels[0].empty()) {
    return false;
  }
  // Get the number of rows and columns in the original image
  const size_t old_r = Pixels.size();
  const size_t old_c = Pixels[0].size();
  // Check if the crop is within the original image
  if (r >= old_r || c >= old_c || r + rows > old_r || c + cols > old_c) {
    return false;
  }
  // Erase the rows before the desired start row
  Pixels.erase(Pixels.begin(), Pixels.begin() + r);
  // Erase the rows after the desired end row
  Pixels.erase(Pixels.begin() + rows, Pixels.end());
  // Iterate over each remaining row and remove the columns before and after the desired crop
  for (std::vector<int>& row : Pixels) {
    row.erase(row.begin(), row.begin() + c);
    row.erase(row.begin() + cols - c, row.end());
  }
  // Return success
  return true;
}

// C program to demonstrate matrix multiply using multi processing work
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>  // Header for std::stringstream
#include <string>

// Using vectors for store dynamic matrix data
std::vector<std::vector<double>> matrix;
std::vector<std::vector<double>> matrix2;
const std::string files[] = {"matrix1.txt", "matrix2.txt"};

int readmatrix(std::string filename, std::vector<std::vector<double>> &matrix)
{
    std::ifstream file(filename);  // Open file for reading
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл" << std::endl;
        return 1; // Return error code
    }
    
    //int rows, cols; // Number of rows and columns

    std::string line;
    while (std::getline(file, line))  // Read single string from file
    {
        std::stringstream ss(line);   // Create string stream for single line
        double value;
        std::vector<double> row;
        while (ss >> value) { // Read values from string stream
          row.push_back(value);   // Add value in current string
        }
        matrix.push_back(row);  // Add string to matrix
    }
    
    file.close();
    return 0;
}

void printmatrix(std::vector<std::vector<double>> matrix)
{
  for (long unsigned int i = 0; i < matrix.size(); ++i) 
  { // Iterate through rows
    for (long unsigned int j = 0; j < matrix[i].size(); ++j) 
    { // Iterate through elements in current row
        std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl; // Newline after each row
  }
}

 std::vector<double> extractcolumn(std::vector<std::vector<double>> matrix, int col_idx)
 { // Extract a complete column into another vector
      std::vector<double> result;
      for(long unsigned int i = 0; i < matrix.size(); ++i) 
      {
          //double value = matrix[i][col_idx];
          //std::cout << matrix[i][col_idx] << " ";
          //result.push_back(matrix[i][col_idx]);
      }
      return result;
 }


int main()
{
    if (0 == readmatrix(files[0], matrix)) 
    {  // Read first matrix
      printmatrix(matrix);
        
      // print the middle row
      std::vector<double> elem = extractcolumn(matrix, 1);
      std::cout << elem.size() << std::endl;
    }
    
    if (0 == readmatrix(files[1], matrix2)) 
    {  // Read second matrix
        printmatrix(matrix2);
    }
    
    if (matrix.size() == 0 || matrix2.size() == 0)
    {
        std::cout << "Matrix has zero size" << std::endl;
        return 1;
    }
    
    if (matrix[0].size() != matrix2.size())
    {
        std::cout << "Matrices sizes not satisfied multiply rules" << std::endl;
        return 1;
    }
    
    
    
    return 0;
}



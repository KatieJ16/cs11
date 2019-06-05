#include "matrix.h"
using namespace std;

#include <iostream>
#include <string>
#include <set>


//Constructors
Matrix::Matrix(){
  this->rows = 0;
  this->cols = 0;



  matrix = new int*[1];
  for(int i = 0; i < 1; i++)
      matrix[i] = new int[1];

  //fill in with zeros
  for (int i = 0; i < 1; i++){
    for(int j = 0; j < 1; j ++){
      matrix[i][j] = 0;
    }
  }

  // this->matrix = matrix;
}
//define a rows x cols size matrix of zeros
Matrix::Matrix(int rows, int cols){
  //the matrix must have a size
  if(rows <= 0 || cols <= 0){
    throw std::invalid_argument("The number of Rows and Columns must be postive.");
  }

  this->rows = rows;
  this->cols = cols;

  //declare the matrix

  matrix = new int*[rows];
  for(int i = 0; i < rows; i++)
      matrix[i] = new int[cols];

  //fill in with zeros
  for (int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j ++){
      matrix[i][j] = 0;
    }
  }

}
// Cleans up a Matrix object.
Matrix::~Matrix() {
  for(int i = 0; i < rows; i++)
    delete[] matrix[i];
delete[] matrix;
}

//make the copy constructor
Matrix::Matrix(const Matrix &m){
  rows = m.numRows();
  cols = m.numCols();
  // Make a deep copy
  matrix = new int*[rows];
  for (int i = 0; i < rows; i++)
    matrix[i] = new int[cols];

  //fill in with numbers
  for (int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j ++){
      matrix[i][j] = m.get(i,j);
    }
  }

}

Matrix& Matrix::operator=( const Matrix &other ) {
  //Detect and handle self-assignment
  if(this == &other)
    return *this;
    
  //Release old memory
  for(int i = 0; i < rows; i++)
      delete[] matrix[i];
  delete[] matrix;

  //Allocate new memory
  rows = other.numRows();
  cols = other.numCols();
  // Make a deep copy
  matrix = new int*[rows];
  for (int i = 0; i < rows; i++)
    matrix[i] = new int[cols];

  //fill in with numbers
  for (int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j ++){
      matrix[i][j] = other.get(i,j);
    }
  }

  //Return non-const reference to myself
  return *this;

}

int Matrix::numRows() const{
  return rows;
}
int Matrix::numCols() const{
    return cols;
}
int Matrix::get(int r, int c) const{
  //r and c can't be larger than size
  if((r >= this->rows) || (c >= this->cols)){
    throw std::invalid_argument("row and columns not valid");
  }

  //cant be negative
  if((r < 0) || (c < 0)){
    throw std::invalid_argument("row and columns not valid");
  }

    return matrix[r][c];
}
int Matrix::set(int r, int c, int value){
  //r and c can't be larger than size
  if((r >= this->rows) || (c >= this->cols)){
    throw std::invalid_argument("row and columns not valid");
  }

  //cant be negative
  if((r < 0) || (c < 0)){
    throw std::invalid_argument("row and columns not valid");
  }

  matrix[r][c] = value;
  return 0;

}

//Redefine equals
bool Matrix::operator==(const Matrix &mat2){
  //they are not equal if different sizes
  if((this->rows != mat2.numRows())|| (this->cols != mat2.numCols())){
    return false;
  }
  //If they are the same size, check that every element is the same
  //and return false if any are different
  for(int i = 0; i < this->rows; i ++){
    for(int j = 0; j < this->cols; j ++){
      if(this->matrix[i][j] != mat2.get(i,j)){
        return false;
      }
    }
  }

  return true;
}

//Redefine not equals
bool Matrix::operator!=(const Matrix &mat2){
  //exact same as == but switch when to return truw and false

  //they are not equal if different sizes
  if((this->rows != mat2.numRows())|| (this->cols != mat2.numCols())){
    return true;
  }
  //If they are the same size, check that every element is the same
  //and return false if any are different
  for(int i = 0; i < this->rows; i ++){
    for(int j = 0; j < this->cols; j ++){
      if(this->matrix[i][j] != mat2.get(i,j)){
        return true;
      }
    }
  }

  return false;
}

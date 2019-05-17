using namespace std;
#include <string>
#include <vector>
#include <set>

// Class that stores the Matrix number
class Matrix {
  private:
    int **matrix;
    int rows;
    int cols;

  public:
     // Constructor
     Matrix();
     Matrix(int rows, int columns);
     ~Matrix(); // Destructor

     //Copy Constructor
     Matrix(const Matrix &m); // Must pass by reference

     Matrix& operator=( const Matrix& other ); //Copy-assignment operator

     //Accessors
     int numRows() const; //returns the number of Rows
     int numCols() const; //returns the number of columns
     int get(int r, int c) const; //returns the values tored at the specified row and column.
     int set(int r, int c, int value); //sets the value stored at the specified row and column.

     //redefine some operators
     bool operator==(const Matrix &mat2);
     bool operator!=(const Matrix &mat2);
};

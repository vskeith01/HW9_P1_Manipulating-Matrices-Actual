#include <iostream>
#include <iomanip>

using namespace std;

// FUNCTIONS
void printMatrix_3col(int matrix[][3], int N_ROWS, int N_COLUMNS);


int CountUnhealthySensitive(int matrix[10][3], int collum);

int main() {
  
  
  int AirQuality_Index[10][3] =  { {50, 68, 58},
                                   {58, 115, 78},
                                   {62, 110, 81},
                                   {66, 124, 110},
                                   {64, 152, 121},
                                   {46, 143, 90},
                                   {46, 143,90},
                                   {25, 91, 91},
                                   {27, 19, 59},
                                   {17, 13, 27} };

  cout << "The air quality index for Grand Junction, Fort Collins, and Denver-Boulder from 10/4/2020 through 10/13/2020 is:" << endl;
  printMatrix_3col(AirQuality_Index, 10, 3);

  // find the number of unhealthy days\
  int CollumOfCity;
   cout << "Please input the collum number of the city you are looking for.\n(Grand Junction = 0, Fort Collins = 1, Donver-Boulder = 2)"<< endl;
  cin >> CollumOfCity;

  CountUnhealthySensitive(AirQuality_Index, CollumOfCity);
}


// function to print the matrix in a matrix with 3 columns
void printMatrix_3col(int matrix[][3], int N_ROWS, int N_COLUMNS) {
  int row, col;
  for (row = 0; row < N_ROWS; row++) {
    for (col = 0; col < N_COLUMNS; col++)
      cout << setw(6) << matrix[row][col] << " ";

    cout << endl;
  }
}


// function to find how many times the airquality was "unhealthy for sensitive groups" for a specific city
int CountUnhealthySensitive(int matrix[10][3], int collum){
  
  int row;
  int unhealthy;     // number of unhealthy days the specific city
  
  for (row = 0; row < 10; row++){
    if (matrix[row][collum] > 100)
        unhealthy++;
  }

  return unhealthy;
}
#include <iostream>
using namespace std;

// Global constants
const int ROWS = 3; // The number of rows in the array
const int COLS = 3; // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

// Function prototypes
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);

int main()
{

    int magicArray[ROWS][COLS], userInput;
    // Your code goes here

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << "Enter the number for row " << i << " and column " << j << " :";
            cin >> magicArray[i][j];
        }
    }
    return 0;
}
// Function definitions go here

bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {}
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max) {}
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {}
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size) {}
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size) {}
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size) {}
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {}
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
        }
    }
}
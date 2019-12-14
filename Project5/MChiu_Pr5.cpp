/*
 * Class: CMSC140 CRN 24381
 * Instructor: Dr. Kuijt
 * Project 5
 * Description: Lo Shu Magic Square validator. User enters inputs for a potential Lo Shu Magic Square and outputs whether it is or not.
 * Due Date:
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Max Chiu
 

 * Pseudocode or Algorithm for the program:
	(be sure to indent items with control structure)
	(need to match flow chart submitted in documentation)
  1. Init
     - consts
          * Square Specifications (rows, cols, min cell val, max cell val.)
          * Credits (Programmer name, project number, due date)
     - variables
          * magicArray (hold square input values)
          * user inputs (cell values, try again)
  2. Square Input
     - The square is 3x3. For every cell, ask for a value.
     - User inputs value that is min(1) < x < max(9)
  3. Square validation
     - Check if all numbers are in range
     - Check if all numbers are unique (no repetition)
     - Check if every row, column, and diagonal have the same sum
  4. Output
     - Prints out the user-inputted Lo Shu Square
     - Prints out whether the square is a Lo Shu Square
     - Asks user if they want to try again
            * Any input that is not 'y' will be considered as no
            * If 'y', return to step 2
  5. Outro
     - Programmer name, assignment #, due date
*/

#include <iostream>
#include <string>
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

// custom function prototype
int arraySum(int array[], int size);
bool checkSingleUnique(int array[], int size, bool uniqueList[]);
void showSingleArray(int array[], int size);
bool checkSingleRange(int array[], int size, int min, int max);
void fillSingleArray(int array[], int size, int rowNum);

int main()
{
    // Init Vars
    int magicArray[ROWS][COLS];
    char userInput;
    bool repeat = false;

    const string programmerName = "Max Chiu", dueDate = "12/15/19";
    const int assignNum = 5;

    // do while loop to allow the user to use the program inf # of times.
    do
    {
        repeat = false;
        fillArray(magicArray[0], magicArray[1], magicArray[2], ROWS);
        showArray(magicArray[0], magicArray[1], magicArray[2], ROWS);
        if (isMagicSquare(magicArray[0], magicArray[1], magicArray[2], ROWS))
        {
            cout << "This is a Lo Shu magic square";
        }
        else
        {
            cout << "This is not a Lo Shu magic square";
        }
        cout << "\n\n\nDo you want to try again? ";
        cin >> userInput;
        if (userInput == 'y' || userInput == 'Y')
        {
            repeat = true;
        }
    } while (repeat);

    cout << "\n\nName: " << programmerName << endl
         << "Project #: " << assignNum << endl
         << "Due Date: " << dueDate;
    return 0;
}

//Required functions

bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    /*
    Given rows, return if the following input is a Lo Shu Square
    */

    return checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX) &&
           checkUnique(arrayRow1, arrayRow2, arrayRow3, size) &&
           checkRowSum(arrayRow1, arrayRow2, arrayRow3, size) &&
           checkColSum(arrayRow1, arrayRow2, arrayRow3, size) &&
           checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size);
}

bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max)
{
    /*
    Given rows, check if every value is min < x < max
    */

    // check if all values are in range of min, max.
    return checkSingleRange(arrayRow1, size, min, max) &&
           checkSingleRange(arrayRow2, size, min, max) &&
           checkSingleRange(arrayRow3, size, min, max);
}
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    /*
    Given rows, check if all the values in the square are unique from each other
    */

    //a bool list so we know if a # is used or not.
    bool uniqueList[9] = {0};

    // true if row 1-3 are all unique
    return checkSingleUnique(arrayRow1, size, uniqueList) &&
           checkSingleUnique(arrayRow2, size, uniqueList) &&
           checkSingleUnique(arrayRow3, size, uniqueList);
}

void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    /*
    Asks user to fill in Lo Shu Square
    */
    fillSingleArray(arrayRow1, size, 1);
    fillSingleArray(arrayRow2, size, 2);
    fillSingleArray(arrayRow3, size, 3);
}
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
    /*
    Shows the Lo Shu Square
    */
    showSingleArray(arrayrow1, size);
    showSingleArray(arrayrow2, size);
    showSingleArray(arrayrow3, size);
}

bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
    /*
    Checks if the sum of each row equals each other
    */

    // row 1 == row 2, row 2 == row 3, therefore row1 == row 3
    return arraySum(arrayrow1, size) == arraySum(arrayrow2, size) &&
           arraySum(arrayrow2, size) == arraySum(arrayrow3, size);
}
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
    /*
    Checks if the sum of each column equals each other
    */

    // array of sums for each column
    int totalSum[size];

    for (int i = 0; i < size; i++)
    {
        int colArray[3] = {arrayrow1[i], arrayrow2[i], arrayrow3[i]};
        totalSum[i] = arraySum(colArray, size);
    }

    // column sum = sum. sum 1 == sum 2, sum 2 == sum 3, therefore sum 1 == sum 3
    return totalSum[0] == totalSum[1] &&
           totalSum[1] == totalSum[2];
}
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
    /*
    Checks if the sum of each of the diagonals equal each other
    */

    // define inputs
    int diagonalOne[3] = {arrayrow1[2], arrayrow2[1], arrayrow3[0]}, diagonalTwo[3] = {arrayrow1[0], arrayrow2[1], arrayrow3[2]};

    return arraySum(diagonalOne, size) == arraySum(diagonalTwo, size);
}

// custom functions
int arraySum(int array[], int size)
{
    /*
    returns sum of array
    */

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}

bool checkSingleUnique(int array[], int size, bool uniqueList[])
{
    /*
    Pass in an array, and then a list of boolean values whose indexes you want to check against
    if array has 1, go to 0th index of list and if false, set to true
    Otherwise, return false (not unique)
    */
    for (int i = 0; i < size; i++)
    {

        if (uniqueList[array[i] - 1])
        {
            cout << "not unique";
            return false;
        }
        else
        {
            // set index to true so the next time the same # is seen the array won't be unique
            uniqueList[array[i] - 1] = true;
        }
    }
    return true;
}
void showSingleArray(int array[], int size)
{
    /*
    Print all values of an array on a line and endl
    */
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
bool checkSingleRange(int array[], int size, int min, int max)
{
    /*
    Checks if every value in array is min < x < max
    */
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max || array[i] < min)
            return false;
    }
    return true;
}

void fillSingleArray(int array[], int size, int rowNum)
{
    /*
    User fills out every value in array
    */

    for (int j = 0; j < size; j++)
    {
        cout << "Enter the number for row " << rowNum << " and column " << j + 1 << " :";
        cin >> array[j];
    }
}
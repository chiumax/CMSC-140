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

// custom function prototype
int arraySum(int array[], int size);
bool checkSingleUnique(int array[], int size, bool uniqueList[]);
void showSingleArray(int array[], int size);
bool checkSingleRange(int array[], int size, int min, int max);

int main()
{

    int magicArray[ROWS][COLS];
    string userInput;
    bool repeat = false;

    const string programmerName = "Max Chiu", dueDate = "1/1/1";
    const int assignNum = 5;

    // Your code goes here
    do
    {
        repeat = false;
        fillArray(magicArray[0], magicArray[1], magicArray[2], ROWS);
        if (isMagicSquare(magicArray[0], magicArray[1], magicArray[2], ROWS))
        {
            cout << "This is a Lo Shu magic square";
        }
        else
        {
            cout << "This is not a Lo Shu magic square";
        }
        cout << "Do you want to try again?";
        cin >> userInput;
        if (userInput == "y")
        {
            repeat = true;
        }
    } while (repeat);

    cout << "Name: " << programmerName << endl
         << "Project #: " << assignNum << endl
         << "Due Date: " << dueDate;
    return 0;
}
// Function definitions go here

bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    return checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX) &&
           checkUnique(arrayRow1, arrayRow2, arrayRow3, size) &&
           checkRowSum(arrayRow1, arrayRow2, arrayRow3, size) &&
           checkColSum(arrayRow1, arrayRow2, arrayRow3, size) &&
           checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size);
}
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max)
{
    // check if all values are in range of min, max.
    return checkSingleRange(arrayRow1, size, min, max) &&
           checkSingleRange(arrayRow2, size, min, max) &&
           checkSingleRange(arrayRow3, size, min, max);
}
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    //a bool list so we know if a # is used or not.
    bool uniqueList[9] = {0};

    // true if row 1-3 are all unique
    return checkSingleUnique(arrayRow1, size, uniqueList) &&
           checkSingleUnique(arrayRow2, size, uniqueList) &&
           checkSingleUnique(arrayRow3, size, uniqueList);
}
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
    // row 1 == row 2, row 2 == row 3, therefore row1 == row 3
    return arraySum(arrayrow1, size) == arraySum(arrayrow2, size) &&
           arraySum(arrayrow2, size) == arraySum(arrayrow3, size);
}
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
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
    // define inputs
    int diagonalOne[3] = {arrayrow1[2], arrayrow2[1], arrayrow3[0]}, diagonalTwo[3] = {arrayrow1[0], arrayrow2[1], arrayrow3[2]};

    return arraySum(diagonalOne, size) == arraySum(diagonalTwo, size);
}

void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    int *currentArray;
    for (int i = 0; i < size; i++)
    {
        switch (i)
        {
        case 0:
            currentArray = arrayRow1;
            break;
        case 1:
            currentArray = arrayRow2;
            break;
        case 2:
            currentArray = arrayRow3;
            break;
        default:
            break;
        }
        for (int j = 0; j < size; j++)
        {
            cout << "Enter the number for row " << i << " and column " << j << " :";
            cin >> currentArray[j];
        }
    }
}
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
    showSingleArray(arrayrow2, size);
    showSingleArray(arrayrow2, size);
    showSingleArray(arrayrow3, size);
}

int arraySum(int array[], int size)
{
    // returns sum of array
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}
bool checkSingleUnique(int array[], int size, bool uniqueList[])
{
    // pass in a list, a list of unique values you want to check against
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
    // print a single array
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
bool checkSingleRange(int array[], int size, int min, int max)
{
    // checks the range of an array
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max || array[i] < min)
            return false;
    }
    return true;
}
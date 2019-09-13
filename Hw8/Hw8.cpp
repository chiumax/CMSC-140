/*
Hw8.cpp

CMSC 140, CRN 24381, Dr. Kuijt
Max C.

Write a program to read as many test scores as the user wants from the keyboard (assuming at most 50 scores).

Print the scores in 
    (1) original order, 
    (2) sorted from high to low ,
    (3) the highest score, 
    (4) the lowest score, and  
    (5) the average of the scores.
*/

#include <iostream>
#include <string>

using namespace std;

// function prototypes

void displayArray(int array[], int size);
void selectionSort(int array[], int size);

int findMax(int array[], int size);
int findMin(int array[], int size);

double findAvg(int array[], int size);

int main()
{
    int grades[50], size;
    cout << "How many scores do you want to enter ? ";
    cin >> size;

    // Loops through inputted size to query all test scores
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Score #" << i + 1 << ": ";
        cin >> grades[i];
    }

    // Output
    cout << "Original order scores are: ";
    displayArray(grades, size);

    cout << "\nScores ordered High to low: ";
    selectionSort(grades, size);
    displayArray(grades, size);

    cout << "\nHighest Score: " << findMax(grades, size);
    cout << "\nLowest Score: " << findMin(grades, size);
    cout << "\nAverage of scores: " << findAvg(grades, size);

    return 0;
}

void displayArray(int array[], int size)
{
    /*
         Displays the content of the array 
    */
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}
void selectionSort(int array[], int size)
{
    /*
        sorts the array using the selection sort algorithm in descending order.
    */
    int index, val, temp;

    for (int i = 0; i < size; i++)
    {
        val = array[i];
        index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] > val)
            {
                index = j;
                val = array[j];
            }
        }
        temp = array[i];
        array[i] = val;
        array[index] = temp;
    }
}

int findMax(int array[], int size)
{
    /*
        finds and returns the highest element of the array
    */

    int largest = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] > largest)
            largest = array[i];
    }

    return largest;
}
int findMin(int array[], int size)
{
    /*
        finds and returns the lowest element of the array
    */
    int smallest = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] < smallest)
            smallest = array[i];
    }
    return smallest;
}

double findAvg(int array[], int size)
{
    /*
        finds and returns the average of the elements of the array
    */
    float sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum / size;
}
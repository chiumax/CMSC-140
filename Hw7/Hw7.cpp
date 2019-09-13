/* 
Hw7.cpp

CMSC 140, CRN 24381, Dr. Kuijt
Max C.

Display all of the numbers in the array that are greater than the number n.

In the main() function create an array named numbers containing 
10 integers :  30,20,50,2,-1,44,3,12,90,32 

*/
#include <iostream>
#include <string>

using namespace std;

void largerThanN(int numbers[], int length, int n)
{
    cout << "The numbers that are larger than " << n << " are: ";
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] > n)
        {
            cout << numbers[i] << " ";
        }
    }
    cout << "\n";
    system("pause");
}

int main()
{
    int numbers[] = {30, 20, 50, 2, -1, 44, 3, 12, 90, 32}, n;

    cout << "Enter a number:\n";
    cin >> n;

    largerThanN(numbers, sizeof(numbers) / sizeof(numbers[0]), n);

    return 0;
}

/* 
Hw4_part1.cpp

CMSC 140, CRN 24381, Dr. Kuijt
Max C.

A software company sells a package that retails for $99. Quantity discounts are given according to the following table.


Quantity               discount
------------------------------
10-19                     20%

20-49                     30%

50-99                     40%

100 or more               50%


Write a program that asks for the number of units sold and computes the total cost of the purchase.
Input validation: Make sure the number of units is greater than 0.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int input;
    float discount;

    cout << "How many units were sold? ";
    cin >> input;

    if (0 < input && input < 10)
    {
        discount = 0;
    }
    else if (10 <= input && input <= 19)
    {
        discount = .20;
    }
    else if (20 <= input && input <= 49)
    {
        discount = .30;
    }
    else if (50 <= input && input <= 99)
    {
        discount = .40;
    }
    else if (100 <= input)
    {
        discount = .50;
    }
    else
    {
        cout << "Units sold must be greater than zero";
        return 0;
    }

    // 2 decimal points
    cout << "The total cost of the purchase is $" << fixed << setprecision(2) << ((input * 99) - (input * 99 * discount));
    return 0;
}
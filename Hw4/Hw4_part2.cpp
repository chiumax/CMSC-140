/* 
Hw4_part2.cpp

CMSC 140, CRN 24381, Dr. Kuijt
Max C.

Write a program to determine the price for a portrait sitting. 
The price is determined by subjects in portraits, background chosen and sitting appointment day.

The fee schedule is shown below. 

Fancy background and sitting appointment cost an extra 10 percent more than the base price.

 

Subjects in Portrait       Base Price

1                          $100

2                          $130

3                          $150

4                          $160

5 or more                  $165
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    int numSubject;
    float basePrice, fancyBackPrice = 0, appDatePrice = 0;
    string tempInput;

    cout << "Enter the number of subjects in the portrait: ";
    cin >> numSubject;

    if (numSubject == 1)
    {
        basePrice = 100;
    }
    else if (numSubject == 2)
    {
        basePrice = 130;
    }
    else if (numSubject == 3)
    {
        basePrice = 150;
    }
    else if (numSubject == 4)
    {
        basePrice = 160;
    }
    else if (numSubject >= 5)
    {
        basePrice = 165;
    }
    else
    {
        cout << "Please input a integer value greater than 0 next time.";
        return 0;
    }

    cout << "Do you want a fancy background (y/n)? ";
    cin >> tempInput;

    if (tempInput == "y" || tempInput == "yes")
    {
        fancyBackPrice = basePrice * .1;
    }

    cout << "Do you want an appointment date (y/n)? ";
    cin >> tempInput;

    if (tempInput == "y" || tempInput == "yes")
    {
        appDatePrice = basePrice * .1;
    }

    cout << "The price is: $" << fixed << setprecision(2) << basePrice + fancyBackPrice + appDatePrice;
    return 0;
}

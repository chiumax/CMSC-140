/* 
Hw6_part1.cpp

CMSC 140, CRN 24381, Dr. Kuijt
Max C.

Adding and Subtracting through user input
*/

#include <iostream>

using namespace std;

double addition(float first, float second)
{
    return first + second;
}

int getChoice()
{
    int input;
    cout << "Enter your Choice, 1 for Addition, 2 for subtraction: ";
    cin >> input;

    if (input != 1 && input != 2)
    {
        cout << "Please enter either 1 or 2.\n";
        return getChoice();
    }
    return input;
}

void getNumbers(float &num1, float &num2)
{
    cout << "Enter first Number: ";
    cin >> num1;
    cout << "Enter second Number: ";
    cin >> num2;
}

int main()
{
    int choice;
    float firstNum, secondNum, final;

    choice = getChoice();

    getNumbers(firstNum, secondNum);

    final = (choice == 1) ? addition(firstNum, secondNum) : addition(firstNum, secondNum * -1);

    cout << "The result of the operation is: " << final << endl;
    system("pause");
    return 0;
}

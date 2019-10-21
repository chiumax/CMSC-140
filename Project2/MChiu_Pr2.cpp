/*
 * Class: CMSC140 CRN 24381
 * Instructor: Dr. Kuijt
 * Project 2
 * Description: A "Converter Toolkit" that primarily converts Temperature, Distance, Weight from Metric to Imperial
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
          * Credits (Programmer name, project number, due date)
     - variables
          * user country
          * user inputs (menu choice, conversion value)
  2. Introduction
     - Ask for a country name
     - User inputs country
     - Display conversion toolkit menu
     - User inputs selection and program checks if in bounds.
  3. Temperature Conversion
     - Asks for a number in Celsius
     - User inputs a number
     - Outputs user input converted to Fahrenheit - Whole Number output ex. 84
  4. Distance Conversion
     - Asks for a number in Kilometer
     - User inputs a number
     - Outputs user input converted to Mile - Two decimal output ex. 84.56
  5. Weight Conversion
     - Asks for a number in Kilogram
     - User inputs a number
     - Outputs user input converted to Pound - One decimal output ex. 84.5
  5. Outro
     - X country sounds fun!
     - Programmer name, assignment #, due date
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function prototypes
void tempConvert();
void distConvert();
void weightConvert();

int main()
{
    // Init vars
    int userChoice;
    string userCountry;

    const string programmerName = "Max Chiu", dueDate = "10/21/2019";
    const int assignNum = 2;

    // Begin
    cout << "Enter a country name: ";
    getline(cin, userCountry);

    cout << "\nConverter Toolkit\n"
         << setfill('-') << setw(20) << "\n"
         << "   1. Temperature Converter\n"
         << "   2. Distance Converter\n"
         << "   3. Weight Converter\n"
         << "   4. Quit\n";

    cout << "Enter your choice (1-4): ";
    cin >> userChoice;
    cout << "\n";

    // Check if input is 1-4
    switch (userChoice)
    {
    case 1:
        tempConvert();
        break;
    case 2:
        distConvert();
        break;
    case 3:
        weightConvert();
        break;
    case 4:
        cout << "Exiting...";
        return 0;
        break;
    default:
        // Would have made case 4 default but wouldn't have been specific enough
        cout << "Invalid choice (1-4 only), exiting...";
        return 0;
        break;
    }

    cout << "\n"
         << userCountry << " sounds fun!\n\n";

    // Outro
    cout << "Thank you for testing my program!!\n"
         << "PROGRAMMER: " << programmerName << endl
         << "CMSC140 Common Project " << assignNum << endl
         << "Due Date: " << dueDate << endl;
    return 0;
}

void tempConvert()
{
    /*
    Converts Celsius to Fahrenheit
    */
    double userInput;

    cout << "Please enter temperature in Celsius (such as 24 ) : ";
    cin >> userInput;

    // Whole number
    cout << fixed << setprecision(0) << "It is " << 9.0 / 5.0 * userInput + 32.0 << " in Fahrenheit.\n";
}
void distConvert()
{
    /*
    Converts Kilometer to Mile
    */
    double userInput;

    cout << "Please enter distance in Kilometer (such as 18.54): ";
    cin >> userInput;

    // Can't convert negative values
    if (userInput >= 0)
    {
        // Two decimal places
        cout << fixed << setprecision(2) << "It is " << userInput * 0.6 << " in Miles.\n";
    }
    else
    {
        cout << "  !!! Program dos not convert negative distance !!!\n";
    }
}
void weightConvert()
{
    /*
    Converts Kilogram to Pound
    */
    double userInput;

    cout << "Please enter weight in Kilograms (such as 6 ) : ";
    cin >> userInput;

    // Can't convert negative values
    if (userInput >= 0)
    {
        // One decimal Place
        cout << fixed << setprecision(1) << "It is " << userInput * 2.2 << " in Pounds.\n";
    }
    else
    {
        cout << "  !!! Program dos not convert negative weight !!!\n";
    }
}

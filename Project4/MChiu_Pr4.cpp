/*
 * Class: CMSC140 CRN 24381
 * Instructor: Dr. Kuijt
 * Project 4
 * Description: Average number of days a company's employees were absent during the year and counts into a text file
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
          * ofstream output file
     - variables
          * days absent average
          * user inputs (employee count, days absent count)
  2. Introduction
     - Welcome message about program purpose
     - Write header to text file ("Employee absence report", two columns- each for id and # absent)
  3. Employee Count
     - Asks for number of employees
     - User inputs a number greater than 0
  4. Days Absent
     - For every employee in the company, ask for employee ID and absent frequency
     - User inputs one for each prompt but absence frequency cannot be negative
     - Everytime the user input is validated (criteria listed above) it is written to output file
     - Using user input, write to file the # of employees, # of absent days, and the average.
  5. Outro
     - Write to output file programmer name
     - Programmer name, assignment #, due date
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Global Vars
ofstream outputFile;

// Function prototypes
int NumOfEmployees();
int TotDaysAbsent(int employeeCount);
double AverageAbsent(int employeeCount, int daysAbsentCount);

int main()
{
    // Init Vars
    int employeeCount;
    double daysAbsentCount;

    const string programmerName = "Max Chiu", dueDate = "25/11/19";
    const int assignNum = 4;

    // Open file, create one if doesn't exist
    outputFile.open("employeeAbsences.txt");

    // Write headers to the file
    outputFile << "EMPLOYEE ABSENCE REPORT\nemployee id   days absent\n";

    cout << "Calculate the average number of days a company's employees are absent.\n";

    employeeCount = NumOfEmployees();
    daysAbsentCount = TotDaysAbsent(employeeCount);

    // Write summary to end of file
    outputFile << "The " << employeeCount << " employees were absent a total of " << daysAbsentCount << " days.\n"
               << "The average number of days absent is " << AverageAbsent(employeeCount, daysAbsentCount) << " days.\n";

    outputFile << "Programmer: " << programmerName;

    outputFile.close();

    // Outro
    cout << "Thank you for testing my program!!\n"
         << "PROGRAMMER: " << programmerName << endl
         << "CMSC140 Common Project " << assignNum << endl
         << "Due Date: " << dueDate;
}

int NumOfEmployees()
{
    /* 
    Queries for number of employees in the company
    */

    // init vars
    int userInput;
    bool validate = true;

    do
    {
        if (validate)
        {
            cout << "Please enter the number of employees in the company: ";
        }
        else
        {
            cout << "Please re-enter the number of employees in the company: ";
        }

        cin >> userInput;

        if (userInput < 1)
        {
            validate = false;
            cout << "The number of employees must not be negative or zero. ";
            continue;
        }

        validate = true;

    } while (!validate);

    return userInput;
}

int TotDaysAbsent(int employeeCount)
{
    /*
    For each employee, queries for ID and days absent
    Writes to file gathered information
    Returns total days absent
    */

    // Init Vars
    int userInput, total = 0;
    bool validate = true;
    for (int i = 0; i < employeeCount; i++)
    {
        do
        {
            if (validate)
            {
                cout << "Please enter the an employee ID: ";
                cin >> userInput;

                // Write to file the employee ID
                outputFile << setw(8) << userInput;
                cout << "Please enter the number of days this employee was absent: ";
            }
            else
            {

                cout << "Please re-enter the number of days absent: ";
            }
            cin >> userInput;
            if (userInput < 0)
            {
                validate = false;
                cout << "The number of days must not be negative or zero. ";
                continue;
            }

            total += userInput;

            // Write to file the # of days absent on the same row as the corresponding ID
            outputFile << setw(10) << userInput << endl;
            validate = true;
        } while (!validate);
    }
    return total;
}
double AverageAbsent(int employeeCount, int daysAbsentCount)
{
    /*
    Calculates average absence per employee
    */

    // cast to double to ensure decimal accuracy.
    return (double)daysAbsentCount / (double)employeeCount;
}
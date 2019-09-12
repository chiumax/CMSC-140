#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int NumOfEmployees();
int TotDaysAbsent(int employeeCount);
double AverageAbsent(int employeeCount, int daysAbsentCount);

ofstream outputFile;

int main()
{
    int employeeCount, daysAbsentCount;

    const string programmerName = "Max Chiu";

    outputFile.open("employeeAbsences.txt");

    outputFile << "EMPLOYEE ABSENCE REPORT\nemployee id   days absent\n";

    cout << "Calculate the average number of days a company's employees are absent.\n";

    employeeCount = NumOfEmployees();
    daysAbsentCount = TotDaysAbsent(employeeCount);
    cout << "Programmer: " << programmerName;

    outputFile << "The " << employeeCount << " employees were absent a total of " << daysAbsentCount << " days.\n"
               << "The average number of days absent is " << AverageAbsent(employeeCount, daysAbsentCount) << " days.\n";

    outputFile << "Programmer: " << programmerName;

    outputFile.close();
}

int NumOfEmployees()
{
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
            cout << "The number of employees must not be negative.";
            continue;
        }
        validate = true;
    } while (!validate);
    return userInput;
}
int TotDaysAbsent(int employeeCount)
{
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
                outputFile << setw(8) << userInput;
                cout << "Please enter the number of days this employee was absent: ";
            }
            else
            {

                cout << "Please re-enter the number of days absent";
            }
            cin >> userInput;
            if (userInput < 0)
            {
                validate = false;
                cout << "The number of days must not be negative.";
                continue;
            }
            total += userInput;
            outputFile << setw(10) << userInput << endl;
            validate = true;
        } while (!validate);
    }
    return total;
}
double AverageAbsent(int employeeCount, int daysAbsentCount)
{
    // cast to double to ensure decimal accuracy.
    return (double)daysAbsentCount / (double)employeeCount;
}
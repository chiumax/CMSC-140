/* 
Hw3.cpp

CMSC 140, CRN 24381, Dr. Kuijt
Max C.

Develop a program that calculates the final score and the average score for a student from his/her (1)class participation, (2) test, (3) assignment, (4) exam,  and (5) practice scores.

The user should enter the name of the student and scores ranging from 0 to 100 for each grading item.

The final score is the sum of all grading items.

The average score is the average of all grading items.
*/

#include <iostream>
#include <string>

using namespace std;

bool checkNum(float grade)
{
    /*
        Checks if grade is between 0 and 100
    */
    return (grade >= 0 && grade <= 100);
}

int main()
{
    bool isProgramRunning = true;
    float finalScore = 0, avgScore, input;
    string studentName, questions[5] = {"Enter Class Participation Score ranging from 0 to 100: ", "Enter Test Score ranging from 0 to 100: ", "Enter Assignment Score ranging from 0 to 100: ", "Enter Exam Score ranging from 0 to 100: ", "Enter Practice Score ranging from 0 to 100: "};
    while (isProgramRunning)
    {
        finalScore = 0;
        isProgramRunning = false;
        cout << "Enter the Student's name: ";
        getline(cin, studentName);

        for (int i = 0; i < 5; i++)
        {
            cout << questions[i];
            cin >> input;

            if (!checkNum(input))
            {
                isProgramRunning = true;
                cout << "Error: Please enter a number between 0 and 100 next time.\nRestarting...\n";
                cin.ignore();
                break;
            }
            finalScore += input;
        }
        avgScore = finalScore / 5;
    }
    cout << studentName << ": Final Score: " << finalScore << " Average Score: " << avgScore;
    return 0;
}

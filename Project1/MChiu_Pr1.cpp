/*
 * Class: CMSC140 CRN 24381
 * Instructor: Dr. Kuijt
 * Project 1
 * Description: The Department plans to purchase a humanoid robot. And my job is to write a greeting script.
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
          * Time unit lengths (months, days, hours, dog years, gold fish years, etc.)
          * Dog age must be 7x human age
          * Goldfish age must be 5x human age
          * 1 month must be 30 days
          * Credits (Programmer name, project number, due date)
     - variables
          * robot name
          * user inputs (visitor name, age, 2 numbers)
  2. Introduction
     - Welcome message, asks for name
     - User inputs name
  3. Game 1
     - Asks for a number
     - User inputs a number
     - Outputs the different units of time that number in years can represent (input*const)
          * Years
          * Months (y*12)
          * Days (y*12*30)
          * Hours (y*12*30*24)
          * Minutes (y*12*30*24*60)
          * Seconds (y*12*30*24*60*60)
          * Dog years (y*7)
          * Goldfish years (y*5)
  4. Game 2
     - Asks for two whole numbers in total (one at a time)
     - User inputs one for each prompt
     - Outputs 
          * int addition 
          * int division
          * but highlights the difference between int and float/double division with setprecision for one decimal point
  5. Outro
     - Programmer name, assignment #, due date
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
     // Init variables
     string robotName = "Nao", visitorName;
     int age;
     double wholeNumOne, wholeNumTwo;

     const string programmerName = "Max Chiu", dueDate = "10/7/2019";
     const int assignNum = 1;

     // year to months, seconds, etc.
     const int months = 12, days = 30, hours = 24, minutes = 60, seconds = 60, dogYear = 7, goldFish = 5;

     //// Introduction
     cout << "Hello, welcome to Montgomery College! My name is " << robotName << ". May I have your name?\n";
     getline(cin, visitorName);

     //// Game #1
     cout << "Nice to have you with us today, " << visitorName
          << "!\nLet me impress you with a small game.\n"
          << "Give me the age of an important person or a pet to you.\n"
          << "Please give me only a number:\n";
     cin >> age;
     cout << "\nYou have entered " << age << ".\n";

     // Converting (years) age to different units
     cout << "If this is for a person, the age can be expressed as:\n "
          << age << " years\n or "
          << age * months << " months\n or "
          << age * months * days << " days\n or "
          << age * months * days * hours << " hours\n or "
          << age * months * days * hours * minutes << " minutes\n or "
          << age * months * days * hours * minutes * seconds << " seconds\n "
          << "If this is for a dog, it is " << age * dogYear << " years old in human age.\n "
          << "If this is for a gold fish, its is " << age * goldFish << " years old in human age.\n";

     //// Game #2
     cout << "\nLet's play another game, " << visitorName << ". Give me a whole number.\n";
     cin >> wholeNumOne;
     cout << "Very well. Give me another whole number.\n";
     cin >> wholeNumTwo;

     cout << "Using the operator '+' in C++, the result of " << wholeNumOne << " + " << wholeNumTwo << " is " << wholeNumOne + wholeNumTwo << ".\n";
     // Either cout or setprecision does rounding. Cast int during division to prevent # > 0.5 to round.
     cout << "Using the operator '/', the result of " << wholeNumOne << " / " << wholeNumTwo << " is " << (int)(wholeNumOne / wholeNumTwo) << ".\n";
     cout << setprecision(1) << fixed << "However, the result of " << wholeNumOne << " / " << wholeNumTwo << " is about " << ((int)((wholeNumOne / wholeNumTwo) * 10)) / 10.0 << ".\n";

     //// Outro
     cout << "\nThank you for testing my program!!" << endl
          << "PROGRAMMER: " << programmerName << endl
          << "CMSC140 Common Project " << assignNum << endl
          << "Due Date: " << dueDate << endl
          << endl;

     system("pause");
}

/* 
Hw5_part2.cpp

CMSC 140, CRN 24381, Dr. Kuijt
Max C.

Ask for user info and save to list.txt
Then read information and display it on the screen in the format:

Name:                User's Name  
Phone Number:        User's Phone Number  
Address:             User's Street Address 
                     User's City, State, and Zip Code 
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string question[6] = {"Name", "Phone #", "Street Address", "City", "State", "Zip Code"}, answers[6], display[3] = {"Name", "Phone Number", "Address"}, data;
    ofstream outListFile;
    outListFile.open("list.txt");
    for (int i = 0; i < 6; i++)
    {
        cout << question[i] << ": ";
        getline(cin, answers[i]);
        outListFile << answers[i] << endl;
    }
    outListFile.close();

    ifstream inListFile;
    inListFile.open("list.txt");

    for (int i = 0; i < 3; i++)
    {
        getline(inListFile, data);
        cout << display[i] << ": " << data << endl;
    }
    cout << "          ";
    inListFile >> data;
    cout << data << ", ";
    inListFile >> data;
    cout << data << ", ";
    inListFile >> data;
    cout << data;
    return 0;
}
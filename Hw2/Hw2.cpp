/* 
Hw2.cpp

CMSC 140, CRN 24381, Dr. Kuijt
Max C.

Prints my (on separate lines):

- name
- address, with the city, state, and ZIP code
- telephone number
- college major

While using a single `cout` statement
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // I decided to use \n instead of endl for convenience purposes
    cout << "First Last\nAddress\nPhone#\nDegree";
    return 0;
}
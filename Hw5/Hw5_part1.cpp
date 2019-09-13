/* 
Hw5_part1.cpp

CMSC 140, CRN 24381, Dr. Kuijt
Max C.

Use loops to display star patterns
*/

#include <iostream>
#include <string>

using namespace std;

// prototype functions
void starLine(int iter);
void triangle(int iter);
void upsideDownTriangle(int iter);

int main()
{
    starLine(10);
    cout << "\n";
    starLine(20);
    cout << "\n";
    triangle(10);
    cout << "\n";
    triangle(20);
    cout << "\n";
    upsideDownTriangle(10);
    cout << "\n";
    upsideDownTriangle(20);
    cout << "\n";
    return 0;
}

void starLine(int iter)
{
    /*

    ***

    */
    for (int i = 0; i < iter; i++)
    {
        cout << "*";
    }
    cout << "\n";
}

void triangle(int iter)
{
    /*

    *
    **
    ***

    */
    for (int i = 0; i < iter; i++)
    {
        starLine(i + 1);
    }
}

void upsideDownTriangle(int iter)
{
    /*

    ***
    **
    *
    
    */
    for (int i = iter; i > 0; i--)
    {
        starLine(i);
    }
}

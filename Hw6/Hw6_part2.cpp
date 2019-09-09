/* 
Hw6_part2.cpp

CMSC 140, CRN 24381, Dr. Kuijt
Max C.

Create a soda vending machine with payment + tax.
*/

#include <iostream>

using namespace std;

double showMenu()
{
    int input;
    cout << "**** Vending Machine****\n"
         << endl;

    cout << "1. Coke $1.25\n2. Pepsi $1.00\n3. Water $2.00\n4. Coffee $1.50\n5. Exit Menu";

    cout << "\nEnter your choice: ";
    cin >> input;

    switch (input)
    {
    case 1:
        // Coke
        return 1.25;
        break;
    case 2:
        // Pepsi
        return 1;
        break;
    case 3:
        // Water
        return 2;
        break;
    case 4:
        // Coffee
        return 1.5;
        break;
    case 5:
        // Exit Menu
        return -1;
        break;
    default:
        cout << "Invalid input, redisplaying menu...\n";
        return showMenu();
        break;
    }
}

double takePurchase(double price)
{
    int input;
    cout << "How many do you want? ";
    cin >> input;
    return input * price;
}

double takePayment()
{
    double input;
    cout << "How much is your payment? ";
    cin >> input;
    return input;
}

void displayInfo(double purchase, double payment)
{
    double tax, totalPurchase, change;

    totalPurchase = purchase * 1.06;
    tax = purchase * 0.06;

    if (totalPurchase > payment)
    {
        cout << "Insufficient Funds.\nQuitting...";
        return;
    }
    cout << "\n\nTax Amount: $" << tax;
    cout << "\n\nTotal Purchase: $" << totalPurchase;
    cout << "\n\nChange: $" << payment - totalPurchase;
}

int main()
{
    double price, payment;
    price = showMenu();
    // If user selected to exit
    if (price == -1)
        return 0;
    price = takePurchase(price);
    payment = takePayment();
    displayInfo(price, payment);

    return 0;
}
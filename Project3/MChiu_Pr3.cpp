#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
     // Init Variables
     int num = 1, totalFloors, totalRooms, occupiedRooms, occuRate;
     bool validated = false;
     string location;

     const int singleRate = 60, doubleRate = 75, kingRate = 100, suiteRate = 150, rates[4] = {singleRate, doubleRate, kingRate, suiteRate};

     const string programmerName = "Max Chiu", dueDate = "1/1/1";
     const int assignNum = 3;

     // Begin
     cout << setfill('=') << setw(50) << "\n"
          << setfill(' ') << setw(30) << "BlueMont Hotel\n"
          << setfill('=') << setw(50) << "\n"
          << "Enter the location of this hotel chain: ";
     cin >> location;

     // Asks for # floors. 1 <= total <= 5
     do
     {
          validated = true;
          cout << "Enter total number of floors of the hotel: ";
          cin >> totalFloors;

          if (totalFloors >= 1 && totalFloors <= 5)
          {
               cout << "Number of floors should be between 1 and 5 !! Please try again.";
               validated = false;
          }
     } while (!validated);

     // Asks for # rooms. 1 <= total <= 30
     do
     {
          validated = true;
          cout << "Enter total number of rooms in the " << num << "th Floor: ";
          cin >> totalRooms;

          if (totalRooms >= 1 && totalRooms <= 30)
          {
               cout << "Number of rooms should be between 1 and 30 !! Please try again.";
               validated = false;
          }
     } while (!validated);

     // Asks for # rooms occupied. 1 <= total <= total # of rooms
     do
     {
          cout << "How many SINGLE rooms are occupied in the " << num << "th Floor: ";

          cout << "How many DOUBLE rooms are occupied in the 1th floor: ";

          cout << "How many KING rooms are occupied in the 1th floor: ";

          cout << "How many SUITE are occupied in the 1th floor: ";
     } while (!validated);

     // Output calculations/earnings
     cout << "\n\n"
          << setfill('=') << setw(100) << "\n"
          << setfill(' ') << setw(50) << "Bluemont Hotel located in " << location << endl
          << endl
          << setw(60) << "TODAY'S ROOM RATES (US$/night)\n\n"
          << setw(20) << "Single Room" << setw(20) << "Double Room" << setw(20) << "King Room" << setw(20) << "Suite Room"
          << "\n\n"
          << setw(20) << singleRate << setw(20) << doubleRate << setw(20) << kingRate << setw(20) << suiteRate << "\n\n"
          << setfill('=') << setw(100) << "\n";

     cout << "Hotel Income:"
          << "Total # of rooms:"
          << "Total # Occupied Rooms:"
          << "Total # Unoccupied Rooms:"
          << "Occupancy Rate";

     if (occuRate < 60)
          cout << "Need to improve Hotel occupancy rate!!";

     // Outro
     cout << "Thank you for testing my program!!\n"
          << "PROGRAMMER: " << programmerName << endl
          << "CMSC140 Common Project " << assignNum << endl
          << "Due Date: " << dueDate;

     return 0;
}
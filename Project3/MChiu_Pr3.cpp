/*
 * Class: CMSC140 CRN 24381
 * Instructor: Dr. Kuijt
 * Project 3
 * Description: BlueMont hotel chain program that assists in calculating occupancy rate and total hotel income for one night. Along with other small info as well.
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
          * Hotel Rate Information (Pricing of each type of room)
          * Credits (Programmer name, project number, due date)
     - variables
          * Building information (floors, rooms, occupied rooms, total cost, unoccupied rooms)
          * user inputs (Number of floors, rooms, occupied rooms)
  2. Introduction
     - Welcome banner
     - Ask for location of hotel chain
     - User inputs location
  3. Building Information
     - Asks for number of floors
          * User inputs a number between 1 and 5
     - For each floor, ask for the number of rooms
          * User inputs numbers between 1 and 30
     - For each floor, ask for the type of rooms that are occupied
          * User inputs numbers between 0 and the # of rooms on the current floor
          * Total of rooms occupied must not exceed the # of rooms on floor
  4. Output statistics/details
     - Prints a banner with information about the hotel located at a user specified location (room rate in US$/night)
     - Prints statistics regarding the night (income, # of rooms, occupancy rate)
     - Prints the floor with the least number of rooms
     - If hotel occupancy < 60% print an encouraging message to improve occupancy rates.
  5. Outro
     - Programmer name, assignment #, due date
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
     // Init Variables
     int totalCost = 0, totalFloors = 0, totalRooms = 0, occupiedRooms = 0, tempUserInput;
     // Rooms by floor. Used to get floor with least # of rooms
     int roomsByFloor[5];
     bool validated = false;
     string location;

     // Room Rates
     const int singleRate = 60, doubleRate = 75, kingRate = 100, suiteRate = 150, rates[4] = {singleRate, doubleRate, kingRate, suiteRate};
     const string roomName[4] = {"SINGLE rooms", "DOUBLE rooms", "KING rooms", "SUITES"};

     const string programmerName = "Max Chiu", dueDate = "11/11/19";
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
          cout << "\nEnter total number of floors of the hotel: ";
          cin >> totalFloors;

          if (!(totalFloors >= 1 && totalFloors <= 5))
          {
               cout << "Number of floors should be between 1 and 5 !! Please try again.\n";
               validated = false;
          }
     } while (!validated);

     // Asks for # rooms by floor. 1 <= total <= 30
     for (int i = 1; i < totalFloors + 1; i++)
     {
          do
          {
               // temp variables for floor by floor input validation
               int tempTotalRooms = 0, tempTotalCost = 0, tempFloorRooms;
               validated = true;

               cout << "\nEnter total number of rooms in the " << i << "th Floor: ";
               cin >> tempFloorRooms;

               if (!(tempFloorRooms >= 1 && tempFloorRooms <= 30))
               {
                    cout << "Number of rooms should be between 1 and 30 !! Please try again.\n";
                    validated = false;
                    continue;
               }

               // appending # rooms to array for later when checking which floor has the least # of rooms
               roomsByFloor[i - 1] = tempFloorRooms;

               // Asks for # rooms occupied for each type on floor i. 1 <= total <= total # of rooms on current floor
               for (int j = 0; j < 4; j++)
               {
                    cout << "How many " << roomName[j] << " are occupied in the " << i << "th Floor: ";
                    cin >> tempUserInput;
                    if (tempUserInput < 0)
                    {
                         cout << "You cannot have a negative number of rooms. Please try again!!\n";
                         validated = false;
                         break;
                    }

                    tempTotalRooms += tempUserInput;
                    tempTotalCost += tempUserInput * rates[j];
               }

               if (tempTotalRooms > tempFloorRooms && validated)
               {
                    cout << "Total number of occupied rooms exceeds the total number of rooms on this floor. Please try again!!\n";
                    validated = false;
                    continue;
               }
               if (validated)
               {
                    // once validated, these sums can be added
                    totalCost += tempTotalCost;
                    totalRooms += tempFloorRooms;
                    occupiedRooms += tempTotalRooms;
               }
          } while (!validated);
     }

     // Output calculations/earnings
     cout << "\n\n"
          << setfill('=') << setw(80) << "\n"
          << setfill(' ') << setw(50) << "Bluemont Hotel located in " << location << endl
          << endl
          << setw(60) << "TODAY'S ROOM RATES (US$/night)\n\n"
          << setw(20) << "Single Room" << setw(20) << "Double Room" << setw(20) << "King Room" << setw(20) << "Suite Room"
          << "\n\n"
          << setw(20) << singleRate << setw(20) << doubleRate << setw(20) << kingRate << setw(20) << suiteRate << "\n\n"
          << setfill('=') << setw(80) << "\n";

     // Total Stats of the night
     cout << setfill(' ') << setw(30) << "Hotel Income: " << setw(15) << "$" << fixed << setprecision(2) << (double)totalCost << endl
          << setw(30) << "Total # of rooms: " << setw(15) << totalRooms << endl
          << setw(30) << "Total # Occupied Rooms: " << setw(15) << occupiedRooms << endl
          << setw(30) << "Total # Unoccupied Rooms: " << setw(15) << totalRooms - occupiedRooms << endl
          << setw(30) << "Occupancy Rate: " << fixed << setprecision(2) << setw(15) << (((double)occupiedRooms / (double)totalRooms) * 100) << "%\n\n";

     // Looping through all the rooms to get the floor with the least number of rooms.
     // Starts at 1 because the array[0] item in an array is the first item in it.
     int min = roomsByFloor[0], minIndex = 1;
     for (int i = 1; i < totalFloors; i++)
     {
          if (min > roomsByFloor[i])
          {
               min = roomsByFloor[i];
               minIndex = i + 1;
          }
     }
     cout << minIndex << "th Floor with " << min << " rooms, has the least number of rooms\n";
     // Check if occupancy rate is below 60 percent
     if ((((double)occupiedRooms / (double)totalRooms) * 100) < 60)
          cout << "Need to improve Hotel occupancy rate!!\n\n";

     // Outro
     cout << "Thank you for testing my program!!\n"
          << "PROGRAMMER: " << programmerName << endl
          << "CMSC140 Common Project " << assignNum << endl
          << "Due Date: " << dueDate;

     return 0;
}
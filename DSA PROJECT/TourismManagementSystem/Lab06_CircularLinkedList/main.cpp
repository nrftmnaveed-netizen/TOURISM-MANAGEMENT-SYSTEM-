// ---------------------------------------------------------
// MAIN FILE - Lab 06 (Individual Project)
// Sightseeing Bus Route using a Circular Linked List
// ---------------------------------------------------------
#include <iostream>
#include <string>
#include <limits>
#include "Destination.h"
#include "CircularLinkedList.h"
using namespace std;

// Read an integer safely
int ReadInt(const string& prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a number.\n";
    }
}

// Read a full line of text
string ReadLine(const string& prompt)
{
    string text;
    cout << prompt;
    getline(cin, text);
    return text;
}

// Build a destination node from user input
DestinationNode* ReadDestination()
{
    int id = ReadInt("Enter destination ID: ");
    string name = ReadLine("Enter destination name: ");
    string city = ReadLine("Enter city: ");
    return new DestinationNode(id, name, city);
}

void ShowMenu()
{
    cout << "\n========================================\n";
    cout << "  SIGHTSEEING BUS ROUTE (CIRCULAR LIST)\n";
    cout << "========================================\n";
    cout << "1.  Display All Destinations\n";
    cout << "2.  Insert Destination at Head\n";
    cout << "3.  Remove Destination from Head\n";
    cout << "4.  Insert Destination at Index\n";
    cout << "5.  Remove Destination at Index\n";
    cout << "6.  Swap Destinations\n";
    cout << "7.  Sort Destinations by ID\n";
    cout << "8.  Reverse Route\n";
    cout << "9.  Move Bus to Next Destination\n";
    cout << "10. Show Bus Rotation (wraps around)\n";
    cout << "11. Verify Circular Link (last -> first)\n";
    cout << "12. Check Route Status\n";
    cout << "13. Exit\n";
}

int main()
{
    CircularLinkedList route;

    // Demonstration data of the project (pre-loaded)
    route.InsertAt(new DestinationNode(103, "Hunza Valley", "Gilgit"), 0);
    route.InsertAt(new DestinationNode(101, "Lahore Fort", "Lahore"), 1);
    route.InsertAt(new DestinationNode(104, "Skardu Lakes", "Skardu"), 2);
    route.InsertAt(new DestinationNode(102, "Murree Hills", "Murree"), 3);

    int choice = 0;
    do
    {
        ShowMenu();
        choice = ReadInt("Enter your choice: ");

        switch (choice)
        {
        case 1:
            route.Print();
            break;

        case 2:   // insert next to pivot
            route.Insert(ReadDestination());
            cout << "Destination inserted at head.\n";
            break;

        case 3:   // remove next to pivot
        {
            DestinationNode* removed = route.Remove();
            if (removed == nullptr)
                cout << "Route is empty.\n";
            else
            {
                cout << "Removed: " << removed->name << endl;
                delete removed;   // free removed node
            }
            break;
        }

        case 4:
        {
            int index = ReadInt("Enter index (wraps if out of range): ");
            route.InsertAt(ReadDestination(), index);
            cout << "Destination inserted.\n";
            break;
        }

        case 5:
        {
            if (route.IsEmpty())
            {
                cout << "Route is empty.\n";
                break;
            }
            int index = ReadInt("Enter index (wraps if out of range): ");
            DestinationNode* removed = route.RemoveAt(index);
            cout << "Removed: " << removed->name << endl;
            delete removed;
            break;
        }

        case 6:
        {
            int a = ReadInt("Enter first index: ");
            int b = ReadInt("Enter second index: ");
            route.Swap(a, b);
            cout << "Swap done.\n";
            break;
        }

        case 7:
            route.Sort();
            cout << "Sorted by destination ID.\n";
            break;

        case 8:
            route.Reverse();
            cout << "Route reversed.\n";
            break;

        case 9:   // move display one step around the circle
        {
            DestinationNode* destination = route.MoveToNext();
            if (destination == nullptr)
                cout << "Route is empty.\n";
            else
                cout << "Bus now at: " << destination->name << endl;
            break;
        }

        case 10:  // show repeated rotation without reaching nullptr
        {
            int turns = ReadInt("How many turns to show? ");
            route.PrintRotation(turns);
            break;
        }

        case 11:
            route.VerifyCircular();
            break;

        case 12:
            if (route.IsEmpty())
                cout << "Status: EMPTY\n";
            else if (route.IsNotEmpty())
                cout << "Status: NOT EMPTY (" << route.GetCount() << " destinations)\n";
            break;

        case 13:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Enter 1-13.\n";
        }
    } while (choice != 13);

    return 0;
}

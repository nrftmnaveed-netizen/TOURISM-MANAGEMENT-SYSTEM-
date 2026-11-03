// ---------------------------------------------------------
// MAIN FILE - Lab 05 (Individual Project)
// Tour Destination List using a Singly Linked List
// ---------------------------------------------------------
#include <iostream>
#include <string>
#include <limits>
#include "Destination.h"
#include "LinkedList.h"
using namespace std;

// Read an integer safely (keeps asking until the input is valid)
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
        cin.clear();                                            // clear error
        cin.ignore(numeric_limits<streamsize>::max(), '\n');    // discard bad input
        cout << "Invalid input. Enter a number.\n";
    }
}

// Read one full line of text (allows spaces)
string ReadLine(const string& prompt)
{
    string text;
    cout << prompt;
    getline(cin, text);
    return text;
}

// Ask the user for destination details and build a node
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
    cout << "   TOUR DESTINATION LIST (SINGLY LIST)\n";
    cout << "========================================\n";
    cout << "1.  Display All Destinations\n";
    cout << "2.  Add Destination at Head\n";
    cout << "3.  Remove Destination from Head\n";
    cout << "4.  Add Destination at Index\n";
    cout << "5.  Remove Destination at Index\n";
    cout << "6.  Swap Two Destinations\n";
    cout << "7.  Sort Destinations by ID\n";
    cout << "8.  Reverse Destination List\n";
    cout << "9.  Check List Status\n";
    cout << "10. Exit\n";
}

int main()
{
    LinkedList destinations;

    // Demonstration data of the project (pre-loaded)
    destinations.InsertAt(new DestinationNode(103, "Hunza Valley", "Gilgit"), 0);
    destinations.InsertAt(new DestinationNode(101, "Lahore Fort", "Lahore"), 1);
    destinations.InsertAt(new DestinationNode(105, "Naran Kaghan", "Mansehra"), 2);
    destinations.InsertAt(new DestinationNode(102, "Murree Hills", "Murree"), 3);

    int choice = 0;
    do
    {
        ShowMenu();
        choice = ReadInt("Enter your choice: ");

        switch (choice)
        {
        case 1:   // show every destination
            destinations.Print();
            break;

        case 2:   // insert at head
            destinations.Insert(ReadDestination());
            cout << "Destination added at head.\n";
            break;

        case 3:   // remove from head
        {
            DestinationNode* removed = destinations.Remove();
            if (removed == nullptr)
                cout << "List is empty.\n";
            else
            {
                cout << "Removed: " << removed->name << endl;
                delete removed;   // free memory of removed node
            }
            break;
        }

        case 4:   // insert at index
        {
            int index = ReadInt("Enter index: ");
            destinations.InsertAt(ReadDestination(), index);
            cout << "Destination added.\n";
            break;
        }

        case 5:   // remove at index
        {
            if (destinations.IsEmpty())
            {
                cout << "List is empty.\n";
                break;
            }
            int index = ReadInt("Enter index to remove: ");
            DestinationNode* removed = destinations.RemoveAt(index);
            cout << "Removed: " << removed->name << endl;
            delete removed;
            break;
        }

        case 6:   // swap two destinations
        {
            int a = ReadInt("Enter first index: ");
            int b = ReadInt("Enter second index: ");
            if (destinations.Swap(a, b))
                cout << "Destinations swapped.\n";
            else
                cout << "Invalid index.\n";
            break;
        }

        case 7:
            destinations.Sort();
            cout << "Sorted by destination ID.\n";
            break;

        case 8:
            destinations.Reverse();
            cout << "List reversed.\n";
            break;

        case 9:   // status check using IsEmpty / IsNotEmpty
            if (destinations.IsEmpty())
                cout << "Status: EMPTY\n";
            else if (destinations.IsNotEmpty())
                cout << "Status: NOT EMPTY (" << destinations.GetCount() << " destinations)\n";
            break;

        case 10:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Enter 1-10.\n";
        }
    } while (choice != 10);   // repeat until Exit

    return 0;
}

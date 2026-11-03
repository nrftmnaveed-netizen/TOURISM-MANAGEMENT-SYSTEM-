// ---------------------------------------------------------
// MAIN FILE - Lab 07 (Individual Project)
// Tourist Travel Itinerary Navigator using a Doubly Linked List
// ---------------------------------------------------------
#include <iostream>
#include <string>
#include <limits>
#include "Destination.h"
#include "DoublyLinkedList.h"
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

// Build a name node from user input
DestinationNode* ReadDestination()
{
    int id = ReadInt("Enter destination ID: ");
    string name = ReadLine("Enter name: ");
    string city = ReadLine("Enter city name: ");
    return new DestinationNode(id, name, city);
}

void ShowMenu()
{
    cout << "\n========================================\n";
    cout << " TRAVEL ITINERARY NAVIGATOR (DOUBLY LIST)\n";
    cout << "========================================\n";
    cout << "1. Display Current Destination\n";
    cout << "2. Move to Next Destination\n";
    cout << "3. Move to Previous Destination\n";
    cout << "4. Add Destination at the End\n";
    cout << "5. Insert Destination After Current\n";
    cout << "6. Remove Current Destination\n";
    cout << "7. Display Itinerary from First to Last\n";
    cout << "8. Display Itinerary from Last to First\n";
    cout << "9. Exit\n";
}

int main()
{
    DoublyLinkedList itinerary;

    // Demonstration data: destinations in a tourist travel itinerary
    itinerary.InsertRight(new DestinationNode(101, "Lahore Fort", "Lahore"));
    itinerary.InsertRight(new DestinationNode(102, "Faisal Mosque", "Islamabad"));
    itinerary.InsertRight(new DestinationNode(103, "Hunza Valley", "Gilgit"));

    int choice = 0;
    do
    {
        ShowMenu();
        choice = ReadInt("Enter your choice: ");

        switch (choice)
        {
        case 1:
            itinerary.PrintCurrent();
            break;

        case 2:   // forward navigation
            if (itinerary.Next())
                itinerary.PrintCurrent();
            else
                cout << "No next name.\n";
            break;

        case 3:   // backward navigation
            if (itinerary.Previous())
                itinerary.PrintCurrent();
            else
                cout << "No previous name.\n";
            break;

        case 4:
            itinerary.InsertRight(ReadDestination());
            cout << "Destination added at the end.\n";
            break;

        case 5:
            itinerary.InsertAfterCurrent(ReadDestination());
            cout << "Destination inserted after current.\n";
            break;

        case 6:   // remove the entry being reviewed
        {
            DestinationNode* removed = itinerary.RemoveCurrent();
            if (removed == nullptr)
                cout << "Itinerary is empty.\n";
            else
            {
                cout << "Removed: " << removed->name << endl;
                delete removed;   // free removed node
                itinerary.PrintCurrent();
            }
            break;
        }

        case 7:
            itinerary.PrintForward();
            break;

        case 8:
            itinerary.PrintBackward();
            break;

        case 9:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Enter 1-9.\n";
        }
    } while (choice != 9);

    return 0;
}

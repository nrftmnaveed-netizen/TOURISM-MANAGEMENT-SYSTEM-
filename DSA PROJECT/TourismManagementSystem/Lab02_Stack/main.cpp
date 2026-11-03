// ---------------------------------------------------------
// MAIN FILE - Lab 02 (Individual Project)
// Tourist Return-Journey Tracker using a Stack (LIFO)
// ---------------------------------------------------------
#include <iostream>
#include <string>
#include <limits>
#include "Destination.h"
#include "Stack.h"
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
    cout << "   TOURIST RETURN JOURNEY (STACK)\n";
    cout << "========================================\n";
    cout << "1. Visit New Destination (Push)\n";
    cout << "2. Go Back to Last Destination (Pop)\n";
    cout << "3. View Last Visited Destination (Top)\n";
    cout << "4. Check if Stack is Empty\n";
    cout << "5. Check if Stack is Not Empty\n";
    cout << "6. Display All Visited Destinations\n";
    cout << "7. Test Copy Constructor and Assignment\n";
    cout << "8. Exit\n";
}

int main()
{
    Stack journey;

    // Demonstration data: the tourist has already visited these places
    journey.Push(new DestinationNode(1, "Lahore Fort", "Lahore"));
    journey.Push(new DestinationNode(2, "Faisal Mosque", "Islamabad"));
    journey.Push(new DestinationNode(3, "Naran Kaghan", "Mansehra"));

    int choice = 0;
    do
    {
        ShowMenu();
        choice = ReadInt("Enter your choice: ");

        switch (choice)
        {
        case 1:   // Push
            journey.Push(ReadDestination());
            cout << "Destination added to the top of the stack.\n";
            break;

        case 2:   // Pop
        {
            DestinationNode* removed = journey.Pop();
            if (removed == nullptr)
                cout << "Stack is empty. Nothing to go back to.\n";
            else
            {
                cout << "Going back from: " << removed->name << endl;
                delete removed;   // free memory of removed node
            }
            break;
        }

        case 3:   // Peek
        {
            DestinationNode* top = journey.GetTopValue();
            if (top == nullptr)
                cout << "Stack is empty.\n";
            else
                cout << "Last visited: " << top->name
                     << " (" << top->city << ")\n";
            break;
        }

        case 4:
            cout << (journey.IsEmpty() ? "Stack is EMPTY.\n"
                                       : "Stack is NOT empty.\n");
            break;

        case 5:
            cout << (journey.IsNotEmpty() ? "Stack contains destinations.\n"
                                          : "Stack has no destinations.\n");
            break;

        case 6:
            journey.PrintStack();
            break;

        case 7:   // prove the copy is independent from the original
        {
            Stack copied(journey);     // copy constructor
            Stack assigned;
            assigned = journey;        // assignment operator

            // changing the copy must not change the original
            DestinationNode* removed = copied.Pop();
            delete removed;
            cout << "Original has " << journey.GetCount()
                 << " destinations, copy (after one Pop) has "
                 << copied.GetCount() << ", assigned has "
                 << assigned.GetCount() << ".\n";
            break;
        }

        case 8:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Enter 1-8.\n";
        }
    } while (choice != 8);

    return 0;
}

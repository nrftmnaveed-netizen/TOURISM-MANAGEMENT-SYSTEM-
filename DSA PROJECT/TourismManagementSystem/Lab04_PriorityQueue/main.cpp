// ---------------------------------------------------------
// MAIN FILE - Lab 04 (Individual Project)
// Tourist Support Desk using a Priority Queue
// ---------------------------------------------------------
#include <iostream>
#include <string>
#include <limits>
#include "SupportRequest.h"
#include "PriorityQueue.h"
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

// Keep asking until the priority is 1, 2 or 3
int ReadPriority()
{
    int priority;
    do
    {
        priority = ReadInt("Enter Priority (1=Emergency, 2=Booking problem, 3=General): ");
        if (priority < 1 || priority > 3)
            cout << "Priority must be 1, 2 or 3.\n";
    } while (priority < 1 || priority > 3);
    return priority;
}

void ShowMenu()
{
    cout << "\nTourist Support Request System\n";
    cout << "1. Add Support Request\n";
    cout << "2. Process Highest Priority Request\n";
    cout << "3. Display All Requests\n";
    cout << "4. Check Queue Status\n";
    cout << "5. Exit\n";
}

int main()
{
    PriorityQueue requests;

    // Demonstration data (arrives in this order)
    requests.Add(new SupportRequestNode(101, "Ali", "Need hotel suggestions", 3));
    requests.Add(new SupportRequestNode(102, "Ahmed", "Injured on a hiking trail", 1));
    requests.Add(new SupportRequestNode(103, "Bilal", "Tour booking was cancelled", 2));
    requests.Add(new SupportRequestNode(104, "Hamza", "Lost passport at the airport", 1));

    int choice = 0;
    do
    {
        ShowMenu();
        choice = ReadInt("Enter your choice: ");

        switch (choice)
        {
        case 1:   // build node dynamically and add it by priority
        {
            int id = ReadInt("Enter Tourist ID: ");
            string name = ReadLine("Enter Tourist Name: ");
            string issue = ReadLine("Enter Issue: ");
            int priority = ReadPriority();
            requests.Add(new SupportRequestNode(id, name, issue, priority));
            cout << "Request added.\n";
            break;
        }

        case 2:   // process the most urgent request
        {
            SupportRequestNode* processed = requests.Remove();
            if (processed == nullptr)
                cout << "No pending requests.\n";
            else
            {
                cout << "\nProcessing request:\n";
                cout << "Tourist: " << processed->touristName << endl;
                cout << "Issue: " << processed->issue << endl;
                cout << "Priority: " << processed->priority << endl;
                delete processed;   // free memory
            }
            break;
        }

        case 3:
            requests.PrintQueue();
            break;

        case 4:   // status using IsEmpty / IsNotEmpty
            if (requests.IsEmpty())
                cout << "Queue status: EMPTY\n";
            else if (requests.IsNotEmpty())
                cout << "Queue status: NOT EMPTY ("
                     << requests.GetCount() << " pending)\n";
            break;

        case 5:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Enter 1-5.\n";
        }
    } while (choice != 5);

    return 0;   // destructor releases remaining nodes automatically
}

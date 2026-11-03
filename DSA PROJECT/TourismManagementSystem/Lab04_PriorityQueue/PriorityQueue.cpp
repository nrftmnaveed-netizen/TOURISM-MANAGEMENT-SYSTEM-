// ---------------------------------------------------------
// CLASS MEMBER FUNCTION FILE
// Definitions of all PriorityQueue member functions
// ---------------------------------------------------------
#include <iostream>
#include "PriorityQueue.h"
using namespace std;

// Constructor: empty queue
PriorityQueue::PriorityQueue()
{
    front = nullptr;
    rear = nullptr;
    count = 0;
}

// Copy constructor: independent copy of all requests
PriorityQueue::PriorityQueue(const PriorityQueue& other)
{
    front = nullptr;
    rear = nullptr;
    count = 0;
    CopyFrom(other);
}

// Assignment operator: replace contents with a copy of 'other'
PriorityQueue& PriorityQueue::operator=(const PriorityQueue& other)
{
    if (this == &other)   // guard against self-assignment
        return *this;
    Clear();
    CopyFrom(other);
    return *this;
}

// Destructor: release all nodes
PriorityQueue::~PriorityQueue()
{
    Clear();
}

// Delete every request
void PriorityQueue::Clear()
{
    while (IsNotEmpty())
        delete Remove();
}

// Copy by creating new nodes and adding them with Add()
void PriorityQueue::CopyFrom(const PriorityQueue& other)
{
    for (SupportRequestNode* current = other.front; current != nullptr;
         current = current->next)
    {
        Add(new SupportRequestNode(current->touristID, current->touristName,
                                   current->issue, current->priority));
    }
}

// Add: insert the request at the correct place according to priority
void PriorityQueue::Add(SupportRequestNode* request)
{
    if (request == nullptr)
        return;
    request->next = nullptr;

    // Case 1: queue is empty -> request is front and rear
    if (front == nullptr)
    {
        front = rear = request;
    }
    // Case 2: new request is more urgent than the front -> becomes new front
    else if (request->priority < front->priority)
    {
        request->next = front;
        front = request;
    }
    // Case 3: find the last node with priority <= new priority,
    // then insert after it (equal priority keeps arrival order)
    else
    {
        SupportRequestNode* current = front;
        while (current->next != nullptr &&
               current->next->priority <= request->priority)
        {
            current = current->next;
        }
        request->next = current->next;
        current->next = request;

        // if inserted at the very end, update rear
        if (request->next == nullptr)
            rear = request;
    }
    count++;
}

// Remove: take out the highest-priority request (front)
SupportRequestNode* PriorityQueue::Remove()
{
    if (front == nullptr)
        return nullptr;

    SupportRequestNode* request = front;
    front = front->next;
    if (front == nullptr)
        rear = nullptr;        // queue became empty
    request->next = nullptr;
    count--;
    return request;            // caller deletes it
}

bool PriorityQueue::IsEmpty() const { return front == nullptr; }
bool PriorityQueue::IsNotEmpty() const { return front != nullptr; }
int PriorityQueue::GetCount() const { return count; }

// Print all pending requests from highest to lowest priority
void PriorityQueue::PrintQueue() const
{
    if (IsEmpty())
    {
        cout << "\nNo pending requests.\n";
        return;
    }
    cout << "\n";
    for (SupportRequestNode* current = front; current != nullptr;
         current = current->next)
    {
        cout << "Tourist ID: " << current->touristID << endl;
        cout << "Tourist Name: " << current->touristName << endl;
        cout << "Issue: " << current->issue << endl;
        cout << "Priority: " << current->priority << endl;
        cout << "-----------------------------" << endl;
    }
    cout << "Total pending requests: " << count << endl;
}

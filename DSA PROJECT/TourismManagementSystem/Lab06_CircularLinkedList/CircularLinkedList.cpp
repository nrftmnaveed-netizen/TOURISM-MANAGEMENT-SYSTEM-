// ---------------------------------------------------------
// CLASS MEMBER FUNCTION FILE
// Definitions of all CircularLinkedList member functions
// ---------------------------------------------------------
#include <iostream>
#include <utility>
#include "CircularLinkedList.h"
using namespace std;

// Constructor: empty route
CircularLinkedList::CircularLinkedList()
{
    head = nullptr;
    busStop = nullptr;
    count = 0;
}

// Destructor: delete all nodes
CircularLinkedList::~CircularLinkedList()
{
    while (IsNotEmpty())
        delete Remove();
}

// Return node at index, counting from the first node (head->next)
DestinationNode* CircularLinkedList::GetNodeAt(int index)
{
    if (head == nullptr)
        return nullptr;
    DestinationNode* current = head->next;   // first node
    for (int i = 0; i < index; i++)
        current = current->next;
    return current;
}

// Exchange data (not links) of two nodes
void CircularLinkedList::SwapData(DestinationNode* a, DestinationNode* b)
{
    swap(a->destinationID, b->destinationID);
    swap(a->name, b->name);
    swap(a->city, b->city);
}

// Map any integer (even negative or huge) into 0..count-1
int CircularLinkedList::NormalizeIndex(int index) const
{
    return ((index % count) + count) % count;
}

// Insert as the first node (the node next to the pivot)
void CircularLinkedList::Insert(DestinationNode* destination)
{
    if (destination == nullptr)
        return;

    if (head == nullptr)
    {
        // first destination: points to itself, forming a circle of one
        head = destination;
        destination->next = destination;
        busStop = destination;
    }
    else
    {
        // put the new node between pivot and old first node
        destination->next = head->next;
        head->next = destination;
    }
    count++;
}

// Remove the first node (the node next to the pivot)
DestinationNode* CircularLinkedList::Remove()
{
    if (IsEmpty())
        return nullptr;

    DestinationNode* first = head->next;

    // if the removed destination is where the bus is, the bus moves to the next stop
    if (busStop == first)
        busStop = (first == head) ? nullptr : first->next;

    if (first == head)
        head = nullptr;            // it was the only node
    else
        head->next = first->next;  // pivot now skips the removed node

    first->next = nullptr;
    count--;
    return first;
}

// Insert at an index; wraps around the circle if index is out of range
void CircularLinkedList::InsertAt(DestinationNode* destination, int index)
{
    if (destination == nullptr)
        return;

    // empty list: same as a normal first insert
    if (count == 0)
    {
        Insert(destination);
        return;
    }

    if (index < 0)
        index = NormalizeIndex(index);   // negative index wraps around
    if (index > count)
        index %= count;                  // too large index wraps around

    if (index == 0)                      // insert at front
    {
        Insert(destination);
        return;
    }

    if (index == count)                  // insert at end: becomes new pivot
    {
        destination->next = head->next;
        head->next = destination;
        head = destination;
        count++;
        return;
    }

    // insert in the middle, after the node at (index - 1)
    DestinationNode* previous = GetNodeAt(index - 1);
    destination->next = previous->next;
    previous->next = destination;
    count++;
}

// Remove at an index; index wraps around the circle
DestinationNode* CircularLinkedList::RemoveAt(int index)
{
    if (IsEmpty())
        return nullptr;

    index = NormalizeIndex(index);
    if (index == 0)
        return Remove();

    DestinationNode* previous = GetNodeAt(index - 1);
    DestinationNode* target = previous->next;

    // the bus moves forward if the removed destination was where the bus was
    if (busStop == target)
        busStop = target->next;

    previous->next = target->next;   // bypass the removed node
    if (target == head)
        head = previous;             // removed the last node -> new pivot

    target->next = nullptr;
    count--;
    return target;
}

// Swap two destinations' data; indexes wrap around
void CircularLinkedList::Swap(int index1, int index2)
{
    if (IsEmpty())
        return;
    index1 = NormalizeIndex(index1);
    index2 = NormalizeIndex(index2);
    if (index1 != index2)
        SwapData(GetNodeAt(index1), GetNodeAt(index2));
}

// Sort ascending by destinationID
void CircularLinkedList::Sort()
{
    if (count < 2)
        return;

    DestinationNode* current = head->next;
    // outer loop: fix one position at a time
    for (int i = 0; i < count - 1; i++)
    {
        DestinationNode* nextNode = current->next;
        // inner loop: compare with every later node (count-based, no nullptr)
        for (int j = i + 1; j < count; j++)
        {
            if (current->destinationID > nextNode->destinationID)
                SwapData(current, nextNode);
            nextNode = nextNode->next;
        }
        current = current->next;
    }
}

// Reverse the circle by flipping every 'next' pointer
void CircularLinkedList::Reverse()
{
    if (count < 2)
        return;

    DestinationNode* oldTail = head;          // old last node
    DestinationNode* oldFirst = head->next;   // old first node
    DestinationNode* previous = oldTail;
    DestinationNode* current = oldFirst;

    // flip links until we come back around to the old tail
    while (current != oldTail)
    {
        DestinationNode* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }
    oldTail->next = previous;   // old tail becomes the new first node
    head = oldFirst;            // old first becomes the new last (pivot)
}

// Print exactly 'count' nodes (a circle never reaches nullptr)
void CircularLinkedList::Print() const
{
    if (IsEmpty())
    {
        cout << "\nNo destinations in the route.\n";
        return;
    }
    cout << "\nIndex\tID\tName\t\tCity\n";
    cout << "-----------------------------------------------\n";
    DestinationNode* current = head->next;
    for (int i = 0; i < count; i++)
    {
        cout << i << "\t" << current->destinationID << "\t" << current->name
             << "\t\t" << current->city;
        if (current == busStop)
            cout << "  <-- BUS IS HERE";
        cout << endl;
        current = current->next;
    }
    cout << "Total destinations: " << count << endl;
}

// Move bus to the next destination; after the last destination it returns to the first
DestinationNode* CircularLinkedList::MoveToNext()
{
    if (IsEmpty())
        return nullptr;
    busStop = busStop->next;
    return busStop;
}

DestinationNode* CircularLinkedList::GetBusStop() const
{
    return busStop;
}

// Show the bus stops for N consecutive turns (wraps around the circle)
void CircularLinkedList::PrintRotation(int turns)
{
    if (IsEmpty())
    {
        cout << "No destinations in the route.\n";
        return;
    }
    DestinationNode* current = busStop;
    for (int turn = 1; turn <= turns; turn++)
    {
        cout << "Turn " << turn << ": " << current->name
             << " (" << current->city << ")\n";
        current = current->next;   // never becomes nullptr
    }
}

// Prove that the last node links back to the first node
void CircularLinkedList::VerifyCircular() const
{
    if (IsEmpty())
    {
        cout << "No destinations in the route.\n";
        return;
    }
    cout << "Last node : " << head->name << endl;
    cout << "First node: " << head->next->name << endl;
    if (head->next != nullptr)
        cout << "Last node's next pointer leads back to the first node: YES\n";
}

bool CircularLinkedList::IsEmpty() const { return count == 0; }
bool CircularLinkedList::IsNotEmpty() const { return count > 0; }
int CircularLinkedList::GetCount() const { return count; }

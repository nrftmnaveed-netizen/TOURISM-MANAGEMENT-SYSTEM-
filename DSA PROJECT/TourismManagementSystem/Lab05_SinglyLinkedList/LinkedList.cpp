// ---------------------------------------------------------
// CLASS MEMBER FUNCTION FILE
// Definitions of all LinkedList member functions
// ---------------------------------------------------------
#include <iostream>
#include <utility>
#include "LinkedList.h"
using namespace std;

// Constructor: start with an empty list
LinkedList::LinkedList()
{
    head = nullptr;
    count = 0;
}

// Destructor: delete every remaining node to avoid memory leaks
LinkedList::~LinkedList()
{
    while (IsNotEmpty())
        delete Remove();
}

// Walk from head and return the node at the given index
DestinationNode* LinkedList::GetNodeAt(int index)
{
    DestinationNode* current = head;
    // move forward 'index' times (stop early if list ends)
    for (int i = 0; i < index && current != nullptr; i++)
        current = current->next;
    return current;
}

// Exchange the data (not the links) of two nodes
void LinkedList::SwapData(DestinationNode* a, DestinationNode* b)
{
    swap(a->destinationID, b->destinationID);
    swap(a->name, b->name);
    swap(a->city, b->city);
}

// Insert at head: new node points to old head, then becomes head
void LinkedList::Insert(DestinationNode* destination)
{
    if (destination == nullptr)
        return;
    destination->next = head;
    head = destination;
    count++;
}

// Remove from head: head moves to the second node
DestinationNode* LinkedList::Remove()
{
    if (IsEmpty())
        return nullptr;
    DestinationNode* removed = head;
    head = head->next;
    removed->next = nullptr;   // fully detach the removed node
    count--;
    return removed;            // caller deletes it
}

// Insert at an index (invalid index is corrected into range)
void LinkedList::InsertAt(DestinationNode* destination, int index)
{
    if (destination == nullptr)
        return;

    // correct the index: below 0 -> 0, above count -> count (append)
    if (index < 0)
        index = 0;
    if (index > count)
        index = count;

    // index 0 is the same as inserting at head
    if (index == 0)
    {
        Insert(destination);
        return;
    }

    // otherwise find the node just before the insertion point
    DestinationNode* previous = GetNodeAt(index - 1);
    destination->next = previous->next;   // new node -> following node
    previous->next = destination;         // previous node -> new node
    count++;
}

// Remove at an index (invalid index is corrected into range)
DestinationNode* LinkedList::RemoveAt(int index)
{
    if (IsEmpty())
        return nullptr;

    if (index < 0)
        index = 0;
    if (index >= count)
        index = count - 1;

    // removing index 0 is the same as removing from head
    if (index == 0)
        return Remove();

    DestinationNode* previous = GetNodeAt(index - 1);
    DestinationNode* removed = previous->next;
    previous->next = removed->next;   // bypass the removed node
    removed->next = nullptr;
    count--;
    return removed;
}

// Swap two destinations; returns false if an index is invalid
bool LinkedList::Swap(int index1, int index2)
{
    if (index1 < 0 || index1 >= count || index2 < 0 || index2 >= count)
        return false;
    if (index1 != index2)
        SwapData(GetNodeAt(index1), GetNodeAt(index2));
    return true;
}

// Sort ascending by destinationID (compare each node with all later nodes)
void LinkedList::Sort()
{
    for (DestinationNode* i = head; i != nullptr; i = i->next)
    {
        for (DestinationNode* j = i->next; j != nullptr; j = j->next)
        {
            // if out of order, exchange their data
            if (i->destinationID > j->destinationID)
                SwapData(i, j);
        }
    }
}

// Reverse by flipping every 'next' pointer
void LinkedList::Reverse()
{
    DestinationNode* previous = nullptr;
    DestinationNode* current = head;
    while (current != nullptr)
    {
        DestinationNode* nextNode = current->next; // remember the rest
        current->next = previous;              // flip the link
        previous = current;                    // move both pointers ahead
        current = nextNode;
    }
    head = previous;   // last node is now the first
}

// Display all destinations with their index
void LinkedList::Print() const
{
    if (IsEmpty())
    {
        cout << "\nNo destinations in the list.\n";
        return;
    }
    cout << "\nIndex\tID\tName\t\tCity\n";
    cout << "-----------------------------------------------\n";
    DestinationNode* current = head;
    int index = 0;
    while (current != nullptr)
    {
        cout << index << "\t" << current->destinationID << "\t"
             << current->name << "\t\t" << current->city << endl;
        current = current->next;   // move to the next node
        index++;
    }
    cout << "Total destinations: " << count << endl;
}

bool LinkedList::IsEmpty() const { return head == nullptr; }
bool LinkedList::IsNotEmpty() const { return head != nullptr; }
int LinkedList::GetCount() const { return count; }

// ---------------------------------------------------------
// CLASS MEMBER FUNCTION FILE
// Definitions of all DoublyLinkedList member functions
// ---------------------------------------------------------
#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

// Constructor: empty itinerary
DoublyLinkedList::DoublyLinkedList()
{
    head = tail = current = nullptr;
    count = 0;
}

// Destructor: walk through the list and delete every node
DoublyLinkedList::~DoublyLinkedList()
{
    DestinationNode* node = head;
    while (node != nullptr)
    {
        DestinationNode* nextNode = node->right;  // save before deleting
        delete node;
        node = nextNode;
    }
}

// Add a new name at the end of the itinerary
void DoublyLinkedList::InsertRight(DestinationNode* node)
{
    if (node == nullptr)
        return;

    node->left = tail;       // new node looks back at old tail
    node->right = nullptr;   // nothing after the new node

    if (tail != nullptr)
        tail->right = node;  // old tail now points forward to new node
    else
        head = node;         // list was empty: new node is also the head

    tail = node;             // new node is the last one
    if (current == nullptr)
        current = node;      // first entry becomes the current one
    count++;
}

// Insert immediately after the current entry (4 links to update)
void DoublyLinkedList::InsertAfterCurrent(DestinationNode* node)
{
    if (node == nullptr)
        return;

    // empty list: behave like a normal insert
    if (current == nullptr)
    {
        InsertRight(node);
        return;
    }

    node->left = current;               // 1. new node's left = current
    node->right = current->right;       // 2. new node's right = old next

    if (current->right != nullptr)
        current->right->left = node;    // 3. old next looks back at new node
    else
        tail = node;                    // current was last, so new node is tail

    current->right = node;              // 4. current points forward to new node
    count++;
}

// Remove the current entry; neighbours are linked directly together
DestinationNode* DoublyLinkedList::RemoveCurrent()
{
    if (current == nullptr)
        return nullptr;

    DestinationNode* removed = current;
    DestinationNode* previous = current->left;
    DestinationNode* nextNode = current->right;

    // connect previous -> next (or update head if removing the first)
    if (previous != nullptr)
        previous->right = nextNode;
    else
        head = nextNode;

    // connect next -> previous (or update tail if removing the last)
    if (nextNode != nullptr)
        nextNode->left = previous;
    else
        tail = previous;

    // current moves to the next entry, or the previous one if none
    current = (nextNode != nullptr) ? nextNode : previous;

    removed->left = nullptr;
    removed->right = nullptr;
    count--;
    return removed;   // caller deletes it
}

// Move current one step forward; false if already at the end
bool DoublyLinkedList::Next()
{
    if (current != nullptr && current->right != nullptr)
    {
        current = current->right;
        return true;
    }
    return false;
}

// Move current one step backward; false if already at the start
bool DoublyLinkedList::Previous()
{
    if (current != nullptr && current->left != nullptr)
    {
        current = current->left;
        return true;
    }
    return false;
}

// Show the entry currently being reviewed
void DoublyLinkedList::PrintCurrent() const
{
    if (current == nullptr)
    {
        cout << "The travel itinerary is empty.\n";
        return;
    }
    cout << "Current Destination: " << current->destinationID << " - "
         << current->name << " (in " << current->city << ")\n";
}

// Print oldest -> newest following the 'right' pointers
void DoublyLinkedList::PrintForward() const
{
    cout << "\nTravel Itinerary (First to Last):\n";
    if (IsEmpty())
    {
        cout << "(empty)\n";
        return;
    }
    for (DestinationNode* node = head; node != nullptr; node = node->right)
    {
        cout << node->destinationID << " - " << node->name
             << " (in " << node->city << ")";
        if (node == current)
            cout << "  [CURRENT]";
        cout << endl;
    }
}

// Print newest -> oldest following the 'left' pointers
void DoublyLinkedList::PrintBackward() const
{
    cout << "\nTravel Itinerary (Last to First):\n";
    if (IsEmpty())
    {
        cout << "(empty)\n";
        return;
    }
    for (DestinationNode* node = tail; node != nullptr; node = node->left)
    {
        cout << node->destinationID << " - " << node->name
             << " (in " << node->city << ")";
        if (node == current)
            cout << "  [CURRENT]";
        cout << endl;
    }
}

bool DoublyLinkedList::IsEmpty() const { return head == nullptr; }
bool DoublyLinkedList::IsNotEmpty() const { return head != nullptr; }
int DoublyLinkedList::GetCount() const { return count; }

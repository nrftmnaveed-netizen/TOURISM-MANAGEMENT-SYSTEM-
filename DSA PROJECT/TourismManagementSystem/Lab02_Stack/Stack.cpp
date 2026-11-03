// ---------------------------------------------------------
// CLASS MEMBER FUNCTION FILE
// Definitions of all Stack member functions
// ---------------------------------------------------------
#include <iostream>
#include "Stack.h"
using namespace std;

// Constructor: start with an empty stack
Stack::Stack()
{
    top = nullptr;
    count = 0;
}

// Copy constructor: build a new, independent stack with copies of all nodes
Stack::Stack(const Stack& other)
{
    top = nullptr;
    count = 0;
    CopyFrom(other);
}

// Assignment operator: replace this stack's contents with a copy of 'other'
Stack& Stack::operator=(const Stack& other)
{
    if (this == &other)   // protect against self-assignment (s = s)
        return *this;
    Clear();              // free the old nodes first
    CopyFrom(other);
    return *this;
}

// Destructor: release every remaining node
Stack::~Stack()
{
    Clear();
}

// Delete all nodes one by one
void Stack::Clear()
{
    while (IsNotEmpty())
        delete Pop();
}

// Copy nodes from 'other' while keeping the same top-to-bottom order
void Stack::CopyFrom(const Stack& other)
{
    DestinationNode* last = nullptr;   // last node already copied
    for (DestinationNode* current = other.top; current != nullptr;
         current = current->next)
    {
        DestinationNode* copy = new DestinationNode(
            current->destinationID, current->name, current->city);

        if (last == nullptr)
            top = copy;           // first copied node becomes the top
        else
            last->next = copy;    // attach below the previous copy
        last = copy;
        count++;
    }
}

// Push: new node points to the old top, then becomes the top
void Stack::Push(DestinationNode* destination)
{
    if (destination == nullptr)
        return;
    destination->next = top;
    top = destination;
    count++;
}

// Pop: detach and return the top node (caller deletes it)
DestinationNode* Stack::Pop()
{
    if (IsEmpty())
        return nullptr;
    DestinationNode* removed = top;
    top = top->next;           // next node becomes the new top
    removed->next = nullptr;   // fully detach the removed node
    count--;
    return removed;
}

// Peek: return the top node without removing it
DestinationNode* Stack::GetTopValue() const
{
    return top;
}

bool Stack::IsEmpty() const { return top == nullptr; }
bool Stack::IsNotEmpty() const { return top != nullptr; }
int Stack::GetCount() const { return count; }

// Display from top to bottom
void Stack::PrintStack() const
{
    if (IsEmpty())
    {
        cout << "\nNo destinations in the stack.\n";
        return;
    }
    cout << "\nTOP\n |\n v\n";
    for (DestinationNode* current = top; current != nullptr;
         current = current->next)
    {
        cout << current->destinationID << " - " << current->name
             << " (" << current->city << ")" << endl;
    }
    cout << "BOTTOM\nTotal destinations: " << count << endl;
}

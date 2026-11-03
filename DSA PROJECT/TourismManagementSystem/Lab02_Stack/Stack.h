#ifndef STACK_H
#define STACK_H

#include "Destination.h"

// ---------------------------------------------------------
// CLASS FILE (declaration only)
// Stack (LIFO) of visited destinations for the return journey.
// The most recently visited destination is on TOP and is the
// first one the tourist goes back to.
// Member function bodies are in Stack.cpp
// ---------------------------------------------------------
class Stack
{
private:
    DestinationNode* top;   // most recently visited destination
    int count;              // number of destinations in the stack

    void Clear();                    // delete all nodes
    void CopyFrom(const Stack& other); // deep copy (keeps same order)

public:
    Stack();                                   // constructor
    Stack(const Stack& other);                 // copy constructor
    Stack& operator=(const Stack& other);      // assignment operator
    ~Stack();                                  // destructor

    void Push(DestinationNode* destination);   // place on top
    DestinationNode* Pop();                    // remove from top
    DestinationNode* GetTopValue() const;      // look at top without removing
    bool IsEmpty() const;
    bool IsNotEmpty() const;
    int GetCount() const;
    void PrintStack() const;                   // display top -> bottom
};

#endif

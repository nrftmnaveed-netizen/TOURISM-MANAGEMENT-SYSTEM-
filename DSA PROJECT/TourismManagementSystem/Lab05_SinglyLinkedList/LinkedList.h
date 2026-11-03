#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Destination.h"

// ---------------------------------------------------------
// CLASS FILE (declaration only)
// Singly linked list that manages the tour destination list.
// Member function bodies are in LinkedList.cpp
// ---------------------------------------------------------
class LinkedList
{
private:
    DestinationNode* head;   // first destination in the list
    int count;           // number of destinations currently in the list

    DestinationNode* GetNodeAt(int index);            // find node at an index
    void SwapData(DestinationNode* a, DestinationNode* b); // swap data of two nodes

public:
    LinkedList();
    ~LinkedList();

    // Copying is disabled so two lists can never share the same nodes
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void Insert(DestinationNode* destination);              // insert at head
    DestinationNode* Remove();                          // remove from head
    void InsertAt(DestinationNode* destination, int index); // insert at any index
    DestinationNode* RemoveAt(int index);               // remove from any index
    bool Swap(int index1, int index2);              // swap two destinations
    void Sort();                                    // sort by destination ID
    void Reverse();                                 // reverse the list
    void Print() const;                             // display all destinations

    bool IsEmpty() const;
    bool IsNotEmpty() const;
    int GetCount() const;
};

#endif

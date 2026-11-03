#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include "Destination.h"

// ---------------------------------------------------------
// CLASS FILE (declaration only)
// Circular linked list for the sightseeing bus route.
//   head       -> points to the LAST node (the "pivot")
//   head->next -> is the FIRST node
//   busStop     -> destination where the bus currently is (moves around the circle)
// Member function bodies are in CircularLinkedList.cpp
// ---------------------------------------------------------
class CircularLinkedList
{
private:
    DestinationNode* head;     // last node (pivot)
    DestinationNode* busStop;   // destination where the bus currently is
    int count;            // number of destinations

    DestinationNode* GetNodeAt(int index);               // node at index (0 = first)
    void SwapData(DestinationNode* a, DestinationNode* b);    // swap data of two nodes
    int NormalizeIndex(int index) const;            // wrap index into 0..count-1

public:
    CircularLinkedList();
    ~CircularLinkedList();

    // Copying disabled: two lists must never share nodes
    CircularLinkedList(const CircularLinkedList&) = delete;
    CircularLinkedList& operator=(const CircularLinkedList&) = delete;

    void Insert(DestinationNode* destination);               // insert next to pivot (front)
    DestinationNode* Remove();                          // remove node next to pivot
    void InsertAt(DestinationNode* destination, int index);  // insert at index
    DestinationNode* RemoveAt(int index);               // remove at index
    void Swap(int index1, int index2);             // swap two destinations
    void Sort();                                   // sort by destination ID
    void Reverse();                                // reverse the circle
    void Print() const;                            // display all destinations once

    DestinationNode* MoveToNext();                      // shift bus to next destination
    DestinationNode* GetBusStop() const;                 // destination where the bus is now
    void PrintRotation(int turns);                 // show bus stops for N turns (wraps)
    void VerifyCircular() const;                   // prove last -> first link

    bool IsEmpty() const;
    bool IsNotEmpty() const;
    int GetCount() const;
};

#endif

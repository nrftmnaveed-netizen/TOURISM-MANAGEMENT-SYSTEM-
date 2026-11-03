#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Destination.h"

// ---------------------------------------------------------
// CLASS FILE (declaration only)
// Doubly linked list for one tourist's travel itinerary.
//   head    -> oldest name
//   tail    -> newest name
//   current -> name the city is reviewing right now
// Member function bodies are in DoublyLinkedList.cpp
// ---------------------------------------------------------
class DoublyLinkedList
{
private:
    DestinationNode* head;
    DestinationNode* tail;
    DestinationNode* current;
    int count;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Copying disabled: two lists must never share nodes
    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    void InsertRight(DestinationNode* node);          // add at the end
    void InsertAfterCurrent(DestinationNode* node);   // add after current
    DestinationNode* RemoveCurrent();                 // remove current entry
    bool Next();                                    // move current forward
    bool Previous();                                // move current backward
    void PrintCurrent() const;                      // show current entry
    void PrintForward() const;                      // oldest -> newest
    void PrintBackward() const;                     // newest -> oldest

    bool IsEmpty() const;
    bool IsNotEmpty() const;
    int GetCount() const;
};

#endif

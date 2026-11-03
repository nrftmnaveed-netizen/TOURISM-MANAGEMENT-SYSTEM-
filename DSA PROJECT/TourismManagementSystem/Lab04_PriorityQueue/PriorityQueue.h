#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "SupportRequest.h"

// ---------------------------------------------------------
// CLASS FILE (declaration only)
// Priority Queue of tourist support requests.
//   front -> highest-priority request (processed first)
//   rear  -> last request in the queue
// Requests with equal priority keep their arrival order.
// Member function bodies are in PriorityQueue.cpp
// ---------------------------------------------------------
class PriorityQueue
{
private:
    SupportRequestNode* front;
    SupportRequestNode* rear;
    int count;

    void Clear();                              // delete all nodes
    void CopyFrom(const PriorityQueue& other); // deep copy

public:
    PriorityQueue();                                       // constructor
    PriorityQueue(const PriorityQueue& other);             // copy constructor
    PriorityQueue& operator=(const PriorityQueue& other);  // assignment operator
    ~PriorityQueue();                                      // destructor

    void Add(SupportRequestNode* request);   // add according to priority
    SupportRequestNode* Remove();            // remove highest priority
    bool IsEmpty() const;
    bool IsNotEmpty() const;
    int GetCount() const;
    void PrintQueue() const;                 // highest -> lowest priority
};

#endif

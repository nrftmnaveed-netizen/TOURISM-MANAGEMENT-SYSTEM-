#ifndef QUEUE_H
#define QUEUE_H

#include "TourRequest.h"

// ---------------------------------------------------------
// CLASS FILE (declaration only)
// Queue (FIFO) of tour booking requests.
//   front -> oldest request (served first)
//   rear  -> newest request (new requests join here)
// Member function bodies are in Queue.cpp
// ---------------------------------------------------------
class Queue
{
private:
    TourRequestNode* front;
    TourRequestNode* rear;
    int count;

    void Clear();                      // delete all nodes
    void CopyFrom(const Queue& other); // deep copy (keeps same order)

public:
    Queue();                                  // constructor
    Queue(const Queue& other);                // copy constructor
    Queue& operator=(const Queue& other);     // assignment operator
    ~Queue();                                 // destructor

    void EnQueue(TourRequestNode* request);   // add at the rear
    TourRequestNode* DeQueue();               // remove from the front
    bool IsEmpty() const;
    bool IsNotEmpty() const;
    int GetCount() const;
    void PrintQueue() const;                  // display FRONT -> REAR
};

#endif

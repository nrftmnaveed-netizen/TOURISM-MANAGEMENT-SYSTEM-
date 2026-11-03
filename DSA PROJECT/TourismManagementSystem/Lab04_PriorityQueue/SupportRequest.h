#ifndef SUPPORTREQUEST_H
#define SUPPORTREQUEST_H

#include <string>

// ---------------------------------------------------------
// STRUCTURE FILE
// One node = one help request from a tourist.
// Priority levels (smaller number = more urgent):
//   1 = Emergency (medical problem, lost, accident)
//   2 = Booking problem (cancelled tour, wrong booking)
//   3 = General inquiry (information, suggestions)
// ---------------------------------------------------------
struct SupportRequestNode
{
    int touristID;              // unique tourist ID
    std::string touristName;    // tourist name
    std::string issue;          // description of the problem
    int priority;               // 1 (highest) to 3 (lowest)
    SupportRequestNode* next;   // next request in the queue

    // Constructor: a new request always starts unlinked
    SupportRequestNode(int id, std::string name, std::string problem, int p)
        : touristID(id), touristName(name), issue(problem),
          priority(p), next(nullptr) {}
};

#endif

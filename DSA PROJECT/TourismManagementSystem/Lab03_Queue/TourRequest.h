#ifndef TOURREQUEST_H
#define TOURREQUEST_H

#include <string>

// ---------------------------------------------------------
// STRUCTURE FILE
// One node = one tour booking request from a tourist.
// The thing being queued is a REQUEST, not just a tour,
// so the node stores both tourist and tour information.
// 'next' makes the node self-referential.
// ---------------------------------------------------------
struct TourRequestNode
{
    int touristID;              // unique tourist ID
    std::string touristName;    // tourist name
    int tourID;                 // unique tour ID
    std::string tourName;       // requested tour name
    TourRequestNode* next;      // next request in the queue

    // Constructor: a new request always starts unlinked
    TourRequestNode(int tid, std::string tname, int id, std::string tour)
        : touristID(tid), touristName(tname), tourID(id),
          tourName(tour), next(nullptr) {}
};

#endif

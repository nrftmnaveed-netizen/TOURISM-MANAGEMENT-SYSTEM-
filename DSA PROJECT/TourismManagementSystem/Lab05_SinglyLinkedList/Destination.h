#ifndef DESTINATION_H
#define DESTINATION_H

#include <string>

// ---------------------------------------------------------
// STRUCTURE FILE
// One node = one destination record.
// The node is "self-referential": it holds a pointer ('next')
// to another DestinationNode, which is how nodes get chained.
// ---------------------------------------------------------
struct DestinationNode
{
    int destinationID;          // unique destination ID
    std::string name;       // destination name
    std::string city;    // destination city
    DestinationNode* next;      // pointer to the next destination in the list

    // Constructor: new node always starts unlinked (next = nullptr)
    DestinationNode(int id, std::string n, std::string d)
        : destinationID(id), name(n), city(d), next(nullptr) {}
};

#endif

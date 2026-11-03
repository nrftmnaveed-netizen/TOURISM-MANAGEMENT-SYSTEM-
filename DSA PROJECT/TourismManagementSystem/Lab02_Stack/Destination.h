#ifndef DESTINATION_H
#define DESTINATION_H

#include <string>

// ---------------------------------------------------------
// STRUCTURE FILE
// One node = one destination a tourist has visited.
// The node is "self-referential": 'next' points to another
// DestinationNode, which is how the stack is chained together.
// ---------------------------------------------------------
struct DestinationNode
{
    int destinationID;      // unique destination ID
    std::string name;       // destination name
    std::string city;       // city where the destination is located
    DestinationNode* next;  // node below this one in the stack

    // Constructor: a new node always starts unlinked
    DestinationNode(int id, std::string n, std::string c)
        : destinationID(id), name(n), city(c), next(nullptr) {}
};

#endif

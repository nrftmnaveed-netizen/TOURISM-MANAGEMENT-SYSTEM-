#ifndef DESTINATION_H
#define DESTINATION_H

#include <string>

// ---------------------------------------------------------
// STRUCTURE FILE
// One node = one destination in the bus route.
// 'next' points to the next destination; the LAST destination points
// back to the FIRST, so the route repeats forever.
// ---------------------------------------------------------
struct DestinationNode
{
    int destinationID;                 // unique destination ID
    std::string name;             // destination name
    std::string city;   // e.g. Cardiology
    DestinationNode* next;             // next destination in the circle

    DestinationNode(int id, std::string n, std::string s)
        : destinationID(id), name(n), city(s), next(nullptr) {}
};

#endif

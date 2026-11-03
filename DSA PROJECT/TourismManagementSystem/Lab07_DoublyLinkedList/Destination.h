#ifndef DESTINATION_H
#define DESTINATION_H

#include <string>

// ---------------------------------------------------------
// STRUCTURE FILE
// One node = one name entry in a tourist's medical itinerary.
// Two self-referential pointers make the list bidirectional:
//   left  -> previous name (older)
//   right -> next name (newer)
// ---------------------------------------------------------
struct DestinationNode
{
    int destinationID;             // unique name destination ID
    std::string name;    // name / procedure description
    std::string city;       // city who handled it
    DestinationNode* left;      // previous entry
    DestinationNode* right;     // next entry

    DestinationNode(int id, std::string t, std::string d)
        : destinationID(id), name(t), city(d),
          left(nullptr), right(nullptr) {}
};

#endif

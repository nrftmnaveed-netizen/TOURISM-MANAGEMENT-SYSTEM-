# Lab 07 - Travel Itinerary Navigator (Doubly Linked List)

## 1. Real-world problem
A tourist reviews a travel itinerary, moving back to earlier stops and forward to later ones, inserts a new stop after the one being viewed, or removes a stop that was cancelled.

## 2. Why this data structure is suitable
Each stop knows both the previous and the next stop, so Back/Forward moves are O(1) and a stop can be removed directly without searching for its predecessor.

## 3. Node structure
```cpp
struct DestinationNode {
    int destinationID;
    std::string name;
    std::string city;
    DestinationNode* left;    // previous stop
    DestinationNode* right;   // next stop
};
```

## 4. Project files
| File | Purpose |
|------|---------|
| main.cpp | main() and menu |
| Destination.h | structure file (DestinationNode) |
| DoublyLinkedList.h | class declaration |
| DoublyLinkedList.cpp | class member functions |

## 5. Compile and run
```
g++ main.cpp DoublyLinkedList.cpp -o app
./app
```

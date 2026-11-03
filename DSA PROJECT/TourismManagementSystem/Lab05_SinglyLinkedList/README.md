# Lab 05 - Tour Destination List (Singly Linked List)

## 1. Real-world problem
A travel agency builds a tour package from destinations. Destinations are added at any position, cancelled ones are removed, two stops can be exchanged, and the list can be sorted by ID or reversed for the return trip.

## 2. Why this data structure is suitable
The number of destinations changes constantly, so a fixed array would waste space or run out. Inserting or removing in the middle only changes pointers; no elements are shifted.

## 3. Node structure
```cpp
struct DestinationNode {
    int destinationID;
    std::string name;
    std::string city;
    DestinationNode* next;
};
```

## 4. Project files
| File | Purpose |
|------|---------|
| main.cpp | main() and menu |
| Destination.h | structure file (DestinationNode) |
| LinkedList.h | class declaration |
| LinkedList.cpp | class member functions |

## 5. Compile and run
```
g++ main.cpp LinkedList.cpp -o app
./app
```

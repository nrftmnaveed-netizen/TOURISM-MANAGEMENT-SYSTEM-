# Lab 06 - Sightseeing Bus Route (Circular Linked List)

## 1. Real-world problem
A city sightseeing bus drives a loop through tourist spots. After the last stop it goes straight back to the first stop and keeps repeating all day.

## 2. Why this data structure is suitable
In a circular list the last node points back to the first, so the bus can keep moving without ever reaching nullptr and without special 'go back to start' code.

## 3. Node structure
```cpp
struct DestinationNode {
    int destinationID;
    std::string name;
    std::string city;
    DestinationNode* next;   // last node's next = first node
};
```

## 4. Project files
| File | Purpose |
|------|---------|
| main.cpp | main() and menu |
| Destination.h | structure file (DestinationNode) |
| CircularLinkedList.h | class declaration |
| CircularLinkedList.cpp | class member functions |

## 5. Compile and run
```
g++ main.cpp CircularLinkedList.cpp -o app
./app
```

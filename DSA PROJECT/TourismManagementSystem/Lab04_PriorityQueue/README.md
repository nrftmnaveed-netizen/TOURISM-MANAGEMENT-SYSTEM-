# Lab 04 - Tourist Support Desk (Priority Queue)

## 1. Real-world problem
Tourists contact the support desk with problems. A tourist who is injured or has lost a passport must be helped before one who only wants hotel suggestions, even if the general request arrived earlier.

## 2. Why this data structure is suitable
Arrival order alone is not enough; urgency decides. Add() inserts each request at the position of its priority (equal priorities keep arrival order) and Remove() always takes the most urgent request from the front.

Priority levels (smaller number = higher priority):
- 1 = Emergency (medical problem, lost passport, accident)
- 2 = Booking problem (cancelled or wrong booking)
- 3 = General inquiry

## 3. Node structure
```cpp
struct SupportRequestNode {
    int touristID;
    std::string touristName;
    std::string issue;
    int priority;               // 1 (highest) to 3 (lowest)
    SupportRequestNode* next;
};
```

## 4. Project files
| File | Purpose |
|------|---------|
| main.cpp | main() and menu |
| SupportRequest.h | structure file (SupportRequestNode) |
| PriorityQueue.h | class declaration |
| PriorityQueue.cpp | class member functions |

## 5. Compile and run
```
g++ main.cpp PriorityQueue.cpp -o app
./app
```

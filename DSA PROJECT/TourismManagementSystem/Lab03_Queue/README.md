# Lab 03 - Tour Booking Requests (Queue)

## 1. Real-world problem
Tourists request tours that are currently full. The agency must handle the requests in the order they were received.

## 2. Why this data structure is suitable
The tourist who requested first must be served first: First In, First Out (FIFO). New requests join at the rear and the next available seat goes to the request at the front. Operations: EnQueue, DeQueue, IsEmpty, IsNotEmpty, PrintQueue, plus copy constructor, assignment operator and destructor.

## 3. Node structure
```cpp
struct TourRequestNode {
    int touristID;
    std::string touristName;
    int tourID;
    std::string tourName;
    TourRequestNode* next;
};
```

## 4. Project files
| File | Purpose |
|------|---------|
| main.cpp | main() and menu |
| TourRequest.h | structure file (TourRequestNode) |
| Queue.h | class declaration |
| Queue.cpp | class member functions |

## 5. Compile and run
```
g++ main.cpp Queue.cpp -o app
./app
```

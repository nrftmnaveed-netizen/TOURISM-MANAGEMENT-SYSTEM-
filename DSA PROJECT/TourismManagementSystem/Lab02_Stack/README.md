# Lab 02 - Tourist Return Journey (Stack)

## 1. Real-world problem
A tourist visits destinations one after another (Lahore Fort, Faisal Mosque, Naran Kaghan). On the return journey the tourist goes back through the places in reverse order, starting from the most recently visited one.

## 2. Why this data structure is suitable
The most recently visited destination must be the first one revisited: Last In, First Out (LIFO). No sorting is needed and no destination in the middle can be reached directly, which is exactly how a stack works. Operations: Push (visit), Pop (go back), GetTopValue (last visited), IsEmpty, IsNotEmpty, PrintStack, plus copy constructor, assignment operator and destructor.

## 3. Node structure
```cpp
struct DestinationNode {
    int destinationID;
    std::string name;
    std::string city;
    DestinationNode* next;   // node below in the stack
};
```

## 4. Project files
| File | Purpose |
|------|---------|
| main.cpp | main() and menu |
| Destination.h | structure file (DestinationNode) |
| Stack.h | class declaration |
| Stack.cpp | class member functions |

## 5. Compile and run
```
g++ main.cpp Stack.cpp -o app
./app
```

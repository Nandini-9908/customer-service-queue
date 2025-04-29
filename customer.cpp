#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Node for each call log
struct CallLogNode {
    string customerName;
    time_t timestamp;
    CallLogNode* next;
    CallLogNode* prev; // Optional, if you want bidirectional navigation

    CallLogNode(string name) {
        customerName = name;
        timestamp = time(nullptr); // current time
        next = nullptr;
        prev = nullptr;
    }
};
//call log queue class
class CallLogQueue {
private:
    CallLogNode* head;
    CallLogNode* tail;

public:
    CallLogQueue() {
        head = nullptr;
        tail = nullptr;
    }



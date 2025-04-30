#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Node for each call log
struct CallLogNode
{
    string customerName;
    time_t timestamp;
    CallLogNode* next;
    CallLogNode* prev; // Optional, if you want bidirectional navigation

    CallLogNode(string name)
  {
        customerName = name;
        timestamp = time(NULL); // current time
        next = NULL;
        prev = NULL;
    }
};
//call log queue class
class CallLogQueue
{
private:
    CallLogNode* head;
    CallLogNode* tail;

public:
    CallLogQueue()
    {
        head = NULL;
        tail = NULL;
    }

// Add a new call to the end of the Queue
void addCall(string customerName)
{
    CallLogNode* newCall=new CallLogNode(customerName);

    if(!head) // Empty List
    {
        head = tail=newCall;
    }
    else
    {
        tail->next=newCall;
        newCall->prev=tail;
        tail=newCall;
    }
   cout<< "Call From "<<customerName <<" Added on "<<ctime(&newCall->timestamp);
}
void removeOldestCall()
{
        if (!head)
        {
            cout << "No calls to remove.\n";
            return;
        }
      CallLogNode* temp = head;
        head = head->next;
        if (head)
            head->prev = NULL;
        else
            tail = NULL;

        cout << "Removing call from " << temp->customerName << " on " << ctime(&temp->timestamp);
        delete temp;
}
void displayLogs() 
{
        if (!head)
        {
            cout << "No call logs available.\n";
            return;
        }

        CallLogNode* current = head;
        cout << "Call Logs:\n";
        while (current)
            {
            cout << "- " << current->customerName << " on " << ctime(&current->timestamp);
            current = current->next;
             }
}

~CallLogQueue() 
 {
    while (head)
     {
        CallLogNode* temp = head;
        head=head->next;
        delete temp;
     }
  }
};
// Main function to test the CallLogQueue
int main() {
    CallLogQueue callQueue;
    int choice;
    string name;

    do {
        cout << "\n--- Call Log System ---\n";
        cout << "1. Add Call\n";
        cout << "2. Remove Oldest Call\n";
        cout << "3. Display Call Logs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // to consume the newline after number input

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                getline(cin, name);
                callQueue.addCall(name);
                break;
            case 2:
                callQueue.removeOldestCall();
                break;
            case 3:
                callQueue.displayLogs();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}






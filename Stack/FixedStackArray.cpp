#include <iostream>
#include <climits>
using namespace std;
class FixedStack
{
private:
    int *data;
    int nextIndex;
    int capacity;

public:
    FixedStack(int totalSize) {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    // Find size of the stack
    int size() {
        return nextIndex;
    }

    // Check whether stack is empty or not
    bool isEmpty() {
        return nextIndex == 0;
    }

    // Insert an element at the top
    void push(int element) {
        if(nextIndex == capacity) {
            cout << "Stack is full !" << endl;
            return;
        }
        data[nextIndex++] = element;
    }

    // Delete an element from the top
    int pop() {
        if(isEmpty()) {
            cout << "Stack is empty !" << endl;
            return INT_MIN;
        }
        return data[--nextIndex];
    }

    // Access the top element
    int top() {
        if(isEmpty()) {
            cout << "Stack is empty !" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};
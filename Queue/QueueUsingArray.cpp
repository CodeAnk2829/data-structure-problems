// Implement queue and it's respective operations using array.
#include <iostream>
using namespace std;
class Queue
{
private:
    int* queueData;
    int nextIndex;
    int capacity;

public:
    // Constructor
    Queue() {
        capacity = 5;
        queueData = new int[capacity];
        nextIndex = 0;
    }
    // Size of queue
    int size() {
        return nextIndex;
    }
    // Check queue is empty or not
    bool isEmpty() {
        return nextIndex == 0;
    }
    // Insert
    void enqueue(int element) {
        if(nextIndex == capacity) {
            int* newQueue = new int[2*capacity];
            for(int i = 0; i < capacity; ++i) {
                newQueue[i] = queueData[i];
            }
            delete [] queueData;
            queueData = newQueue;
            capacity *= 2;
        }
        queueData[nextIndex] = element;
        nextIndex++;
    } 
    // Delete
    int dequeue() {
        if(isEmpty()) {
            return 0;
        }
        int temp = queueData[0];
        for(int i = 1; i < nextIndex; ++i) {
            queueData[i - 1] = queueData[i];
        }
        nextIndex--;
        return 0;
    }
    // Accessing front
    int front() {
        if(isEmpty()) {
            return 0;
        }
        return queueData[0];
    }

    void print() {
        for(int i = 0; i < nextIndex; ++i) {
            cout << queueData[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue q;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(9);
    q.print();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.print();
    q.enqueue(100);
    q.print();
    cout << q.front() << endl;
    cout << q.size() << endl;
    
    return 0;
}
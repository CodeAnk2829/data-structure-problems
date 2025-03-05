// Heap Sort
#include "MinHeap.h"
#include "MaxHeap.h"
int main() {
    PriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(30);
    p.insert(45);
    p.insert(70);
    p.insert(18);
    p.insert(120);

    cout << p.getSize() << endl;
    cout << p.getMin() << endl;

    while(!p.isEmpty()) {
        cout << p.removeMin() << " ";
    }
    cout << endl;
    MaxHeap pq;
    pq.insert(100);
    pq.insert(10);
    pq.insert(30);
    pq.insert(45);
    pq.insert(70);
    pq.insert(18);
    pq.insert(120);

    cout << pq.getSize() << endl;
    cout << pq.getMax() << endl;

    while (!pq.isEmpty())
    {
        cout << pq.removeMax() << " ";
    }
    cout << endl;
    return 0;
}
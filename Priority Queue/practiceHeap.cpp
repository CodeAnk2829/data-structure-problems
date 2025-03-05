#include <iostream>
#include <vector>
using namespace std;
class MinHeap
{
private:
    vector<int> minHeap;

public:
    MinHeap() {

    }

    int getSize() {
        return minHeap.size();
    }

    bool isEmpty() {
        return minHeap.size() == 0;
    }

    int getMin() {
        if(isEmpty()) {
            return 0;
        }
        return minHeap[0];
    }

    void insert(int element) {
        minHeap.push_back(element);
        int childIndex = minHeap.size() - 1;
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            if(minHeap[parentIndex] > minHeap[childIndex]) {
                swap(minHeap[parentIndex], minHeap[childIndex]);
            } else {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin() {
        if(isEmpty()) {
            return 0;
        }
        int ans = minHeap[0];
        minHeap[0] = minHeap[minHeap.size() - 1];
        minHeap.pop_back();

        // down heapify
        int parentIndex = 0;
        int leftChildIndex = (2 * parentIndex + 1);
        int rightChildIndex = (2 * parentIndex + 2);
        while(leftChildIndex < minHeap.size()) {
            int maxIndex = parentIndex;
            if(minHeap[maxIndex] > minHeap[leftChildIndex]) {
                maxIndex = leftChildIndex;
            }
            if(rightChildIndex < minHeap.size() && minHeap[maxIndex] > minHeap[rightChildIndex]) {
                maxIndex = rightChildIndex;
            }
            if(maxIndex == parentIndex) {
                break;
            }
            swap(minHeap[maxIndex], minHeap[parentIndex]);
            parentIndex = maxIndex;
            leftChildIndex = (2 * parentIndex + 1);
            rightChildIndex = (2 * parentIndex + 2);
        }
        return ans;
    }
};

class MaxHeap
{
private:
    vector<int> pq;

public:
    MaxHeap() {

    }

    bool isEmpty() {
        return pq.size() == 0;
    }

    int getSize() {
        return pq.size();
    }

    int getMax() {
        if(isEmpty()) {
            return 0;
        }
        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            if(pq[parentIndex] < pq[childIndex]) {
                swap(pq[parentIndex], pq[childIndex]);
            } else {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMax() {
        if(isEmpty()) {
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        // down heapify
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while(leftChildIndex < pq.size()) {
            int maxIndex = parentIndex;
            if(pq[maxIndex] < pq[leftChildIndex]) {
                maxIndex = leftChildIndex;
            }
            if(rightChildIndex < pq.size() && pq[maxIndex] < pq[rightChildIndex]) {
                maxIndex = rightChildIndex;
            }
            if(maxIndex == parentIndex) {
                break;
            }
            swap(pq[maxIndex], pq[parentIndex]);
            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
        return ans;
    }
};




int main()
{
    MinHeap p;
    p.insert(100);
    p.insert(10);
    p.insert(30);
    p.insert(45);
    p.insert(70);
    p.insert(18);
    p.insert(120);

    cout << p.getSize() << endl;
    cout << p.getMin() << endl;

    while (!p.isEmpty())
    {
        cout << p.removeMin() << " ";
    }
    cout << endl;
    
    return 0;
}

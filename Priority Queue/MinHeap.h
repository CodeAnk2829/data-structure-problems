#include <iostream>
#include <vector>
using namespace std;
class PriorityQueue
{
private:
    vector<int> pq;

public:
    PriorityQueue() {

    }

    bool isEmpty() {
        return pq.size() == 0;
    }

    int getSize() {
        return pq.size();
    }

    int getMin() {
        if(isEmpty()) {
            return 0;
        }
        return pq[0];
    }

    void insert(int data) {
        pq.push_back(data);
        int childIndex = pq.size() - 1;
        while(childIndex > 0) {
           int parentIndex = (childIndex - 1) / 2;
           if (pq[parentIndex] > pq[childIndex])
               swap(pq[parentIndex], pq[childIndex]);
            else 
                break;
           childIndex = parentIndex;
        }
    }

    int removeMin() {
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        //down heapify
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while(leftChildIndex < pq.size()) {
            int minIndex = parentIndex;
            if(pq[minIndex] > pq[leftChildIndex]) {
                minIndex = leftChildIndex;
            }
            if(rightChildIndex < pq.size() && pq[minIndex] > pq[rightChildIndex]) {
                minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex) {
                break;
            }
            swap(pq[parentIndex], pq[minIndex]);
            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }

        return ans;
    }
};
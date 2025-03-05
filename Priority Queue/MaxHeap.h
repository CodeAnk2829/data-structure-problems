#include <iostream>
#include <vector>
using namespace std;
class MaxHeap
{
private:
    vector<int> pq;

public:
    MaxHeap()
    {
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMax()
    {
        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] < pq[childIndex])
            {
                swap(pq[parentIndex], pq[childIndex]);
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMax()
    {
        if (isEmpty()) {
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        // down heapify
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while (leftChildIndex < pq.size())
        {
            int maxIndex = parentIndex;
            if (pq[maxIndex] < pq[leftChildIndex])
            {
                maxIndex = leftChildIndex;
            }
            if (rightChildIndex < pq.size() && pq[maxIndex] < pq[rightChildIndex])
            {
                maxIndex = rightChildIndex;
            }
            if (maxIndex == parentIndex)
            {
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
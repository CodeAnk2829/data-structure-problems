// Inplace Heap Sort using Max heap.
#include <iostream>
using namespace std;
void buildHeap(int input[], int i) {
    int childIndex = i;
    while(childIndex > 0) {
        int parentIndex = (childIndex - 1) / 2;
        if(input[parentIndex] < input[childIndex]) {
            swap(input[parentIndex], input[childIndex]);
        } else {
            break;
        }
        childIndex = parentIndex;
    }
}

void maxHeapify(int input[], int size) {
    int parentIndex = 0;
    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndex = 2 * parentIndex + 2;
    while(leftChildIndex < size) {
        int maxIndex = parentIndex;
        if(input[maxIndex] < input[leftChildIndex]) {
            maxIndex = leftChildIndex;
        }
        if(rightChildIndex < size && input[maxIndex] < input[rightChildIndex]) {
            maxIndex = rightChildIndex;
        }
        if(maxIndex == parentIndex) {
            break;
        }
        swap(input[maxIndex], input[parentIndex]);
        parentIndex = maxIndex;
        leftChildIndex = 2 * parentIndex + 1;
        rightChildIndex = 2 * parentIndex + 2;
    }
}
void inplaceHeapSort (int input[], int n) {
    for(int i = 1; i < n; ++i) {
        buildHeap(input, i);
    }
    int size = n;
    while(size > 1) {
        swap(input[0], input[size - 1]);
        size--;
        maxHeapify(input, size);
    }
}
int main()
{
    int n;
    cin >> n;
    int input[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> input[i];
    }
    inplaceHeapSort(input, n);
    for (int i = 0; i < n; ++i)
    {
        cout << input[i] << " ";
    }
    return 0;
}

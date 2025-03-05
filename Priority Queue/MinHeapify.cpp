// Inplace Heap Sort using Min heap
// Sorted in decreasing order
// TC = O(nlogn), Space Complexity = O(1)
#include <bits/stdc++.h>
using namespace std;
void buildHeap(int input[], int n, int i) {
    int childIndex = i;
    while(childIndex > 0) {
        int parentIndex = (childIndex - 1) / 2;
        if(input[parentIndex] > input[childIndex]) {
            swap(input[parentIndex], input[childIndex]);
        } else {
            break;
        }
        childIndex = parentIndex;
    }
}
void minHeapify(int input[], int size) {
    int parentIndex = 0;
    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndex = 2 * parentIndex + 2;
    while(leftChildIndex < size) {
        int minIndex = parentIndex;
        if(input[minIndex] > input[leftChildIndex]) {
            minIndex = leftChildIndex;
        }
        if(rightChildIndex < size && input[minIndex] > input[rightChildIndex]) {
            minIndex = rightChildIndex;
        }
        if(minIndex == parentIndex) {
            break;
        }
        swap(input[parentIndex], input[minIndex]);
        parentIndex = minIndex;
        leftChildIndex = 2 * parentIndex + 1;
        rightChildIndex = 2 * parentIndex + 2;
    }
} 
void inplaceHeapSort(int input[], int n) {
    // building heap
    for(int i = 1; i < n; ++i) {
        // up heapify
        buildHeap(input, n, i);
    }
    int size = n;
    while(size > 1) {
        swap(input[0], input[size - 1]);
        size--;
        //down heapify
        minHeapify(input, size);
    }
}
int main() {
    int n;
    cin >> n;
    int input[n];
    for(int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    inplaceHeapSort(input, n);
    for(int i = 0; i < n; ++i) {
        cout << input[i] << " ";
    }
    return 0;
}
// Quick sort with partitioning at median of three
#include<bits/stdc++.h>
using namespace std;

int partitionAtMedian_3(int arr[], int low, int high)
{
    int pivot = arr[low], y = arr[(low + high) / 2], z = arr[high];
    int index = low;

    if ((y > pivot && y < z) || (y > z && y < pivot))
    {
        pivot = y;
        index = (low + high) / 2;
    }
    else if ((z > pivot && z < y) || (z > y && z < pivot))
    {
        pivot = z;
        index = high;
    }

    int i = low - 1;

    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            if (i == index)
                index = j;
        }
    }

    swap(arr[i + 1], arr[index]);

    return i + 1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){

        int pivot=partitionAtMedian_3(arr, low, high);

        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int main(){
    int n;
    cout << "Enter number of elements\n";
    cin >> n;

    int arr[n];
    cout << "Enter elements" << endl;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Function call
    quickSort(arr, 0, 10);

    cout << "After sorting:" << endl;
    for(int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
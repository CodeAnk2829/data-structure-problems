#include <bits/stdc++.h>
using namespace std;
void insertionSort(int *a, int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        int picked = a[i];
        int j = i - 1;
        while (a[j] > picked and j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = picked;
    }
}
void merge(int *a, int s, int e)
{
    int mid = (s + e) >> 1;
    int aux[e - s + 1];
    int i = s, j = mid + 1;
    int k = 0;
    while (i <= mid and j <= e)
    {
        if (a[i] <= a[j])
        {
            aux[k++] = a[i++];
        }
        else
        {
            aux[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        aux[k++] = a[i++];
    }
    while (j <= e)
    {
        aux[k++] = a[j++];
    }
    for (int i = s; i <= e; i++)
    {
        a[i] = aux[i - s];
    }
}
void mergeSort(int *a, int s, int e)
{
    if (s == e)
        return;
    int mid = (s + e) >> 1;
    if (mid - s + 1 <= 16)
    {
        insertionSort(a, s, e);
    }
    else
    {
        mergeSort(a, s, mid);
    }
    if (e - mid <= 16)
    {
        insertionSort(a, s, e);
    }
    else
    {
        mergeSort(a, mid + 1, e);
    }
    merge(a, s, e);
}
void mergeSort(int *a, int n)
{
    mergeSort(a, 0, n - 1);
}
int main()
{
    int n;
    cout << "Enter size: " << endl;
    cin >> n;

    int *a = new int[n];
    cout << "Enter elements" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Function Call
    mergeSort(a, n);

    cout << "After sorting: " << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    delete [] a;

    return 0;
}
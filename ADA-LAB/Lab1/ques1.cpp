#include <bits/stdc++.h>
using namespace std;

void minMaxVersion1(int arr[], int n)
{
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];

        if (arr[i] > max)
            max = arr[i];
    }

    cout << "minimum_vers_1 : " << min << endl;
    cout << "maximum_vers_1 : " << max << endl;
}

void minMaxVersion2(int arr[], int n)
{
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }

    cout << "minimum_vers_2 : " << min << endl;
    cout << "maximum_vers_2 : " << max << endl;
}

void binary_Search(int a[], int low, int high, int key)
{
    int mid;

    if (low <= high)
    {
        mid = (low + high) / 2;
        if (key == a[mid])
            cout << "key found " << endl;

        if (key < a[mid])
            binary_Search(a, low, mid - 1, key);

        if (key > a[mid])
            binary_Search(a, mid + 1, high, key);
    }
    if (low > high)
        cout << "key not found ";
}

int main()
{
    int n;
    cout << "Enter no. of values to array : " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter n values into the array :" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    minMaxVersion1(arr, n);
    minMaxVersion2(arr, n);

    int key;
    cout << "Enter key value to search: " << endl;
    cin >> key;

    sort(arr, arr + n);
    binary_Search(arr, 0, n, key);
    return 0;
}

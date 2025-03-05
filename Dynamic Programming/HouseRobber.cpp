#include <bits/stdc++.h>
using namespace std;


// Function to find the maximum money the thief can get.
// bottom-up approach
int FindMaxSum(int arr[], int n)
{
    int prevHouse = arr[0];
    int prevToPrevHouse = 0;
    for (int i = 1; i < n; ++i)
    {
        int option1 = arr[i] + prevToPrevHouse;
        int option2 = prevHouse;
        int amount = max(option1, option2);
        prevToPrevHouse = prevHouse;
        prevHouse = amount;
    }

    return prevHouse;
}


// top-down approach
// same as minimum sum of non adjacent element (see)
#include <bits/stdc++.h> 
using namespace std;
const int MAX = 100; // maximum number of coins
int coins[MAX];      // array to store the weight of each coin
// function to check if the left or right set of coins is lighter bool isLeftLight(int low, int high, int mid)
int isLeftLight(int low, int high, int mid)
{
    int leftWeight = 0, rightWeight = 0;
    for (int i = low; i <= mid; i++)
        leftWeight += coins[i];
    for (int i = mid + 1; i <= high; i++)
        rightWeight += coins[i];
    return leftWeight < rightWeight;
}
// binary search function to find the fake coin int binarySearch(int low, int high)
int binarySearch (int low, int high)
{
    int mid;
    while (low <= high)

    {
        mid = (low + high) / 2;
        bool ifLeftLight = isLeftLight(low, high, mid);
        if (ifLeftLight)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
// ternary search function to find the fake coin int ternarySearch(int low, int high)
int ternarySearch(int low, int high) {
    int mid1, mid2;
    while (low <= high)
    {
        mid1 = low + (high - low) / 3;
        mid2 = high - (high - low) / 3;
        bool ifLeftLight = isLeftLight(low, high, mid1);
        if (ifLeftLight)
        {
            low = mid1 + 1;
        }
        else
        {
            bool isMiddleLight = isLeftLight(low, high, mid2);
            if (isMiddleLight)
                low = mid1 + 1;
            else
                high = mid2 - 1;
        }
    }
    return low;
}
int main()
{
    int n;
    // input the weights of the coins int n;
    cout << "Enter the number of coins: ";
    cin >> n;
    cout << "Enter the weight of each coin: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    int fakeCoinIndex = binarySearch(0, n - 1);
    cout << "The fake coin is at index " << fakeCoinIndex << endl;
    fakeCoinIndex = ternarySearch(0, n - 1);

    cout << "The fake coin is at index " << fakeCoinIndex << endl;
    return 0;
}

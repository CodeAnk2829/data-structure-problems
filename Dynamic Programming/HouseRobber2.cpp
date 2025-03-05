// https://www.codingninjas.com/studio/problems/house-robber-ii_839733?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

long long lootHouses(vector<int> &arr)
{
    int n = arr.size();
    long long prevHouse = arr[0];
    long long prevToPrevHouse = 0;
    for (int i = 1; i < n; ++i)
    {
        long long option1 = arr[i] + prevToPrevHouse;
        long long option2 = prevHouse;
        long long amount = max(option1, option2);
        prevToPrevHouse = prevHouse;
        prevHouse = amount;
    }

    return prevHouse;
}
long long int houseRobber(vector<int> &valueInHouse)
{
    vector<int> arr1 = valueInHouse;
    vector<int> arr2 = valueInHouse;
    arr1.erase(arr1.begin());
    arr2.pop_back();

    return max(lootHouses(arr1), lootHouses(arr2));
}
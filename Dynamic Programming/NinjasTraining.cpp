// https://www.codingninjas.com/studio/problems/ninja%E2%80%99s-training_3621003?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

// top-down approach

#include <bits/stdc++.h>
using namespace std;

int f(int day, int lastTask, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    // base case
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i <= 2; ++i)
        {
            if (i != lastTask)
            {
                maxi = max(points[day][i], maxi);
            }
        }
        return dp[day][lastTask] = maxi;
    }

    // if the answer already exists
    if (dp[day][lastTask] != -1)
        return dp[day][lastTask];

    // check for all possible cases
    int maxi = 0;
    for (int i = 0; i <= 2; ++i)
    {
        if (i != lastTask)
        {
            int point = points[day][i] + f(day - 1, i, points, dp);
            maxi = max(maxi, point);
        }
    }

    return dp[day][lastTask] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // task3 is taken explicitly to show that none
    // of the three tasks has been performed initially

    vector<vector<int>> dp(n, vector<int>(4, -1)); // 4 for {task0, task1, task2 and task3}
    return f(n - 1, 3, points, dp);
}
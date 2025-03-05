#include <bits/stdc++.h>
using namespace std;
double round(double var) {
    double value = (int)(var * 100 + .5);
    return (double)value / 100;
}

vector<double> averageTimes(vector<int> arrivalTime, vector<int> burstTime, int n) {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> readyQueue;
    vector<pair<int, int>> temp(n);
    for (int i = 0; i < n; ++i) {
        temp[i] = {arrivalTime[i], burstTime[i]};
    }

    sort(temp.begin(), temp.end());

    int currTime = temp[0].first;
    int executed = 0;
    int totalTurnAroundTime = 0;
    int totalWaitingTime = 0;

    while (!readyQueue.empty() || executed < n) {
        while (executed < n && temp[executed].first <= currTime) {
            readyQueue.push({temp[executed].second, temp[executed].first});
            executed++;
        }

        if (readyQueue.empty()) {
            currTime = temp[executed].first;
            continue;
        }

        vector<int> runningProcess = readyQueue.top();
        currTime += runningProcess[0];
        int turnAroundTime = currTime - runningProcess[1];
        totalTurnAroundTime += turnAroundTime;
        totalWaitingTime += (turnAroundTime - runningProcess[0]);
        readyQueue.pop();
    }

    double avgTat = (double)(totalTurnAroundTime * 1.0 / n);
    double avgWaitingTime = (double)(totalWaitingTime * 1.0 / n);
    return {round(avgWaitingTime), round(avgTat)};
}

int main() {
    int n;
    cin >> n;
    vector<int> arrivalTime(n), burstTime(n);
    for(auto &i : arrivalTime) cin >> i;
    for(auto &i : burstTime) cin >> i;

    vector<double> ans = averageTimes(arrivalTime, burstTime, n);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
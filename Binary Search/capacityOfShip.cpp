#include <bits/stdc++.h>
using namespace std;

int getDay(vector<int> &weights, int capacity)
{
    int sum = 0;
    int days = 0;
    for (int i = 0; i < weights.size() - 1; ++i)
    {
        sum += weights[i];
        if (sum + weights[i + 1] > capacity)
        {
            sum = 0;
            days++;
        }
    }
    days++;
    return days;
}
int findDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    cout << low << " " << high << endl;
    int ans = high;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int requiredDays = getDay(weights, mid);
        
        cout << requiredDays << " ";
        if(requiredDays <= days) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> weights(n);
    for(int i = 0; i < n; ++i) cin >> weights[i];
    int day;
    cin >> day;
    cout << findDays(weights, day);
    return 0;
}
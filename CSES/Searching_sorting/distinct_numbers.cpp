#include <bits/stdc++.h>
using namespace std;

int distinctNumbers(int n, vector<int>& nums) {
    set<int> s;
    for (auto &i : nums) {
        s.insert(i);
    }
    return s.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto& i : nums) cin >> i;

    cout << distinctNumbers(n, nums) << endl;

    return 0;
}
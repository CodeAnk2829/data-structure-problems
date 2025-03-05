// Next Smaller to Right
#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerToRight(vector<int>& nums) {
    // contains next smaller to right elements 
    vector<int> res;
    stack<int> s;
    int n = nums.size();

    // Find next smaller to left and stores the values in res vector
    for(int i = n - 1; i >= 0; --i) {
        if(s.empty()) {
            res.push_back(-1);
        } else {
            // check whether s.top() is pushable or not
            while(!s.empty() && s.top() >= nums[i]) {
                s.pop();
            }
            if(s.empty()) {
                res.push_back(-1);
            } else {
                res.push_back(s.top());
            }
        }
        s.push(nums[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}
int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector<int> nsr = nextSmallerToRight(v);
    for(auto &x : nsr) {
        cout << x << " ";
    }
    return 0;
}
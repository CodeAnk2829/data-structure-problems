// Next Smaller to left
#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerToLeft(vector<int>& nums) {
    // contains next smaller to left elements
    vector<int> res;
    stack<int> s;
    int n = nums.size();
    
    // Find next smaller to left elements and store them into res vector
    for(int i = 0; i < n; ++i) {
        if(s.empty()) {
            res.push_back(-1);
        } else {
            // Check whether s.top() is pushable or not
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
    vector<int> nsl = nextSmallerToLeft(v);
    for(auto &x : nsl) {
        cout << x << " ";
    }
    return 0;
}
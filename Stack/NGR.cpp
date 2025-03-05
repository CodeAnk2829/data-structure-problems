// Next Greater to Right
#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterToRight(vector<int>& nums) {
    // contains next greater elements for every element
    vector<int> res;

    stack<int> s;
    int n = nums.size();

    // Calculation
    for(int i = n - 1; i >= 0; --i) {
        if(s.empty()) {
            res.push_back(-1);
        } else {
            // check before inserting the disired number
            while(!s.empty() && s.top() <= nums[i]) {
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
    vector<int> nums;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<int> ngr = nextGreaterToRight(nums);
    for(auto &x : ngr) {
        cout << x << " ";
    }
    return 0;
}
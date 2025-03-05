// Next Greater to Left
#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterToLeft(vector<int>& nums) {
    // contains next greater to left elements
    vector<int> res;
    stack<int> s;
    int n = nums.size();
    
    // Find next greater to left elements and push them into res vector
    for(int i = 0; i < n; ++i) {
        if(s.empty()) {
            res.push_back(-1);
        } else {
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
    vector<int> ngl = nextGreaterToLeft(v);
    for(auto &x : ngl) {
        cout << x << " ";
    }
    return 0;
}
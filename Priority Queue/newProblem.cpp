#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums) {
    int n = nums.size();
    int breakPoint = -1;
    
    for(int i = n - 2; i >= 0; --i) {
        if(nums[i] < nums[i + 1]) {
            breakPoint = i;
            break;
        }
    }

    if(breakPoint == -1) {
        return -1;
    }

    for(int i = n - 1; i > breakPoint; --i) {
        if(nums[i] > nums[breakPoint]) {
            swap(nums[i], nums[breakPoint]);
            break;
        }
    }
    reverse(nums.begin() + breakPoint + 1, nums.end());
    for(auto i : nums) {
        cout << i;
    }
    cout << endl;
    // convert into number
    int result = 0;
    for(int i = 0; i < n; ++i)  {
        result = (result * 10) + nums[i];
    }
    return result;
}
int main() {
    int input = 5;
    vector<int> nums;
    while(input > 0) {
        nums.push_back(input % 10);
        input /= 10;
    }
    reverse(nums.begin(), nums.end());
    int ans = solve(nums);
    if(ans == -1) {
        cout << "NOT POSSIBLE"  << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
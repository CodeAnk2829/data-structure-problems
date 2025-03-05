#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) {
            return true;
        } else if(nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans = {-1, -1};

    bool isFound = binarySearch(nums, target);
    // if the target is not found
    if(isFound == false) return ans;

    // find the lower bound index of the array
    int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    // find the upper bound index of the array
    int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

    if(lb != nums.size() && ub != nums.size()) {
        ans[0] = lb;
        ans[1] = ub - 1;
    }

    return ans;
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
    sort(v.begin(), v.end());
    int key;
    cin >> key;
    vector<int> res = searchRange(v, key);
    cout << res[0] << " " << res[1];
    return 0;
}
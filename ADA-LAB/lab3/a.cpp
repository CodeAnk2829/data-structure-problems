#include <bits/stdc++.h>
using namespace std;
long long findSum(vector<int> &index)
{
    int n = index.size();
    long long sum = 0;

    for (int i = 0, mf = n - 1; i < n / 2; ++i, mf -= 2)
    {
        sum += (mf * (index[n - i - 1] - index[i]));
    }
    return 2*sum;
}
vector<long long> distance(vector<int> &nums)
{
    map<int, vector<int>> m;
    for (int i = 0; i < nums.size(); ++i)
    {
        m[nums[i]].push_back(i);
    }
    for(auto &e : m) {
        cout << e.first << "      ";
        for(auto &c : e.second) {
            cout << c << " ";
        }
        cout << endl;
    }
    vector<long long> ans;
    for (int i = 0; i < nums.size(); ++i)
    {
        ans.push_back(findSum(m[nums[i]]));
    }
    return ans;
}
int main() {
    int n; 
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    vector<long long> ans = distance(v);
    for(auto &c : ans) {
        cout << c << " ";
    }
    return 0;
}
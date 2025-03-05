#include <bits/stdc++.h>
using namespace std;


string solve (int input1, vector<int>& input2) {
    string ans = "";
    
    if(input2[1] > input2[3]) {
        ans += "North";
    } else if(input2[1] < input2[3]) {
        ans += "South";
    }

    if(input2[0] > input2[2]) {
        ans += "-East";
    } else if(input2[0] < input2[2]) {
        ans += "-West";
    }

    if(ans[0] == '-') {
        ans = ans.substr(1);
    }
    
    return ans == "" ? "Origin" : ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &it : arr) cin >> it;

    string ans = solve(n, arr);
    cout << ans << endl;
    return 0;
}
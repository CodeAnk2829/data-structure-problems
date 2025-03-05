#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> meetings = { { 3, 49}, { 23, 44}, { 21, 56}, { 26, 55}, { 23, 52}, { 2, 9}, { 1, 48}, { 3, 31 } };
    sort(meetings.begin(), meetings.end());
    for(auto i : meetings) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
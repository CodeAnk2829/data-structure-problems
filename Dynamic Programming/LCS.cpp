// Brute force approach using recursion
// Time Complexity = O(2^n)
#include <bits/stdc++.h>
using namespace std;
int LCS(char* s1, char* s2) {
    if(s1[0] == '\0' || s2[0] == '\0') {
        return 0;
    }
    int ans;
    if(s1[0] == s2[0]) {
        ans = 1 + LCS(s1 + 1, s2 + 1);
    } else {
        int b = LCS(s1 + 1, s2);
        int c = LCS(s1, s2 + 1);
        ans = max(b, c);
    }
    return ans;
}
int main() {
    char str1[1001], str2[1001];
    cin.getline(str1, 1001);
    cin.getline(str2, 1001);
    cout << LCS(str1, str2);
    return 0;
}
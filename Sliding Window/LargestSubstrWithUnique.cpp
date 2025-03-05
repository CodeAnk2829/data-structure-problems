// Find the length of the largest substring without repeating characters
// TC = O(2N) --> O(N)(for traversing the string) + O(N) (for inner while loop in worst case)
#include <bits/stdc++.h>
using namespace std;
int largestSubuniqueCharactersWithoutRepeatition(string s) {
    set<char> uniqueCharacters;
    int len = 0;
    int left = 0, right = 0;
    while(right < s.size()) {
        // remove the characters from the left
        // side untill we duplicate character is
        // removed
        while(left <= right && uniqueCharacters.find(s[right]) != uniqueCharacters.end()) {
            uniqueCharacters.erase(s[left]);
            left++;
        }

        // calculate the length of the subarray
        // which is having only unique characters
        len = max(len, right - left + 1);
        uniqueCharacters.insert(s[right]);
        right++;
    }

    return len;
}
int main() {
    string s;
    cin >> s;
    cout << largestSubuniqueCharactersWithoutRepeatition(s);
    return 0;
}
// Find the length of the largest substring without repeating characters 
// Using map
// TC = O(N)
#include <bits/stdc++.h>
using namespace std;

int largestSubstrWithoutRepeatingChar(string s) {
    map<char, int> uniqueCharacters;
    int len = 0;
    int left = 0, right = 0;

    while(right < s.size()) {
        // remove the characters from the left
        // side untill the duplicate character is
        // removed
        if(uniqueCharacters.find(s[right]) != uniqueCharacters.end() && uniqueCharacters[s[right]] >= left && uniqueCharacters[s[right]] <= right) {
            int index = uniqueCharacters[s[right]];
            left = index + 1;
        }

        // calculate the length of the subarray
        // which is having only unique characters
        len = max(len, right - left + 1);

        // Add the new char-index pair into the map
        uniqueCharacters[s[right]] = right;
        right++;
    }

    return len;
}

int main() {
    string s;
    cin >> s;
    cout << largestSubstrWithoutRepeatingChar(s);
    return 0;
}
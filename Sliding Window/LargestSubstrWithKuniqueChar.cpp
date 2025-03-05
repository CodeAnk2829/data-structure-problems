#include <bits/stdc++.h>
using namespace std;

// Find the length of the longest substring
// having exaclty k unique characters in it

int getLongestSubstring(string s, int k) {
    map<char, int> m;
    int len = 0;
    int left = 0, right = 0;

    while(right < s.size()) {
        // check if size is equal to k and the coming 
        // character is yet not a part of the map
        // this means we reached desired condition
        if(m.size() == k && m.find(s[right]) == m.end()) {
            // calculate length
            len = max(len, right - left);

            // remove all count of one of the characters from the map
            // so that there will be a new place for the upcoming char
            while(m[s[left]] != 0) {
                m[s[left]]--;
                left++;
                if(m[s[left - 1]] == 0) {
                    break;
                }
            }

            m.erase(s[left - 1]);
        }

        // insert the character and its frequency 
        m[s[right]]++;
        right++;
    }

    if(m.size() == k) {
        len = max(len, right - left);
    } else {
        // if at last size is not equal to k then 
        // there is no substring which is having exactly
        // k unique characters 
        len = -1;
    }

    return len;
}

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << getLongestSubstring(s, k);
    return 0;
}
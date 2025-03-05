// https://leetcode.com/problems/longest-duplicate-substring/description/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Hash {
private:
    const ll MOD = 1e9 + 7;
    const ll BASE1 = 5689;
    const ll BASE2 = 8861;
    vector<pair<ll, ll>> hashes, basePowers;

public:
    Hash(string s) {
        hashes.assign(s.size() + 1, {0, 0});
        basePowers.assign(s.size() + 1, {1, 1});

        for(ll i = 0; i < s.size(); ++i) {
            ll firstHash =  (hashes[i].first * BASE1 + (s[i] - 'a' + 1)) % MOD;
            ll secondHash = (hashes[i].second * BASE2 + (s[i] - 'a' + 1)) % MOD;
            hashes[i + 1] = {firstHash, secondHash};

            ll firstBasePower = (basePowers[i].first * BASE1) % MOD;
            ll secondBasePower = (basePowers[i].second * BASE2) % MOD;
            basePowers[i + 1] = {firstBasePower, secondBasePower};
        }
    }

    pair<ll, ll> getHash(ll l, ll r) {
        l++, r++;
        ll hash1 = (hashes[r].first - (hashes[l - 1].first * basePowers[r - l + 1].first) % MOD + MOD) % MOD;
        ll hash2 = (hashes[r].second - (hashes[l - 1].second * basePowers[r - l + 1].second) % MOD + MOD) % MOD;
        return {hash1, hash2};
    }
};

class Solution {
public:
    string longestDupSubstring(string s) {
        ll low = 0, high = s.size();
        Hash h(s);

        auto findStartingIndex = [&](ll mid)->ll{
            map<pair<ll, ll>, ll> m; // for storing hash and count
            for(ll i = 0; i + mid - 1 < s.size(); ++i) {
                pair<ll, ll> hashValues = h.getHash(i, i + mid - 1);
                m[hashValues]++;
                if(m[hashValues] > 1) {
                    return i;
                }
            }
            return (ll)-1;
        };

        ll minLength = 0;
        ll index = 0;

        while(low <= high) {
            ll mid = (low + high) / 2;
            ll startingIndex = findStartingIndex(mid);
            if(startingIndex != -1) {
                minLength = mid;
                index = startingIndex;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return s.substr(index, minLength);
    }
};